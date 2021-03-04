#include <stdio.h>
#include <assert.h>
#include "BatteryHealthMonitoring.h"
#include "TemparatureMonitoring.h"
#include "ChargeRateMonitoring.h"
#include "StateOfChargeMonitoring.h"

#define TRUE 1
#define FALSE 0

float good_param_value[3] = {25.0, 70.0, 0.7};
float bad_param_value[3] ={50.0, 85.0, 0};

BatteryHealthControlData_t BatteryHealthControlData ={
  {
    {
      0.0,
      &IsBatteryTemparatureStable
    },
    {
      0.0,
      &IsBatterychargeRateStable
    },
    {
      0.0,
      &IsBatteryStateOfChargeStable
    }
  },
  BatteryHealthStatus_OK
};

void FeedBatteryParameterValues(float *Param_Value)
{
  for(int loop_index = 0; loop_index < ((int)BatteryParameter_Temparature) ; loop_index++)
  {
    BatteryHealthControlData.parameter[loop_index].Value = *Param_Value;
    Param_Value++;
  }
}


int batteryIsOk(float temperature, float soc, float chargeRate) {

}

int main() {
  FeedBatteryParameterValues(good_param_value);
  assert(batteryIsOk());
  FeedBatteryParameterValues(bad_param_value);
  assert(!batteryIsOk());
  return 0;
}
