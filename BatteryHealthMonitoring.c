#include <stdio.h>
#include <assert.h>
#include "BatteryHealthMonitoring.h"
#include "LimitedRangeParametersMonitoring.h"
#include "ChargeRateMonitoring.h"
#include "Config/ParameterConfig.h"

#define TRUE 1
#define FALSE 0


float param_value[][3] = {
  {25.0, 0.7, 70.0},  /* Good parameters */
  {50.0, 0.0,85.0},    /* Bad Parameters */
  {(BMS_TEMPARATURE_HIGHER_WARNING_RANGE+0.5) ,
   (BMS_CHARGERATE_HIGHER_WARNING_RANGE+0.01),
   (BMS_STATEOFCHARGE_HIGHER_WARNING_RANGE+0.5)}  /*Warning Parameters */
  };

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
    printf("%f \n",BatteryHealthControlData.parameter[loop_index].Value);
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
  FeedBatteryParameterValues(param_value[0]);
  assert(batteryIsOk());
  FeedBatteryParameterValues(param_value[1]);
  assert(!batteryIsOk());
  FeedBatteryParameterValues(param_value[2]);
  assert(batteryIsOk());
  return 0;
}
