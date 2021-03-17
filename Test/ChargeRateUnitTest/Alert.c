#include "Alert.h"


int call_ReportToAlertContainer =0;
BatteryParameter_t BatteryParameter;
AlertType_t AlertType;
void ReportToAlertContainer(BatteryParameter_t Par_BatteryParameter,AlertType_t Par_AlertType)
{
    call_ReportToAlertContainer++;
    BatteryParameter = Par_BatteryParameter;
    AlertType = Par_AlertType;
}
