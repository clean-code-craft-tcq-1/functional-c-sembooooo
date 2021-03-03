#include "ParameterConfig.h"
#include "StateOfChargeMonitoring.h"
#include "MathUtil.h"

StateOfChargeControlData_t StateOfChargeControlData ={
  BMS_STATEOFCHARGE_LOWER_RANGE,             
  BMS_STATEOFCHARGE_HIGHER_RANGE,
  Failuretype_NoFailure,
  "StateOfCharge" 
  };

int IsBatteryStateOfChargeStable(float StateOfCharge)
{
  if(IsValueOutofLowerRangeThreshold(StateOfCharge,StateOfChargeControlData.LowerOutOfRangeThreshold))
  {
    StateOfChargeControlData.Failure = Failuretype_OutOfLowerRange;
    DisplayFailureOnConsole(StateOfChargeControlData.Identifier,
                           StateOfChargeControlData.Failure);
  }
  
  if(IsValueOutofHigherRangeThreshold(StateOfCharge,StateOfChargeControlData.HigherOutOfRangeThreshold))
  {
    StateOfChargeControlData.Failure = Failuretype_OutOfHigherRange;
    DisplayFailureOnConsole(StateOfChargeControlData.Identifier,
                           StateOfChargeControlData.Failure);
  }
     return (StateOfChargeControlData.Failure == Failuretype_NoFailure);
}