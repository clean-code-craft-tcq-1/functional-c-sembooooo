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



char *AlertContainer[AlertType_TotalNumber][NUMBER_OF_BATTERYMON_PARAMETERS];
int AlertContainerIndex[AlertType_TotalNumber];

void FeedAlertContainer(char *Identifier,AlertType_t AlertType)
{
    int index = AlertContainerIndex[AlertType];
    AlertContainer[AlertType][index] = Identifier;
    AlertContainerIndex[AlertType]++;
}

void AlertFromContainerDataForType(AlertType_t AlertType)
{
    int index;
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

void AlertFromContainerData(void)
{
    /*Coding for Tool */
    AlertFromContainerDataForType(AlertType_CloseToLowerRange);
    AlertFromContainerDataForType(AlertType_OutOfLowerRange);
    AlertFromContainerDataForType(AlertType_CloseToHigherRange);
    AlertFromContainerDataForType(AlertType_OutOfHigherRange); 
}

void Alert(char *Identifier, AlertType_t AlertType)
{    
        printf("%s %s\n",
         Identifier,
         AlertType_str[AlertType]);
}
