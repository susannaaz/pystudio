// File generated by Dispatcher Wizard v  2.9.1.0.14 (07/02/2018)
#ifndef _TCOMMANDDECODE_H_
#define _TCOMMANDDECODE_H_


#define 		GPS_CUSTOMGPSCOMMAND_ID 1
#define 		PLATFORMMOTORS_CONFIGUREMOTORS_ID 2
#define 		PLATFORMMOTORS_CONFIGUREELMOTOR_ID 1
#define 		PLATFORMMOTORS_CONFIGUREAZMOTOR_ID 0
#define 		PLATFORMCONTROLER_CUSTOMCONTROLERMC405COMMAND_ID 1
#define 		CALIBSOURCES_CONFIGURELOWFREQUENCYSOURCE_ID 3
#define 		CALIBSOURCES_CONFIGUREHIGHFREQUENCYSOURCE_ID 2
#define 		CALIBSOURCES_CUSTOMCALIBSOURCESCOMMAND_ID 1
#define 		HWP_HWPCOMMAND_ID 1
#define 		MGC3_TOMGC3_ID 0
#define 		MMR3_TOMMR3_ID 0
#define 		CFIBERS_CONFIGURECFIBERS_ID 1
#define 		SWITCHES_SWITCHESMSG_ID 0
#define 		MULTINETQUICMANAGER_SETHEATERRELAY_ID 62
#define 		MULTINETQUICMANAGER_SETFEEDBACKRELAY_ID 61
#define 		MULTINETQUICMANAGER_ACTIVATEPID_ID 22
#define 		MULTINETQUICMANAGER_CONFIGUREPID_ID 21
#define 		MULTINETQUICMANAGER_SETFEEDBACKDAC_ID 19
#define 		MULTINETQUICMANAGER_SETTESDAC_ID 18
#define 		MULTINETQUICMANAGER_SETASICSERIALLINKFREQUENCY_ID 16
#define 		MULTINETQUICMANAGER_GETSTATUS_ID 14
#define 		MULTINETQUICMANAGER_SETASICCONF_ID 13
#define 		MULTINETQUICMANAGER_SETCYCLERAWMODE_ID 11
#define 		MULTINETQUICMANAGER_RESETNETQUIC_ID 10
#define 		MULTINETQUICMANAGER_SETACQMODE_ID 9
#define 		MULTINETQUICMANAGER_STOPACQ_ID 7
#define 		MULTINETQUICMANAGER_STARTACQ_ID 6
#define 		MULTINETQUICMANAGER_SETNSAMPLE_ID 5
#define 		MULTINETQUICMANAGER_SETMASK_ID 3
#define 		MULTINETQUICMANAGER_SETOFFSETTABLE_ID 20
#define 		MULTINETQUICMANAGER_SETFEEDBACKTABLE_ID 1
#define 		MULTINETQUICMANAGER_SETASICINIB_ID 60
#define 		MULTINETQUICMANAGER_SETASICRAZB_ID 59
#define 		MULTINETQUICMANAGER_SETASICSELLASTROW_ID 57
#define 		MULTINETQUICMANAGER_SETASICSELSTARTROW_ID 56
#define 		MULTINETQUICMANAGER_SETASICSETCOLUMN_ID 55
#define 		MULTINETQUICMANAGER_SETASICVOCM_ID 54
#define 		MULTINETQUICMANAGER_SETASICVICM_ID 53
#define 		MULTINETQUICMANAGER_SETASICSPOL_ID 52
#define 		MULTINETQUICMANAGER_SETASICAPOL_ID 51
#define 		MULTINETQUICMANAGER_SETASICPARAM_ID 50
#define 		MULTINETQUICMANAGER_CUSTOMCOMMAND_ID 40
#define 		DISP_RESETALLPARAMETERS_ID 14
#define 		DISP_SETLOGBOOKBASEDIRECTORY_ID 13
#define 		DISP_SETLOGBOOKFILENAME_ID 12
#define 		DISP_ADDTOLOGBOOK_ID 11
#define 		DISP_RESETDECOMMUTATIONFLAGS_ID 10
#define 		DISP_RESETSUBSYSTEM_ID 9
#define 		DISP_SETBACKUPDIR_ID 8
#define 		DISP_RELOADTF_ID 7
#define 		DISP_STOPBACKUP_ID 5
#define 		DISP_STARTBACKUP_ID 4
#define 		DISP_SETSCIENTIFICDATATFUSED_ID 7
#define 		DISP_SETVOUT2IINSCOEFFS_ID 6
#define 		DISP_SETVOUT2IINCOEFFS_ID 5
#define 		DISP_RESETVOUT2IINCOEFFS_ID 4
#define 		DISP_SETVOFFSETS_ID 3
#define 		DISP_SETVOFFSET_ID 2
#define 		DISP_RESETVOFFSET_ID 1

#include "definitions.h"
#include <QString>
#include <QByteArray>

class TCommandDecode
{
public :
TCommandDecode();
~TCommandDecode();

/** \@brief Decode the ResetVOffset command's fields.
 * 
 * Extract all custom fields of the ResetVOffset command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 */
void decodeResetVOffset(quint8* pbTC , /*@out@*/quint32 *asicNum);

/** \@brief Decode the SetVOffset command's fields.
 * 
 * Extract all custom fields of the SetVOffset command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] pixelNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] voffset TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetVOffset(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *pixelNum , /*@out@*/float *voffset);

/** \@brief Decode the SetVOffsets command's fields.
 * 
 * Extract all custom fields of the SetVOffsets command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] voffset TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetVOffsets(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/float *voffset);

/** \@brief Decode the ResetVout2IinCoeffs command's fields.
 * 
 * Extract all custom fields of the ResetVout2IinCoeffs command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 */
void decodeResetVout2IinCoeffs(quint8* pbTC , /*@out@*/quint32 *asicNum);

/** \@brief Decode the SetVout2IinCoeffs command's fields.
 * 
 * Extract all custom fields of the SetVout2IinCoeffs command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] MinMfb TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] Rfb TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetVout2IinCoeffs(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/float *MinMfb , /*@out@*/float *Rfb);

/** \@brief Decode the SetVout2IinsCoeffs command's fields.
 * 
 * Extract all custom fields of the SetVout2IinsCoeffs command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] MinMfb TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] Rfb TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetVout2IinsCoeffs(quint8* pbTC , /*@out@*/float *MinMfb , /*@out@*/float *Rfb);

/** \@brief Decode the SetScientificDataTfUsed command's fields.
 * 
 * Extract all custom fields of the SetScientificDataTfUsed command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] tfused TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetScientificDataTfUsed(quint8* pbTC , /*@out@*/quint8 *tfused);

/** \@brief Decode the StartBackup command's fields.
 * 
 * Extract all custom fields of the StartBackup command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] backupsId TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] sessionName TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] comment TBWTBWTBWTBWTBWTBWTBW
 */
void decodeStartBackup(quint8* pbTC , /*@out@*/quint16 *backupsId , /*@out@*/QString *sessionName , /*@out@*/QString *comment);

/** \@brief Decode the StopBackup command's fields.
 * 
 * Extract all custom fields of the StopBackup command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] backupsId TBWTBWTBWTBWTBWTBWTBW
 */
void decodeStopBackup(quint8* pbTC , /*@out@*/quint16 *backupsId);

/** \@brief Decode the SetBackupDir command's fields.
 * 
 * Extract all custom fields of the SetBackupDir command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] directory TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetBackupDir(quint8* pbTC , /*@out@*/QString *directory);

/** \@brief Decode the ResetSubsystem command's fields.
 * 
 * Extract all custom fields of the ResetSubsystem command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] subsystemId TBWTBWTBWTBWTBWTBWTBW
 */
void decodeResetSubsystem(quint8* pbTC , /*@out@*/quint8 *subsystemId);

/** \@brief Decode the ResetDecommutationFlags command's fields.
 * 
 * Extract all custom fields of the ResetDecommutationFlags command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] subsytemId TBWTBWTBWTBWTBWTBWTBW
 */
void decodeResetDecommutationFlags(quint8* pbTC , /*@out@*/quint8 *subsytemId);

/** \@brief Decode the AddToLogbook command's fields.
 * 
 * Extract all custom fields of the AddToLogbook command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] key TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] comment TBWTBWTBWTBWTBWTBWTBW
 */
void decodeAddToLogbook(quint8* pbTC , /*@out@*/QString *key , /*@out@*/QString *comment);

/** \@brief Decode the SetLogBookFilename command's fields.
 * 
 * Extract all custom fields of the SetLogBookFilename command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] filename TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetLogBookFilename(quint8* pbTC , /*@out@*/QString *filename);

/** \@brief Decode the SetLogBookBaseDirectory command's fields.
 * 
 * Extract all custom fields of the SetLogBookBaseDirectory command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] directory TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetLogBookBaseDirectory(quint8* pbTC , /*@out@*/QString *directory);

/** \@brief Decode the SetAsicParam command's fields.
 * 
 * Extract all custom fields of the SetAsicParam command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] address TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] value TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetAsicParam(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *address , /*@out@*/quint8 *value);

/** \@brief Decode the SetAsicApol command's fields.
 * 
 * Extract all custom fields of the SetAsicApol command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] value TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetAsicApol(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *value);

/** \@brief Decode the SetAsicSpol command's fields.
 * 
 * Extract all custom fields of the SetAsicSpol command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] value TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetAsicSpol(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *value);

/** \@brief Decode the SetAsicVicm command's fields.
 * 
 * Extract all custom fields of the SetAsicVicm command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] value TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetAsicVicm(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *value);

/** \@brief Decode the SetAsicVocm command's fields.
 * 
 * Extract all custom fields of the SetAsicVocm command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] value TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetAsicVocm(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *value);

/** \@brief Decode the SetAsicSetColumn command's fields.
 * 
 * Extract all custom fields of the SetAsicSetColumn command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] startStopCol TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetAsicSetColumn(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *startStopCol);

/** \@brief Decode the SetAsicSelStartRow command's fields.
 * 
 * Extract all custom fields of the SetAsicSelStartRow command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] value TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetAsicSelStartRow(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *value);

/** \@brief Decode the SetAsicSelLastRow command's fields.
 * 
 * Extract all custom fields of the SetAsicSelLastRow command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] value TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetAsicSelLastRow(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *value);

/** \@brief Decode the SetAsicRazb command's fields.
 * 
 * Extract all custom fields of the SetAsicRazb command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetAsicRazb(quint8* pbTC , /*@out@*/quint32 *asicNum);

/** \@brief Decode the SetAsicInib command's fields.
 * 
 * Extract all custom fields of the SetAsicInib command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetAsicInib(quint8* pbTC , /*@out@*/quint32 *asicNum);

/** \@brief Decode the SetFeedbackTable command's fields.
 * 
 * Extract all custom fields of the SetFeedbackTable command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] feedbackTable TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetFeedbackTable(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint16 *feedbackTable);

/** \@brief Decode the SetOffsetTable command's fields.
 * 
 * Extract all custom fields of the SetOffsetTable command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] offsetTable TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetOffsetTable(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint16 *offsetTable);

/** \@brief Decode the SetMask command's fields.
 * 
 * Extract all custom fields of the SetMask command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] mask TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetMask(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *mask);

/** \@brief Decode the SetNSample command's fields.
 * 
 * Extract all custom fields of the SetNSample command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] Nsample TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetNSample(quint8* pbTC , /*@out@*/quint16 *Nsample);

/** \@brief Decode the StartAcq command's fields.
 * 
 * Extract all custom fields of the StartAcq command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 */
void decodeStartAcq(quint8* pbTC , /*@out@*/quint32 *asicNum);

/** \@brief Decode the StopAcq command's fields.
 * 
 * Extract all custom fields of the StopAcq command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 */
void decodeStopAcq(quint8* pbTC , /*@out@*/quint32 *asicNum);

/** \@brief Decode the SetAcqMode command's fields.
 * 
 * Extract all custom fields of the SetAcqMode command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] testMode TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetAcqMode(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint16 *testMode);

/** \@brief Decode the ResetNetquic command's fields.
 * 
 * Extract all custom fields of the ResetNetquic command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 */
void decodeResetNetquic(quint8* pbTC , /*@out@*/quint32 *asicNum);

/** \@brief Decode the SetCycleRawMode command's fields.
 * 
 * Extract all custom fields of the SetCycleRawMode command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] undersampling TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetCycleRawMode(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint16 *undersampling);

/** \@brief Decode the SetAsicConf command's fields.
 * 
 * Extract all custom fields of the SetAsicConf command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] signalId TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] state TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetAsicConf(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *signalId , /*@out@*/quint8 *state);

/** \@brief Decode the GetStatus command's fields.
 * 
 * Extract all custom fields of the GetStatus command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 */
void decodeGetStatus(quint8* pbTC , /*@out@*/quint32 *asicNum);

/** \@brief Decode the SetASICSerialLinkFrequency command's fields.
 * 
 * Extract all custom fields of the SetASICSerialLinkFrequency command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] serialFreq TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetASICSerialLinkFrequency(quint8* pbTC , /*@out@*/quint8 *serialFreq);

/** \@brief Decode the SetTESDAC command's fields.
 * 
 * Extract all custom fields of the SetTESDAC command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] shape TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] frequency TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] amplitude TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] offsetADU TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetTESDAC(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *shape , /*@out@*/quint8 *frequency , /*@out@*/quint16 *amplitude , /*@out@*/quint16 *offsetADU);

/** \@brief Decode the SetFeedbackDAC command's fields.
 * 
 * Extract all custom fields of the SetFeedbackDAC command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] shape TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] frequency TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] amplitude TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] offsetADU TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetFeedbackDAC(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *shape , /*@out@*/quint8 *frequency , /*@out@*/quint16 *amplitude , /*@out@*/quint16 *offsetADU);

/** \@brief Decode the ConfigurePID command's fields.
 * 
 * Extract all custom fields of the ConfigurePID command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] P TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] I TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] D TBWTBWTBWTBWTBWTBWTBW
 */
void decodeConfigurePID(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint16 *P , /*@out@*/quint16 *I , /*@out@*/quint16 *D);

/** \@brief Decode the ActivatePID command's fields.
 * 
 * Extract all custom fields of the ActivatePID command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] onOff TBWTBWTBWTBWTBWTBWTBW
 */
void decodeActivatePID(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint16 *onOff);

/** \@brief Decode the SetFeedbackRelay command's fields.
 * 
 * Extract all custom fields of the SetFeedbackRelay command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] bitmask TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetFeedbackRelay(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *bitmask);

/** \@brief Decode the SetHeaterRelay command's fields.
 * 
 * Extract all custom fields of the SetHeaterRelay command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] asicNum TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] bitmask TBWTBWTBWTBWTBWTBWTBW
 */
void decodeSetHeaterRelay(quint8* pbTC , /*@out@*/quint32 *asicNum , /*@out@*/quint8 *bitmask);

/** \@brief Decode the ConfigureCFibers command's fields.
 * 
 * Extract all custom fields of the ConfigureCFibers command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] periode TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] broche3State TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] broche4State TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] broche5State TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] ampFiber1 TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] offsetFiber1 TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] durationFiber1 TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] ampFiber2 TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] offsetFiber2 TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] durationFiber2 TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] ampFiber3 TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] offsetFiber3 TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] durationFiber3 TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] ampFiber4 TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] offsetFiber4 TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] durationFiber4 TBWTBWTBWTBWTBWTBWTBW
 */
void decodeConfigureCFibers(quint8* pbTC , /*@out@*/quint16 *periode , /*@out@*/quint8 *broche3State , /*@out@*/quint8 *broche4State , /*@out@*/quint8 *broche5State , /*@out@*/quint16 *ampFiber1 , /*@out@*/quint16 *offsetFiber1 , /*@out@*/quint16 *durationFiber1 , /*@out@*/quint16 *ampFiber2 , /*@out@*/quint16 *offsetFiber2 , /*@out@*/quint16 *durationFiber2 , /*@out@*/quint16 *ampFiber3 , /*@out@*/quint16 *offsetFiber3 , /*@out@*/quint16 *durationFiber3 , /*@out@*/quint16 *ampFiber4 , /*@out@*/quint16 *offsetFiber4 , /*@out@*/quint16 *durationFiber4);

/** \@brief Decode the ConfigureHighFrequencySource command's fields.
 * 
 * Extract all custom fields of the ConfigureHighFrequencySource command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] frequency TBWTBWTBWTBWTBWTBWTBW
 */
void decodeConfigureHighFrequencySource(quint8* pbTC , /*@out@*/double *frequency);

/** \@brief Decode the ConfigureLowFrequencySource command's fields.
 * 
 * Extract all custom fields of the ConfigureLowFrequencySource command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] frequency TBWTBWTBWTBWTBWTBWTBW
 */
void decodeConfigureLowFrequencySource(quint8* pbTC , /*@out@*/double *frequency);

/** \@brief Decode the ConfigureMotors command's fields.
 * 
 * Extract all custom fields of the ConfigureMotors command.
 * \@param [in] pbTC Command buffer.
 * \@param [out] azMsg TBWTBWTBWTBWTBWTBWTBW
 * \@param [out] elMsg TBWTBWTBWTBWTBWTBWTBW
 */
void decodeConfigureMotors(quint8* pbTC , /*@out@*/QString *azMsg , /*@out@*/QString *elMsg);

};

#endif
