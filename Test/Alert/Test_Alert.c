#include "../../Alert.c"
#include "stub_Console.h"


static void Test_ReportToAlertContainer(void)
{
    ReportToAlertContainer(BatteryParameter_Temparature,AlertType_CloseToHigherRange);
    assert(ParameterAlertContainer[BatteryParameter_Temparature] = AlertType_CloseToHigherRange);
    ReportToAlertContainer(BatteryParameter_StateOfCharge,AlertType_OutOfHigherRange);
    assert(ParameterAlertContainer[BatteryParameter_StateOfCharge] = AlertType_OutOfHigherRange);
    ReportToAlertContainer(BatteryParameter_ChargeRate,AlertType_OutOfHigherRange);
    assert(ParameterAlertContainer[BatteryParameter_ChargeRate] = AlertType_OutOfHigherRange);    
}

static void Test_NoPrintingDuringNoAlert(void)
{
    Reset_PrintOnConsoleStub();
    ParameterAlertContainer[BatteryParameter_Temparature] = AlertType_NoAlert;
    ParameterAlertContainer[BatteryParameter_ChargeRate] = AlertType_NoAlert;
    ParameterAlertContainer[BatteryParameter_StateOfCharge] = AlertType_NoAlert;
    AlertFromContainerData();
    assert(call_PrintOnConsole == 0);
}

static void Test_PrintIfatleastOneValueOtherThanNoAlert(void)
{
    Reset_PrintOnConsoleStub();
    ParameterAlertContainer[BatteryParameter_ChargeRate] = AlertType_OutOfHigherRange;
    ParameterAlertContainer[BatteryParameter_StateOfCharge] = AlertType_NoAlert;
    ParameterAlertContainer[BatteryParameter_StateOfCharge] = AlertType_NoAlert;
    AlertFromContainerData();
    assert(call_PrintOnConsole==1);
    assert(PrintOnConsoleInputParam[0].str[0] == Parameter_str[BatteryParameter_ChargeRate]);    
    assert(PrintOnConsoleInputParam[0].str[1] == AlertType_str[AlertType_OutOfHigherRange]); 
}

static void Test_TestAccumulatedPrint(void)
{
    Reset_PrintOnConsoleStub();
    ParameterAlertContainer[BatteryParameter_Temparature] = AlertType_OutOfHigherRange;
    ParameterAlertContainer[BatteryParameter_ChargeRate] = AlertType_OutOfLowerRange;
    ParameterAlertContainer[BatteryParameter_StateOfCharge] = AlertType_CloseToLowerRange;
    AlertFromContainerData();
    assert(call_PrintOnConsole==3);
    assert(PrintOnConsoleInputParam[0].str[0] == Parameter_str[BatteryParameter_Temparature]);    
    assert(PrintOnConsoleInputParam[0].str[1] == AlertType_str[AlertType_OutOfHigherRange]); 
    
    assert(PrintOnConsoleInputParam[1].str[0] == Parameter_str[BatteryParameter_ChargeRate]);    
    assert(PrintOnConsoleInputParam[1].str[1] == AlertType_str[AlertType_OutOfLowerRange]); 

    assert(PrintOnConsoleInputParam[2].str[0] == Parameter_str[BatteryParameter_StateOfCharge]);    
    assert(PrintOnConsoleInputParam[2].str[1] == AlertType_str[AlertType_CloseToLowerRange]); 

}


int main()
{
    Test_ReportToAlertContainer();
    Test_NoPrintingDuringNoAlert();
    Test_PrintIfatleastOneValueOtherThanNoAlert();
    Test_TestAccumulatedPrint();
    return 0;
}