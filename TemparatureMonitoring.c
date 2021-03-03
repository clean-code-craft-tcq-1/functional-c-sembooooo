#include "ParameterConfig.h"
#include "TemparatureMonitoring.h"
#include "MathUtil.h"

#define TRUE 1
#define FALSE 0

TemparatureControlData_t TemparatureControlData = {
  BMS_TEMPARATURE_LOWER_RANGE,            
  BMS_TEMPARATURE_HIGHER_RANGE,
  Failuretype_NoFailure,           
  "Temparature" 
  };

int IsBatteryTemparatureStable(float Temparature)
{
  if(IsValueOutofLowerRangeThreshold(Temparature,TemparatureControlData.LowerOutOfRangeThreshold) == TRUE)
  {
    TemparatureControlData.Failure = Failuretype_OutOfLowerRange;
    DisplayFailureOnConsole(TemparatureControlData.Identifier,
                           TemparatureControlData.Failure);
  }
  
  if(IsValueOutofHigherRangeThreshold(Temparature,TemparatureControlData.HigherOutOfRangeThreshold)== TRUE)
  {
    TemparatureControlData.Failure = Failuretype_OutOfHigherRange;
    DisplayFailureOnConsole(TemparatureControlData.Identifier,
                           TemparatureControlData.Failure);
  }
     return (TemparatureControlData.Failure == Failuretype_NoFailure);
}