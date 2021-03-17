#include <stdio.h>
#include "BatteryHealthMonitoring.h"
#include "LimitedRangeParametersMonitoring.h"
#include "ChargeRateMonitoring.h"
#include "Config/ParameterConfig.h"
#include "Alert.h"

#define TRUE 1
#define FALSE 0

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
  BatteryHealthControlData.HealthStatus = BatteryHealthStatus_OK;
  
  for(loop_index = 0; loop_index < ((int)BatteryParameter_TotalNumber) ; loop_index++)
  {
    BatteryHealthControlData.HealthStatus = (BatteryHealthControlData.parameter[loop_index].Monitoring(
                                              BatteryHealthControlData.parameter[loop_index].Value) &&
                                              BatteryHealthControlData.HealthStatus);
  }
  return  BatteryHealthControlData.HealthStatus;
}
