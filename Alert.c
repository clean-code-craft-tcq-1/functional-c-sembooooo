#include "Alert.h"
#include "Config/ParameterConfig.h"
#include <stdio.h>

char *AlertType_str[AlertType_TotalNumber] =
#if(BMS_ALERT_LANGUAGE == BMS_ALERT_LANGUAGE_ENGLISH)
{
    "No Failure",
    "Warning: Close to Lower Threshold",
    "ERROR: Lower Threshold Crossed",
    "Warning: Close to Higher Threshold",
    "ERROR: Higher Threshold Crossed"
};
#else
{
    "Kein Fehler",
    "Warnung: Nahe am unteren Schwellenwert"
    "FEHLER: Unterer Schwellenwert überschritten ",
    "Warnung: Nahe an der höheren Schwelle"
    "FEHLER: Höherer Schwellenwert überschritten"
};
#endif  /*(BMS_ALERT_LANGUAGE == BMS_ALERT_LANGUAGE_ENGLISH)*/



void Alert(char *Identifier, AlertType_t AlertType)
{
        printf("%s %s\n",
         Identifier,
         AlertType_str[AlertType]);
}
