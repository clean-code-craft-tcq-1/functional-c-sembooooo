#include "Config/ParameterConfig.h"
#include "LimitedRangeParametersMonitoring.h"
#include "MathUtil.h"

#define TRUE 1
#define FALSE 0

int IsParameterStable(LimitedRangeParameterControlData_t *Parameter, float Value)
{
  if(IsValueOutofLowerRangeThreshold(Value,Parameter->LowerOutOfRangeThreshold) == TRUE)
  {
    Parameter->Failure = Failuretype_OutOfLowerRange;
    LogFailure(Parameter->Identifier,
                           Parameter->Failure);
  }
  
  if(IsValueOutofHigherRangeThreshold(Value,Parameter->HigherOutOfRangeThreshold)== TRUE)
  {
    Parameter->Failure = Failuretype_OutOfHigherRange;
    LogFailure(Parameter->Identifier,
                           Parameter->Failure);
  }
     return (Parameter->Failure == Failuretype_NoFailure);
}

LimitedRangeParameterControlData_t TemparatureControlData = {
  BMS_TEMPARATURE_LOWER_RANGE,            
  BMS_TEMPARATURE_HIGHER_RANGE,
  Failuretype_NoFailure,           
  "Temparature" 
  };

LimitedRangeParameterControlData_t StateOfChargeControlData ={
  BMS_STATEOFCHARGE_LOWER_RANGE,             
  BMS_STATEOFCHARGE_HIGHER_RANGE,
  Failuretype_NoFailure,
  "StateOfCharge" 
  };

int IsBatteryTemparatureStable(float Temparature)
{
  IsParameterStable(&TemparatureControlData,Temparature);
}

int IsBatteryStateOfChargeStable(float StateOfCharge)
{
  IsParameterStable(&StateOfChargeControlData,StateOfCharge);
}
