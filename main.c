#include "stdio.h"
#include "time.h"
#include "math.h"

#include "IMD2002_radarAPI_if.h"
#include "IMD2002_radarAPI_structs.h"
#include "IMD2002_radarAPI_enums.h"

#define IMD2002_COMPORT      (12)
#define IMD2002_ADDRESS     (100)
#define IMD2002_TIMEOUT     (150)

int main()
{
    printf("START\n\n");

    /************** CHECK API VERSION **************/
    IMD2002Handle_t handle;
    IMD2002_Result_t res;

    float32_t version;
    #include "IMD2002_radarAPI_if.h" // Include the header file containing the function declaration

    res = IMD2002_getApiVersion(&version); // Call the function to get the API version
    if (res != IMD2002_API_ERR_OK)
    {
        printf("IMD2002_getApiVersion failed\n");
        printf("error: %d\n", res);
        return 0;
    }
    else
    {
        printf("IMD2002_getApiVersion - %.3f\n", version);
    }

    /************** CONNECT DEVICE **************/
    /* Init serial port */
    uint8_t port = IMD2002_COMPORT;
#ifndef __linux__
    res = IMD2002_initComPort(&handle, port, IMD2002_BAUDRATE_256000);
#else
    res = IMD2002_initComPort(&handle, "/dev/ttyUSB0", 9, IMD2002_BAUDRATE_256000);
#endif
    if (res != IMD2002_API_ERR_OK)
    {
        printf("IMD2002_initComPort failed\n");
        return 0;
    }
    else
    {
        printf("IMD2002_initComPort - %d\n", port);
    }
}