
#include "../../BatteryHealthMonitoring.h"

typedef struct{
    char *str[2];
}PrintOnConsoleInputParam_t;

extern PrintOnConsoleInputParam_t PrintOnConsoleInputParam[BatteryParameter_TotalNumber];
extern int PrintOnConsoleInputParamIndex;
extern int call_PrintOnConsole;

extern void Reset_PrintOnConsoleStub(void);