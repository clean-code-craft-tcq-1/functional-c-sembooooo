#include "Config/ParameterConfig.h"
#include "ChargeRateMonitoring.h"
#include "MathUtil.h"


ChargeRateControlData_t ChargeRateControlData = {
    BMS_CHARGERAGE_LOWER_RANGE,
    Failuretype_NoFailure,
    "ChargeRate"
     };

int IsBatterychargeRateStable(float chargeRate)
{
  if(IsValueOutofHigherRangeThreshold(chargeRate,ChargeRateControlData.HigherOutOfRangeThreshold))
  {
    ChargeRateControlData.Failure = Failuretype_OutOfHigherRange;
    LogFailure(ChargeRateControlData.Identifier,
                            ChargeRateControlData.Failure);
  }
  return (ChargeRateControlData.Failure == Failuretype_NoFailure);
}