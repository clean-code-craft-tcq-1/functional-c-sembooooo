#include "Alert.h"
#include "Config/ParameterConfig.h"
#include <stdio.h>

char *AlertType_str[AlertType_TotalNumber] =
#if(BMS_ALERT_LANGUAGE == BMS_ALERT_LANGUAGE_ENGLISH)
{
    "Warning: Close to Lower Threshold",
    "ERROR: Lower Threshold Crossed",
    "Warning: Close to Higher Threshold",
    "ERROR: Higher Threshold Crossed"
};
#else
{
    "Warnung: Nahe am unteren Schwellenwert"
    "FEHLER: Unterer Schwellenwert überschritten ",
    "Warnung: Nahe an der höheren Schwelle"
    "FEHLER: Höherer Schwellenwert überschritten"
};
#endif  /*(BMS_ALERT_LANGUAGE == BMS_ALERT_LANGUAGE_ENGLISH)*/


/**
 * This can be done with dynamic memory allocation but
 * as it is a simple one with three parameters i went
 * static memory allocation.
 */ 
char *AlertContainer[AlertType_TotalNumber][NUMBER_OF_BATTERYMON_PARAMETERS];
int AlertContainerIndex[AlertType_TotalNumber];

void FeedAlertContainer(char *Identifier,AlertType_t AlertType)
{
    int index = AlertContainerIndex[AlertType];
    AlertContainer[AlertType][index] = Identifier;
    AlertContainerIndex[AlertType]++;
}


void AlertFromContainerData(void)
{
    int index, AlertType;
    for(AlertType = 0; AlertType < AlertType_TotalNumber; AlertType++)
    {
        for(index = 0;index<AlertContainerIndex[AlertType];index++)
        {
            printf("%s-",AlertContainer[AlertType][index]);
        }
        if(AlertContainerIndex[AlertType] != 0)
        {
            printf("%s \n",AlertType_str[AlertType]);
            AlertContainerIndex[AlertType] = 0;
        }
    }
    
}

void Alert(char *Identifier, AlertType_t AlertType)
{    
        printf("%s %s\n",
         Identifier,
         AlertType_str[AlertType]);
}
