

#include "BatteryHealthMonitoring.h"
#include "Alert.h"
#include <assert.h>
float parameterValues[2][BatteryParameter_TotalNumber] = {
    {50.0, 0.9, 85.0},
    {25.0, 0.7, 45.0}
};

/**
 * Dummy Controller does only two things
 * 1. Feeds wrong values 
 * 2. Checks if battery is ok (obvious!) and then feeds it the proper values
 * 3. Alerts if there are any alerts in container
 * 4.will again checks if battery is ok
 * 5. Alerts if there are any alerts in container
 * 
*/
int main()
{
    FeedBatteryParameterValues(parameterValues[0]);
    if(IsbatteryOk())
    {
        FeedBatteryParameterValues(parameterValues[1]);
    }
    AlertFromContainerData();
    assert(IsbatteryOk());
    AlertFromContainerData();
}

