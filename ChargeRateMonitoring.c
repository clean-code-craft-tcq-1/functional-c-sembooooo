#include "Config/ParameterConfig.h"
#include "ChargeRateMonitoring.h"
#include "MathUtil.h"


ChargeRateControlData_t ChargeRateControlData = {
    BMS_CHARGERATE_HIGHER_RANGE,
    BMS_CHARGERATE_HIGHER_WARNING_RANGE,
#if(BMS_LANGUAGE_IN_FAILURELOG == BMS_LANGUAGE_IN_FAILURELOG_ENGLISH)
    "ChargeRate"
#else
    "Ladestrom"
#endif  /*(BMS_LANGUAGE_IN_FAILURELOG == BMS_LANGUAGE_IN_FAILURELOG_ENGLISH)*/
     };

int IsBatterychargeRateStable(float chargeRate)
{
    int IsChargeRateStable = 1;
  if(IsValueOutofHigherRangeThreshold(chargeRate,ChargeRateControlData.HigherOutOfRangeThreshold))
  {
    IsChargeRateStable = 0;
    FeedAlertContainer(ChargeRateControlData.Identifier,
                            AlertType_OutOfHigherRange);
    return IsChargeRateStable;
  }
  if(IsValueOutofHigherRangeThreshold(chargeRate,ChargeRateControlData.HigherOutOfRangeWarningThreshold))
  {
    FeedAlertContainer(ChargeRateControlData.Identifier,
                            AlertType_CloseToHigherRange);
  }
  return IsChargeRateStable;
}