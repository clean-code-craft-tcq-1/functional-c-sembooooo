

#include "BatteryHealthMonitoring.h"
#include "Alert.h"
float parameterValues[2][BatteryParameter_TotalNumber] = {
    {50.0, 0.9, 85.0},
    {25.0, 0.7, 55.0}
};

/*Dummy Controller */
int main()
{
    FeedBatteryParameterValues(parameterValues[0]);
    if(BatteryIsOk())
    {
        FeedBatteryParameterValues(parameterValues[1]);
    }
    AlertFromContainerData();
    BatteryIsOk();
    AlertFromContainerData();
}

