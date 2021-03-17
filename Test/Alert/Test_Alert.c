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

static void Test_PrintIfNotNoAlert(void)
{
    Reset_PrintOnConsoleStub();
    ParameterAlertContainer[BatteryParameter_ChargeRate] = AlertType_OutOfHigherRange;
    ParameterAlertContainer[BatteryParameter_StateOfCharge] = AlertType_NoAlert;
    ParameterAlertContainer[BatteryParameter_StateOfCharge] = AlertType_NoAlert;
    AlertFromContainerData();
    assert(call_PrintOnConsole==1);    
}



int main()
{
    Test_ReportToAlertContainer();
    Test_NoPrintingDuringNoAlert();
    Test_PrintIfNotNoAlert();
    return 0;
}