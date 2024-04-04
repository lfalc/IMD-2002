#ifndef IMD2002_API_IF_H
#define IMD2002_API_IF_H

#include "IMD2002_radarAPI_basicTypes.h"
#include "IMD2002_radarAPI_enums.h"
#include "IMD2002_radarAPI_structs.h"
//#include "InnoSenT_Structs_Embedded.h"

/**************************************************************************************
 defines
**************************************************************************************/
#if defined(_WIN32) && !defined(IMD2002_API_AS_SOURCE)
    #ifdef IMD2002_RADARAPI_LIBRARY
        #define IMD2002_API_EXPORT __declspec(dllexport)
    #else
        #define IMD2002_API_EXPORT __declspec(dllimport)
    #endif
#else
    #define IMD2002_API_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************
 api functions
**************************************************************************************/
#ifndef __linux__
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_initComPort(IMD2002Handle_t *pHandle, uint8_t comportNr, IMD2002_Baudrate_t baudrate);
#else
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_initComPort(IMD2002Handle_t *pHandle, char *comport, int length, IMD2002_Baudrate_t baudrate);
#endif

IMD2002_API_EXPORT IMD2002_Result_t IMD2002_initSystem(IMD2002Handle_t pHandle, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_exitComPort(IMD2002Handle_t pHandle);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_exitSystem(IMD2002Handle_t pHandle, uint8_t destAddress);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getApiVersion(float32_t *version);

/*SD2 - D1 */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_StartAcquisition(IMD2002Handle_t pHandle, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_StopAcquisition(IMD2002Handle_t pHandle, uint8_t destAddress, uint32_t timeout);

/*SD2 - D2 */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getSerialNumber(IMD2002Handle_t pHandle,uint32_t *serialNumber, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getFirmwareVersion(IMD2002Handle_t pHandle, uint16_t *major, uint16_t *fix, uint16_t *minor, uint8_t destAddress, uint32_t timeout);

/*SD2 - D3 */

/*SD2 - D4 */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getDetectionThresholdBeta(IMD2002Handle_t pHandle,float32_t *detectionThreshold, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getFalseAlarmSuppression(IMD2002Handle_t pHandle,uint16_t *falseAlarmSuppression, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getFrequencyChannel(IMD2002Handle_t pHandle, uint16_t *pFrequencyChannel, uint8_t destAddress, uint32_t timeout);
/* target filter #1 */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf1VelocityLowerBound(IMD2002Handle_t pHandle,float32_t *velocity, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf1VelocityUpperBound(IMD2002Handle_t pHandle,float32_t *velocity, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf1RangeLowerBound(IMD2002Handle_t pHandle,float32_t *range, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf1RangeUpperBound(IMD2002Handle_t pHandle,float32_t *range, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf1SignalMagnitudeLowerBound(IMD2002Handle_t pHandle,float32_t *signalMagnitude, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf1SignalMagnitudeUpperBound(IMD2002Handle_t pHandle,float32_t *signalMagnitude, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf1AzimuthAngleLowerBound(IMD2002Handle_t pHandle,float32_t *azimuthAngle, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf1AzimuthAngleUpperBound(IMD2002Handle_t pHandle,float32_t *azimuthAngle, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf1FilterDirection(IMD2002Handle_t pHandle, uint16_t *pFilterDiretion, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf1EnableFilter(IMD2002Handle_t pHandle, uint16_t *pEnable, uint8_t destAddress, uint32_t timeout);
/* target filter #2 */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf2VelocityLowerBound(IMD2002Handle_t pHandle,float32_t *velocity, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf2VelocityUpperBound(IMD2002Handle_t pHandle,float32_t *velocity, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf2RangeLowerBound(IMD2002Handle_t pHandle,float32_t *range, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf2RangeUpperBound(IMD2002Handle_t pHandle,float32_t *range, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf2SignalMagnitudeLowerBound(IMD2002Handle_t pHandle,float32_t *signalMagnitude, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf2SignalMagnitudeUpperBound(IMD2002Handle_t pHandle,float32_t *signalMagnitude, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf2AzimuthAngleLowerBound(IMD2002Handle_t pHandle,float32_t *azimuthAngle, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf2AzimuthAngleUpperBound(IMD2002Handle_t pHandle,float32_t *azimuthAngle, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf2FilterDirection(IMD2002Handle_t pHandle, uint16_t *pFilterDiretion, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTf2EnableFilter(IMD2002Handle_t pHandle, uint16_t *pEnable, uint8_t destAddress, uint32_t timeout);
/* blockage detection */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getBlockageThreshold(IMD2002Handle_t pHandle, uint8_t *pThldPercentage, uint8_t destAddress, uint32_t timeout);

/*SD2 - D5 */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setDetectionThresholdBeta(IMD2002Handle_t pHandle, float32_t detectionThreshold, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setFalseAlarmSuppression(IMD2002Handle_t pHandle, uint16_t falseAlarmSuppression, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setFrequencyChannel(IMD2002Handle_t pHandle, uint16_t frequencyChannel, uint8_t destAddress, uint32_t timeout);
/* target filter #1 */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf1VelocityLowerBound(IMD2002Handle_t pHandle, float32_t velocity, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf1VelocityUpperBound(IMD2002Handle_t pHandle, float32_t velocity, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf1RangeLowerBound(IMD2002Handle_t pHandle, float32_t range, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf1RangeUpperBound(IMD2002Handle_t pHandle, float32_t range, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf1SignalMagnitudeLowerBound(IMD2002Handle_t pHandle, float32_t signalMagnitude, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf1SignalMagnitudeUpperBound(IMD2002Handle_t pHandle, float32_t signalMagnitude, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf1AzimuthAngleLowerBound(IMD2002Handle_t pHandle,float32_t azimuthAngle, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf1AzimuthAngleUpperBound(IMD2002Handle_t pHandle,float32_t azimuthAngle, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf1FilterDirection(IMD2002Handle_t pHandle, uint16_t filterDiretion, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf1EnableFilter(IMD2002Handle_t pHandle, uint16_t enable, uint8_t destAddress, uint32_t timeout);
/* target filter #2 */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf2VelocityLowerBound(IMD2002Handle_t pHandle, float32_t velocity, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf2VelocityUpperBound(IMD2002Handle_t pHandle, float32_t velocity, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf2RangeLowerBound(IMD2002Handle_t pHandle, float32_t range, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf2RangeUpperBound(IMD2002Handle_t pHandle, float32_t range, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf2SignalMagnitudeLowerBound(IMD2002Handle_t pHandle, float32_t signalMagnitude, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf2SignalMagnitudeUpperBound(IMD2002Handle_t pHandle, float32_t signalMagnitude, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf2AzimuthAngleLowerBound(IMD2002Handle_t pHandle,float32_t azimuthAngle, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf2AzimuthAngleUpperBound(IMD2002Handle_t pHandle,float32_t azimuthAngle, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf2FilterDirection(IMD2002Handle_t pHandle, uint16_t filterDiretion, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setTf2EnableFilter(IMD2002Handle_t pHandle, uint16_t enable, uint8_t destAddress, uint32_t timeout);
/* blockage detection */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setBlockageMinLevel(IMD2002Handle_t pHandle, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setBlockageThreshold(IMD2002Handle_t pHandle, uint8_t thldPercentage, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setDefaultBlockageParams(IMD2002Handle_t pHandle, uint8_t destAddress, uint32_t timeout);

/*SD2 - D6 */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getProductInfo(IMD2002Handle_t pHandle, uint16_t *productInfo, uint8_t destAddress, uint32_t timeout);

/*SD2 - DA */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_getTargetList(IMD2002Handle_t pHandle, IMD2002_TargetList_t *pTargetList, uint8_t destAddress, uint32_t timeout);

/*SD2 - DF */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_setDefaultAppSetting(IMD2002Handle_t pHandle, uint16_t productNr, uint8_t destAddress, uint32_t timeout);
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_EEPROM_WriteBufferToFlash(IMD2002Handle_t pHandle, uint8_t *result, uint8_t destAddress, uint32_t timeout);

/*SD2 - BC */
IMD2002_API_EXPORT IMD2002_Result_t IMD2002_resetSensor(IMD2002Handle_t pHandle, uint8_t destAddress);



#ifdef __cplusplus
}
#endif

#endif // IMD2002_API_IF_H
