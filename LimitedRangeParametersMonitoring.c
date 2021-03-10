#include "Config/ParameterConfig.h"
#include "LimitedRangeParametersMonitoring.h"
#include "MathUtil.h"

#define TRUE 1
#define FALSE 0

int IsParameterStable(char *Identifier, ParameterThresholds_t *Parameter, float Value)
{
  int IsParameterStable = 1;
  if(IsValueOutofLowerRangeThreshold(Value,Parameter->LowerOutOfRangeThreshold) == TRUE)
  {
    IsParameterStable = 0;
    Alert(Identifier,AlertType_OutOfLowerRange);
  }
  
  if(IsValueOutofHigherRangeThreshold(Value,Parameter->HigherOutOfRangeThreshold)== TRUE)
  {
    Alert(Identifier,AlertType_OutOfHigherRange);
    IsParameterStable = 0;
  }
     return IsParameterStable;
}

void IsParameterWithinWarningRange(char *Identifier, ParameterThresholds_t *Parameter, float Value)
{
  if(IsValueOutofLowerRangeThreshold(Value,Parameter->LowerOutOfRangeThreshold) == TRUE)
  {
    Alert(Identifier,AlertType_CloseToLowerRange);
  }
  
  if(IsValueOutofHigherRangeThreshold(Value,Parameter->HigherOutOfRangeThreshold)== TRUE)
  {
    Alert(Identifier,AlertType_CloseToHigherRange);
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
#if(BMS_LANGUAGE_IN_FAILURELOG == BMS_LANGUAGE_IN_FAILURELOG_ENGLISH)          
  "Temparature" 
#else
  "Temperatur"
#endif  /*(BMS_LANGUAGE_IN_FAILURELOG == BMS_LANGUAGE_IN_FAILURELOG_ENGLISH)*/
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
#if(BMS_LANGUAGE_IN_FAILURELOG == BMS_LANGUAGE_IN_FAILURELOG_ENGLISH) 
  "StateOfCharge" 
#else
  "Ladezustand"
#endif /*(BMS_LANGUAGE_IN_FAILURELOG == BMS_LANGUAGE_IN_FAILURELOG_ENGLISH) */
  };

int IsBatteryTemparatureStable(float Temparature)
{
  int IsTemparatureStable;
    IsTemparatureStable = IsParameterStable(TemparatureControlData.Identifier,
                                            &TemparatureControlData.ErrorThreshold,
                                            Temparature);
    if(IsTemparatureStable == 0)
    {
      return IsTemparatureStable;
    }                                        
    IsParameterWithinWarningRange(TemparatureControlData.Identifier,
                                            &TemparatureControlData.WarningThreshold,
                                            Temparature);
  return IsTemparatureStable;
}   

int IsBatteryStateOfChargeStable(float StateOfCharge)
{
    int IsSOCStable ;
    IsSOCStable = IsParameterStable(StateOfChargeControlData.Identifier,
                                            &StateOfChargeControlData.ErrorThreshold,
                                            StateOfCharge);
    if(IsSOCStable == 0)
    {
      return IsSOCStable;
    }                                        
    IsParameterWithinWarningRange(StateOfChargeControlData.Identifier,
                                            &StateOfChargeControlData.WarningThreshold,
                                            StateOfCharge);
  return IsSOCStable;

}
