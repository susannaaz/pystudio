//File generated by Dispatcher wizard v 2.9.1.0.14 (07/02/2018) .
//Generating date : jeu. mai 24 10:24:41 2018

//---------------------------------------------------------------------------
#ifndef TVirtualDecommutationH
#define TVirtualDecommutationH
//---------------------------------------------------------------------------

#include "tparameters.h"
#include "tclientsmanager.h"
#include "tlogbook.h"
#include "tcustomtelemetrydecode.h"
#include "customdispatcher.h"
#include "qdispatcherbytearray.h"
#define EXTRACT_EOT 0xF0000000

/** \@brief Virtual class, define the Subsystems TM decommutation interfaces.
 */
class TVirtualDecommutation
{
public :
/** \@brief Constructor.
 *
 * Initialize the class parameters.
 * \@param [in] Parameters pointer to the TParameters dispatcher instance.
 * \@param [in] ClientsManager pointer to the TClientManager instance.
 */                      
	TVirtualDecommutation(TParameters* Parameters, TClientsManager *ClientsManager, TLogBook *logBook);
/** \@brief Destructor.
 */
	virtual ~TVirtualDecommutation();

/** \@brief Virtual definition of Decommute function.
 *
 * Used to decommute Subsystems telemetries.
 * \@param [in] subsystem subsytem ID to read.
 * \@param [in] tmBuffer telemetry buffer.
 * \@param [in] tmSize size of telemetry buffer.
 */
	void decommute(quint8 subsystem, quint8* tmBuffer,quint32 tmSize);

/** \@brief Virtual definition of decommuteMULTINETQUICMANAGER function.
*
* Used to decommute MULTINETQUICMANAGER telemetries.
* \@param [in] tmBuffer telemetry buffer.
* \@param [in] tmSize size of telemetry buffer.
*/
	virtual void decommuteMULTINETQUICMANAGER(quint8 *tmBuffer, quint32 tmSize)=0;

/** \@brief Virtual definition of decommuteSWITCHES function.
*
* Used to decommute SWITCHES telemetries.
* \@param [in] tmBuffer telemetry buffer.
* \@param [in] tmSize size of telemetry buffer.
*/
	virtual void decommuteSWITCHES(quint8 *tmBuffer, quint32 tmSize)=0;

/** \@brief Virtual definition of decommuteCFIBERS function.
*
* Used to decommute CFIBERS telemetries.
* \@param [in] tmBuffer telemetry buffer.
* \@param [in] tmSize size of telemetry buffer.
*/
	virtual void decommuteCFIBERS(quint8 *tmBuffer, quint32 tmSize)=0;

/** \@brief Virtual definition of decommuteMMR3 function.
*
* Used to decommute MMR3 telemetries.
* \@param [in] tmBuffer telemetry buffer.
* \@param [in] tmSize size of telemetry buffer.
*/
	virtual void decommuteMMR3(quint8 *tmBuffer, quint32 tmSize)=0;

/** \@brief Virtual definition of decommuteMGC3 function.
*
* Used to decommute MGC3 telemetries.
* \@param [in] tmBuffer telemetry buffer.
* \@param [in] tmSize size of telemetry buffer.
*/
	virtual void decommuteMGC3(quint8 *tmBuffer, quint32 tmSize)=0;

/** \@brief Virtual definition of decommuteHWP function.
*
* Used to decommute HWP telemetries.
* \@param [in] tmBuffer telemetry buffer.
* \@param [in] tmSize size of telemetry buffer.
*/
	virtual void decommuteHWP(quint8 *tmBuffer, quint32 tmSize)=0;

/** \@brief Virtual definition of decommuteCALIBSOURCES function.
*
* Used to decommute CALIBSOURCES telemetries.
* \@param [in] tmBuffer telemetry buffer.
* \@param [in] tmSize size of telemetry buffer.
*/
	virtual void decommuteCALIBSOURCES(quint8 *tmBuffer, quint32 tmSize)=0;

/** \@brief Virtual definition of decommutePLATFORMCONTROLER function.
*
* Used to decommute PLATFORMCONTROLER telemetries.
* \@param [in] tmBuffer telemetry buffer.
* \@param [in] tmSize size of telemetry buffer.
*/
	virtual void decommutePLATFORMCONTROLER(quint8 *tmBuffer, quint32 tmSize)=0;

/** \@brief Virtual definition of decommutePLATFORMMOTORS function.
*
* Used to decommute PLATFORMMOTORS telemetries.
* \@param [in] tmBuffer telemetry buffer.
* \@param [in] tmSize size of telemetry buffer.
*/
	virtual void decommutePLATFORMMOTORS(quint8 *tmBuffer, quint32 tmSize)=0;

/** \@brief Virtual definition of decommuteGPS function.
*
* Used to decommute GPS telemetries.
* \@param [in] tmBuffer telemetry buffer.
* \@param [in] tmSize size of telemetry buffer.
*/
	virtual void decommuteGPS(quint8 *tmBuffer, quint32 tmSize)=0;

/** \@brief decode the telemetry according the ID.
 *
 * decode the 8 bits telemetry buffer and update the TParameters instance.
 * \@param [in] tmId telemetry ID to decode.
 * \@param [in] telemetry telemetry buffer.
 */
	void decodeTelemetry(quint32 tmId,quint8* telemetry, quint32 tmSize);

protected :
/** \@brief Virtual definition of isAck function.
 *
 * Check the TM ID and return true if it's an ACK ID.
 * Update the _ackStatus and _ackStatusSize parameters with the status returned by subsystem.
 * \@param [in] subsystem substem.
 * \@param [in] tmID telemetry ID to check.
 * \@return Return true if the parameter is an ACK ID, else return false.
 */
	virtual bool isACK(quint8 subsystem, quint32 tmID, quint8* telemetry)=0;
	virtual bool canDecodeTelemetry(quint8 subsystem, quint32 tmID, quint8* telemetry, quint32 tmSize) = 0;
	virtual void telemetryDecoded(quint8 subsystem, quint32 tmID, quint8* telemetry, quint32 tmSize) = 0;
	void setDecommutationError(quint8 errorCode,quint64 currentId,quint16 decommIndex,quint64 fieldValue, QString errorDescription = "");
	TCustomTelemetryDecode* _telemetryDecoder;
	TParameters* _parameters; /**< TParameter dispatcher instance pointer. */
	QByteArray _ackStatus; /**< ACK Status received from Subsystem. */
	int _ackClientNum; /**< Used to specify the client to use to return the ack. Default, the ack is returned to the last client which sent command*/
	quint8 _currentSubSystemID; /**< current decoding subsystem ID. */
	TLogBook* _logBook; /**< current decoding subsystem ID. */


	TClientsManager *_clientsManager; /**< TClientManager dispatcher instance pointer. */


};
#endif