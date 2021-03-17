
#include "../../Console.h"
#include "stub_Console.h"

PrintOnConsoleInputParam_t PrintOnConsoleInputParam[BatteryParameter_TotalNumber];
int PrintOnConsoleInputParamIndex;

int call_PrintOnConsole = 0;

void printonConsole(char* str1, char* str2)
{
    call_PrintOnConsole++;
    PrintOnConsoleInputParam[PrintOnConsoleInputParamIndex].str[0] = str1;
    PrintOnConsoleInputParam[PrintOnConsoleInputParamIndex].str[1] = str2;
    PrintOnConsoleInputParamIndex++;
}


void Reset_PrintOnConsoleStub(void)
{
    int i;
    call_PrintOnConsole = 0;
    PrintOnConsoleInputParamIndex = 0;
    for(i=0;i<BatteryParameter_TotalNumber;i++ )
    {
        PrintOnConsoleInputParam[i].str[0] = 0;
        PrintOnConsoleInputParam[i].str[1] = 0;
    }
}