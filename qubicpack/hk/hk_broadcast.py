#!/usr/bin/env python
'''
$Id: hk_broadcast.py
$auth: Steve Torchinsky <satorchi@apc.in2p3.fr>
$created: Mon 03 Dec 2018 15:23:50 CET
$license: GPLv3 or later, see https://www.gnu.org/licenses/gpl-3.0.txt

          This is free software: you are free to change and
          redistribute it.  There is NO WARRANTY, to the extent
          permitted by law.

class for broadcasting/receiving QUBIC Housekeeping data
'''
from __future__ import division, print_function
import sys,os,subprocess,time,socket
import numpy as np
import datetime as dt

from qubicpack.hk.powersupply import *
from qubicpack.hk.entropy_hk import entropy_hk


class hk_broadcast :

    def __init__(self):
        return None
    

    def define_hk_record(self):
        '''define a housekeeping data record
        '''
    
        # packet identifiers
        STX=0xAA
        ID=2


        # make the data record
        names=[]
        fmts=[]
        record_zero=[]

        # identifiers
        names.append('STX')
        fmts.append('i2')
        record_zero.append(STX)

        names.append('QUBIC_ID')
        fmts.append('i2')
        record_zero.append(ID)

        # the current date (milliseconds since 1970-1-1)
        names.append('DATE')
        fmts.append('i8')
        now=dt.datetime.now()
        msec=now.strftime('%f')[0:3]
        record_zero.append(int('%s%s' % (now.strftime('%s'),msec)))

        # temperatures from the two AVS47 controllers
        for idx in range(2):
            avs='AVS47_%i' % (idx+1)
            for ch in range(8):
                recname='%s_ch%i' % (avs,ch)
                names.append(recname)
                fmts.append('f8')
                record_zero.append(0.0)

        # the Mechanical Heat Switch positions
        for idx in range(2):
            mhs='MHS%i' % (idx+1)
            names.append(mhs)
            fmts.append('i4')
            record_zero.append(0)

        # the power supplies (heaters)
        for idx in range(8):
            heater='HEATER%i' % (idx+1)
            for meastype in ['Volt','Amp']:
                names.append('%s_%s' % (heater,meastype))
                fmts.append('f8')
                record_zero.append(0.0)

        ########### we don't send the labels themselves ###########
        # names=['LABELS']+names
        # names_line=','.join(names)
        # fmts=['a%i' % len(names_line)]+fmts
        # fmts_line=','.join(fmts)
        # record_zero=[names_line]+record_zero

        record=np.recarray(names=names_line,formats=fmts_line,shape=(1))
        for idx,val in enumerate(record_zero):
            record[0][idx]=val
        return record

    def get_all_hk(self):
        '''sample all the housekeeping from the various sensors
        '''

        hk=entropy_hk()
        record=self.define_hk_record()
        now=dt.datetime.now()
        msec=now.strftime('%f')[0:3]
        record[0].DATE=int('%s%s' % (now.strftime('%s'),msec))
        
        
        return

    def hk_client(self):
        client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
        client.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        client.bind(("", 37020))

        nskips=0
        local_counter=0
        prev_counter=-1
        while True:
            data, addr = client.recvfrom(4096)
            now=dt.datetime.now()

    
            print('data type %s of length %i' % (type(data),len(data)))
            self.log('try.log',data)
    
            local_counter+=1
    
        return


    def hk_server(self):
        '''broadcast all housekeeping info
        '''
        
        record=self.define_hk_record()

        cmd='/sbin/ifconfig eth0'
        proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
        out,err=proc.communicate()
        for line in out.split('\n'):
            if line.find('inet ')>0: break
        hostname=line.split()[1]
        print('hostname=%s' % hostname)
        hostname='localhost' # for testing
        print('hostname=%s for testing' % hostname)

        now=dt.datetime.now()
        stoptime=now+dt.timedelta(seconds=30)

        s=socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        s.settimeout(0.2)
        s.bind((hostname,15000))

        counter=0
        while now < stoptime:

            msg=record
            
            s.sendto(msg, ('<broadcast>', 37020))

            time.sleep(1.0)
            now=dt.datetime.now()
            counter+=1

        s.close()
        return


    def log(self,filename,data):
        '''add data to log file
        '''
        h=open(filename,'a')
        h.write(data)
        h.close()
        return




