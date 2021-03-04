#include <stdio.h>
#include <assert.h>
#include "BatteryHealthMonitoring.h"
#include "LimitedRangeParametersMonitoring.h"
#include "ChargeRateMonitoring.h"

#define TRUE 1
#define FALSE 0

float good_param_value[3] = {25.0, 0.7, 70.0};
float bad_param_value[3] ={50.0, 0.0,85.0};

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
  int loop_index;
  for(loop_index = 0; loop_index < ((int)BatteryParameter_TotalNumber) ; loop_index++)
  {
    BatteryHealthControlData.parameter[loop_index].Value = *Param_Value;
    Param_Value++;
  }
}


int batteryIsOk() 
{
  int loop_index;
  for(loop_index = 0; loop_index < ((int)BatteryParameter_TotalNumber) ; loop_index++)
  {
    BatteryHealthControlData.HealthStatus = (BatteryHealthControlData.parameter[loop_index].Monitoring(
                                              BatteryHealthControlData.parameter[loop_index].Value) &&
                                              BatteryHealthControlData.HealthStatus);
  }
  return  BatteryHealthControlData.HealthStatus;
}

int main() {
  FeedBatteryParameterValues(good_param_value);
  assert(batteryIsOk());
  FeedBatteryParameterValues(bad_param_value);
  assert(!batteryIsOk());
  return 0;
}
