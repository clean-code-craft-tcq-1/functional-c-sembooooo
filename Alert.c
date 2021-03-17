#include "Alert.h"
#include "Config/ParameterConfig.h"
#include <stdio.h>
#include <assert.h>
#include "Console.h"

char *AlertType_str[AlertType_TotalNumber] =
#if(BMS_ALERT_LANGUAGE == BMS_ALERT_LANGUAGE_ENGLISH)
{
    NULL,
    "Warning: Close to Lower Threshold",
    "ERROR: Lower Threshold Crossed",
    "Warning: Close to Higher Threshold",
    "ERROR: Higher Threshold Crossed"
};
#else
{
    NULL,
    "Warnung: Nahe am unteren Schwellenwert",
    "FEHLER: Unterer Schwellenwert überschritten",
    "Warnung: Nahe an der höheren Schwelle",
    "FEHLER: Höherer Schwellenwert überschritten"
};
#endif  /*(BMS_ALERT_LANGUAGE == BMS_ALERT_LANGUAGE_ENGLISH)*/

char *Parameter_str[BatteryParameter_TotalNumber] = 
#if(BMS_ALERT_LANGUAGE == BMS_ALERT_LANGUAGE_ENGLISH)
{
    "Temparature",
    "ChargeRate",
    "StateOfCharge"    
};
#else
{
    "Temperatur",
    "Ladestrom",
    "Ladezustand"
};
#endif  /*(BMS_ALERT_LANGUAGE == BMS_ALERT_LANGUAGE_ENGLISH)*/



AlertType_t ParameterAlertContainer[BatteryParameter_TotalNumber] = {
    AlertType_NoAlert,
    AlertType_NoAlert,
    AlertType_NoAlert
};

void ReportToAlertContainer(BatteryParameter_t BatteryParameter,AlertType_t AlertType)
{
    assert(BatteryParameter <= (BatteryParameter_TotalNumber-1));
    assert(AlertType <= (AlertType_TotalNumber-1));
    ParameterAlertContainer[BatteryParameter] = AlertType;
}



void AlertFromContainerData(void)
{
    int index = 0;
    for(index = 0;index < BatteryParameter_TotalNumber;index++)
        if(ParameterAlertContainer[index] != AlertType_NoAlert)
        {
           printonConsole(Parameter_str[index], AlertType_str[ParameterAlertContainer[index]]);
           ParameterAlertContainer[index] = AlertType_NoAlert;
        }
}
