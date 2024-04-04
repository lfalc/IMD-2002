#ifndef IMD2002_RADARAPI_STRUCTS_H
#define IMD2002_RADARAPI_STRUCTS_H

/**************************************************************************************
  includes
**************************************************************************************/
#include "IMD2002_radarAPI_basicTypes.h"
#include "IMD2002_radarAPI_enums.h"


/**************************************************************************************
 defines
**************************************************************************************/
#define IMD2002_MAX_TARGETS  (15)

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************
   typedefs
**************************************************************************************/

typedef struct IMD2002Handle *IMD2002Handle_t;


typedef struct {
    float32_t f32_range_m;                  /* [m]*/
    float32_t f32_velocity_mps;             /* [m/s] */
    float32_t f32_signal_dB;                /* [dB] */
    float32_t f32_estimatedTimeOfArrival_s; /* [s] */
    float32_t f32_incidentAngle_deg;       /* [°]*/
} IMD2002_Target_t;

typedef struct {
    uint16_t ui16_nrOfTargets;
    uint16_t ui16_targetListId;
    uint8_t ui8_blockageDetected;           /* blockage level above threshold */
    uint8_t ui8_blockageLevel;              /* blockage level [%] */
    uint16_t ui16_reserved2;
    IMD2002_Target_t target[IMD2002_MAX_TARGETS];
} IMD2002_TargetList_t;


#ifdef __cplusplus
}
#endif

#endif // IMD2002_RADARAPI_STRUCTS_H
