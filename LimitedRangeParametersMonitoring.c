#include "Config/ParameterConfig.h"
#include "LimitedRangeParametersMonitoring.h"
#include "MathUtil.h"

#define TRUE 1
#define FALSE 0

int IsParameterStable(BatteryParameter_t BatteryParameter, ParameterThresholds_t *Parameter, float Value)
{
  int IsParameterStable = 1;
  if(IsValueOutofLowerRangeThreshold(Value,Parameter->LowerOutOfRangeThreshold) == TRUE)
  {
    IsParameterStable = 0;
    ReportToAlertContainer(BatteryParameter,AlertType_OutOfLowerRange);
  }
  
  if(IsValueOutofHigherRangeThreshold(Value,Parameter->HigherOutOfRangeThreshold)== TRUE)
  {
    ReportToAlertContainer(BatteryParameter,AlertType_OutOfHigherRange);
    IsParameterStable = 0;
  }
     return IsParameterStable;
}

void IsParameterWithinWarningRange(BatteryParameter_t BatteryParameter, ParameterThresholds_t *Parameter, float Value)
{
  if(IsValueOutofLowerRangeThreshold(Value,Parameter->LowerOutOfRangeThreshold) == TRUE)
  {
    ReportToAlertContainer(BatteryParameter,AlertType_CloseToLowerRange);
  }
  
  if(IsValueOutofHigherRangeThreshold(Value,Parameter->HigherOutOfRangeThreshold)== TRUE)
  {
    ReportToAlertContainer(BatteryParameter,AlertType_CloseToHigherRange);
  }
}

TemparatureControlData_t TemparatureControlData = {
  {
    BMS_TEMPARATURE_LOWER_RANGE,
    BMS_TEMPARATURE_HIGHER_RANGE
  },
  {
    BMS_TEMPARATURE_LOWER_WARNING_RANGE,            
    BMS_TEMPARATURE_HIGHER_WARNING_RANGE
  },
  BatteryParameter_Temparature
  };

StateOfControlData_t StateOfChargeControlData ={
    {
    BMS_STATEOFCHARGE_LOWER_RANGE,
    BMS_STATEOFCHARGE_HIGHER_RANGE
  },
  {
    BMS_STATEOFCHARGE_LOWER_WARNING_RANGE,             
    BMS_STATEOFCHARGE_HIGHER_WARNING_RANGE
  },
  BatteryParameter_StateOfCharge
  };

int IsBatteryTemparatureStable(float Temparature)
{
  int IsTemparatureStable;
    IsTemparatureStable = IsParameterStable(TemparatureControlData.BatteryParameter,
                                            &TemparatureControlData.ErrorThreshold,
                                            Temparature);
    if(IsTemparatureStable == 0)
    {
      return IsTemparatureStable;
    }                                        
    IsParameterWithinWarningRange(TemparatureControlData.BatteryParameter,
                                            &TemparatureControlData.WarningThreshold,
                                            Temparature);
  return IsTemparatureStable;
}   

int IsBatteryStateOfChargeStable(float StateOfCharge)
{
    int IsSOCStable ;
    IsSOCStable = IsParameterStable(StateOfChargeControlData.BatteryParameter,
                                            &StateOfChargeControlData.ErrorThreshold,
                                            StateOfCharge);
    if(IsSOCStable == 0)
    {
      return IsSOCStable;
    }                                        
    IsParameterWithinWarningRange(StateOfChargeControlData.BatteryParameter,
                                            &StateOfChargeControlData.WarningThreshold,
                                            StateOfCharge);
  return IsSOCStable;

}
