#!/usr/bin/env python
'''
$Id: timeline.py
$auth: Steve Torchinsky <satorchi@apc.in2p3.fr>
$created: Tue 17 Oct 2017 19:04:04 CEST
$license: GPLv3 or later, see https://www.gnu.org/licenses/gpl-3.0.txt

          This is free software: you are free to change and
          redistribute it.  There is NO WARRANTY, to the extent
          permitted by law.

utilities for QUBIC TES timeline data
'''
from __future__ import division, print_function
import numpy as np
import sys,os,time
import datetime as dt
import matplotlib.pyplot as plt

def exist_timeline_data(self):
    '''
    check if we have timeline data
    '''
    if not isinstance(self.timelines,list):
        return False
    if len(self.timelines)==0:
        return False
    if not isinstance(self.timelines[0],np.ndarray):
        return False
    return True

def amplitude2DAC(self,amplitude):
    '''
    convert bias voltage amplitude in Volts to DAC to send to QubicStudio
    '''
    if amplitude > 0 and amplitude <= 9:
        DACamplitude = amplitude / 0.001125 - 1 # "-1" is back Mon 30 Oct 2017 19:51:42 CET
        #DACamplitude = amplitude / 0.001125  # "-1" removed Tue 17 Oct 2017 14:09:47 CEST
    else:
        DACamplitude = 65536 + amplitude / 0.001125
    DACamplitude = int(np.round(DACamplitude))
    return DACamplitude

def bias_offset2DAC(self,bias):
    '''
    convert bias offset voltage in Volts to DAC to send to QubicStudio
    '''

    # conversion constant DAC <- Volts
    # A = 2.8156e-4
    A = 284.5e-6
    if bias > 0 and bias <= 9:
        DACoffset = bias / A - 1 # "-1" is back Mon 30 Oct 2017 19:51:57 CET
        #DACoffset = bias / A # "-1" removed Tue 17 Oct 2017 15:47:03 CEST
    else:
        DACoffset = 65536 + bias / A
    DACoffset = int(np.round(DACoffset))
    self.debugmsg("DACoffset=%i" % DACoffset)
    return DACoffset

def sample_period(self):
    '''
    the integration time per sample.  This is in seconds.
    '''
    if self.nsamples==None:return None
    period = 1.0 / (2e6 / self.NPIXELS / self.nsamples)
    return period

def timeline_npts(self):
    '''
    the size of the timeline determined from requested parameters.
    This is the number of points in the timeline vector
    '''
    sample_period=self.sample_period()
    if sample_period==None:return None
    timeline_size = int(np.ceil(self.tinteg / sample_period))
    return timeline_size

def determine_bias_modulation(self,TES,timeline_index=None):
    '''
    determine the modulation of the bias voltage
    It should be close to the "bias_frequency" which is actually the period.
    '''
    if not self.exist_timeline_data():return None
    if not isinstance(timeline_index,int):timeline_index=0
    ntimelines=len(self.timelines)
    if timeline_index>=ntimelines:
        print('Please enter a timeline between 0 and %i' % (ntimelines-1))
        return None
    
    TES_index=self.TES_index(TES)
    timeline=self.timelines[timeline_index][TES_index,:]
    timeline_npts=len(timeline)

    sample_period=self.sample_period()
    time_axis=sample_period*np.arange(timeline_npts)

    # the so-called frequency of the bias modulation is, in fact, the period
    bias_period_npts=int(self.bias_frequency/sample_period)

    # skip the first few seconds which are often noisy
    skip=int(3.0/sample_period)
    self.debugmsg('looking for peaks in I-V timeline.  Skipping the first %i points.' % skip)
    peak0_range=(skip,bias_period_npts)
    peak1_range_end=skip+2*bias_period_npts
    if peak1_range_end>=timeline_npts:
        peak1_range_end=timeline_npts-1
    peak1_range=(skip+bias_period_npts,peak1_range_end)

    ipeak0=np.argmax(timeline[peak0_range[0]:peak0_range[1]])
    ipeak0+=peak0_range[0]
    peak0=time_axis[ipeak0]
    ipeak1=np.argmax(timeline[peak1_range[0]:peak1_range[1]])
    ipeak1+=peak1_range[0]
    peak1=time_axis[ipeak1]
    return (ipeak0,ipeak1)

def plot_timeline(self,TES,timeline_index=None,xwin=True):
    '''
    plot the timeline
    '''
    if not self.exist_timeline_data():
        print('ERROR! No timeline data.')
        return None

    if not isinstance(timeline_index,int):
        # by default, plot the first one.  this could change
        timeline_index=0

    ntimelines=len(self.timelines)
    if timeline_index>=ntimelines:
        print('Please enter a timeline between 0 and %i' % (ntimelines-1))
        return None

    if isinstance(self.obsdates,list) and len(self.obsdates)==ntimelines:
        timeline_date=self.obsdates[timeline_index]
    else:
        timeline_date=self.obsdate
    
    ttl=str('QUBIC Timeline curve for TES#%3i (%s)' % (TES,timeline_date.strftime('%Y-%b-%d %H:%M UTC')))

    if isinstance(self.temperatures,list) and len(self.temperatures)==ntimelines:
        tempstr=str('%.0f mK' % (1000*self.temperatures[timeline_index]))
    else:
        if self.temperature==None:
            tempstr='unknown'
        else:
            tempstr=str('%.0f mK' % (1000*self.temperature))
    subttl=str('Array %s, ASIC #%i, Pixel #%i, Temperature %s' % (self.detector_name,self.asic,self.tes2pix(TES),tempstr))
    
    if xwin: plt.ion()
    else: plt.ioff()

    fig=plt.figure(figsize=self.figsize)
    fig.canvas.set_window_title('plt: '+ttl) 
    ax=plt.gca()
    ax.set_xlabel('time  /  seconds')
    ax.set_ylabel('Current  /  $\mu$A')
    
    TES_index=self.TES_index(TES)
    timeline=self.timelines[timeline_index][TES_index,:]
    current=self.ADU2I(timeline)
    timeline_npts=len(timeline)

    sample_period=self.sample_period()
    time_axis=sample_period*np.arange(timeline_npts)

    if self.timeline_conversion==None:
        self.timeline2adu(TES=TES,timeline_index=timeline_index)

    ipeak0=self.timeline_conversion['ipeak0']
    ipeak1=self.timeline_conversion['ipeak1']
    peak0=time_axis[ipeak0]
    peak1=time_axis[ipeak1]
    bias_period=peak1-peak0
    sinelabel='sine curve period=%.2f seconds' % bias_period
    subttl+='\npeaks determined from TES %i' % self.timeline_conversion['TES']
    amplitude=0.5*(self.max_bias-self.min_bias)
    offset=self.min_bias+amplitude
    ysine=offset+amplitude*np.sin((time_axis-peak0)*2*np.pi/self.bias_frequency + 0.5*np.pi)

    fig.suptitle(ttl+'\n'+subttl,fontsize=16)
    
    ax.plot(time_axis,current,label='I-V timeline',color='blue')

    ymax=max([current[ipeak0],current[ipeak1]])
    ymin=min(current)
    yrange=ymax-ymin
    yminmax=(ymin-0.02*yrange,ymax+0.02*yrange)
    ax.plot([peak0,peak0],yminmax,color='red')
    ax.plot([peak1,peak1],yminmax,color='red')
    ax.set_ylim(yminmax)

    ax_bias = ax.twinx()
    ax_bias.set_ylabel('Bias / V',rotation=270)
    ax_bias.plot(time_axis,ysine,label=sinelabel,color='green')

    plt.legend()

    pngname=str('TES%03i_array-%s_ASIC%i_timeline_%s.png' % (TES,self.detector_name,self.asic,self.obsdate.strftime('%Y%m%dT%H%M%SUTC')))
    pngname_fullpath=self.output_filename(pngname)
    if isinstance(pngname_fullpath,str): plt.savefig(pngname_fullpath,format='png',dpi=100,bbox_inches='tight')

    return


def plot_timeline_physical_layout(self,timeline_index=0,xwin=True):
    '''
    plot the timeline curves in thumbnails mapped to the physical location of each detector
    '''
    if not self.exist_timeline_data():return None
    ntimelines=len(self.timelines)

    if not isinstance(timeline_index,int):
        # by default, plot the first one.
        timeline_index=0
    
    if timeline_index>=ntimelines:
        print('Please enter a timeline between 0 and %i' % (ntimelines-1))
        return None
    
    if isinstance(self.obsdates,list) and len(self.obsdates)==ntimelines:
        timeline_date=self.obsdates[timeline_index]
    else:
        timeline_date=self.obsdate

    ttl=str('QUBIC Timeline curves (%s)' % (timeline_date.strftime('%Y-%b-%d %H:%M UTC')))

    if isinstance(self.temperatures,list) and len(self.temperatures)==ntimelines:
        tempstr=str('%.0f mK' % (1000*self.temperatures[timeline_index]))
    else:
        if self.temperature==None:
            tempstr='unknown'
        else:
            tempstr=str('%.0f mK' % (1000*self.temperature))
    subttl=str('Array %s, ASIC #%i, T$_\mathrm{bath}$=%s' % (self.detector_name,self.asic,tempstr))

    nrows=self.pix_grid.shape[0]
    ncols=self.pix_grid.shape[1]

    if xwin: plt.ion()
    else: plt.ioff()
    fig,ax=plt.subplots(nrows,ncols,figsize=self.figsize)
    pngname=str('QUBIC_TES_array-%s_ASIC%i_timeline_%s.png' % (self.detector_name,self.asic,timeline_date.strftime('%Y%m%dT%H%M%SUTC')))
    pngname_fullpath=self.output_filename(pngname)
    if xwin: fig.canvas.set_window_title('plt:  '+ttl)
    fig.suptitle(ttl+'\n'+subttl,fontsize=16)
    

    # the pixel number is between 1 and 248
    TES_translation_table=self.TES2PIX[self.asic_index()]

    for row in range(nrows):
        for col in range(ncols):
            ax[row,col].get_xaxis().set_visible(False)
            ax[row,col].get_yaxis().set_visible(False)

            # the pixel identity associated with its physical location in the array
            physpix=self.pix_grid[row,col]
            pix_index=physpix-1
            self.debugmsg('processing PIX %i' % physpix)

            text_y=0.0
            text_x=1.0
            if physpix==0:
                pix_label='EMPTY'
                label_colour='black'
                face_colour='black'
            elif physpix in TES_translation_table:
                TES=self.pix2tes(physpix)
                pix_label=str('%i' % TES)
                label_colour='black'
                face_colour='white'
                TES_index=self.TES_index(TES)
                timeline=self.timelines[timeline_index][TES_index,:]
                I=self.ADU2I(timeline)
                text_y=min(I)
                text_x=len(timeline)
                self.debugmsg('plotting TES %i' % TES)
                plt.sca(ax[row,col])
                plt.plot(I,color='blue')

            else:
                pix_label='other\nASIC'
                label_colour='yellow'
                face_colour='blue'

            ax[row,col].set_facecolor(face_colour)
            ax[row,col].text(text_x,text_y,pix_label,va='bottom',ha='right',color=label_colour,fontsize=8)
            
    if isinstance(pngname_fullpath,str): plt.savefig(pngname_fullpath,format='png',dpi=100,bbox_inches='tight')
    if xwin: plt.show()
    else: plt.close('all')

    return


def timeline2adu(self,TES=None,ipeak0=None,ipeak1=None,timeline_index=0):
    '''
    transfer timeline data with I-V curves to the ADU matrix 
    this is done so that we can directly use all the I-V methods
    '''
    if not self.exist_timeline_data():return None
    ntimelines=len(self.timelines)
    if timeline_index>=ntimelines:
        print('Please enter a timeline between 0 and %i' % (ntimelines-1))
        return None

    if not isinstance(TES,int):
        print('Please enter a TES which is the reference for extracting the bias timeline')
        return None
    
    ip0,ip1=self.determine_bias_modulation(TES,timeline_index)
    if not isinstance(ipeak0,int):ipeak0=ip0
    if not isinstance(ipeak1,int):ipeak1=ip1
    self.debugmsg('timeline2adu: ipeak0=%i' % ipeak0)
    self.debugmsg('timeline2adu: ipeak1=%i' % ipeak1)
    self.timeline_conversion={}
    self.timeline_conversion['ipeak0']=ipeak0
    self.timeline_conversion['ipeak1']=ipeak1
    self.timeline_conversion['TES']=TES
    self.timeline_conversion['timeline_index']=timeline_index
        
    timeline_npts=self.timeline_npts()
    sample_period=self.sample_period()
    if sample_period==None:
        print('ERROR! Could not determine sample period.  Missing nsamples?')
        return None
    time_axis=sample_period*np.arange(timeline_npts)
    peak0=time_axis[ipeak0]
    peak1=time_axis[ipeak1]

    # find the number of cycles from the bias modulation "frequency" which is the period
    ncycles=int( np.round((peak1-peak0)/self.bias_frequency) )
    if ncycles==0:
        # it's not down/up
        self.nbiascycles=1
        self.cycle_vbias=False
    else:
        self.nbiascycles=ncycles
        self.cycle_vbias=True    
    
    amplitude=0.5*(self.max_bias-self.min_bias)
    offset=self.min_bias+amplitude
    ysine=offset+amplitude*np.sin((time_axis-peak0)*2*np.pi/self.bias_frequency + 0.5*np.pi)
    self.vbias=ysine[ipeak0:ipeak1]
    self.min_bias=min(self.vbias)
    self.max_bias=max(self.vbias)

    npts=len(self.vbias)
    self.adu=np.empty((self.NPIXELS,npts))
    for idx in range(self.NPIXELS):
        self.adu[idx,:]=self.timelines[timeline_index][idx,ipeak0:ipeak1]

    return True
