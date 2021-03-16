#include "Config/ParameterConfig.h"
#include "ChargeRateMonitoring.h"
#include "MathUtil.h"


ChargeRateControlData_t ChargeRateControlData = {
    BMS_CHARGERATE_HIGHER_RANGE,
    BMS_CHARGERATE_HIGHER_WARNING_RANGE,
    BatteryParameter_ChargeRate
     };

int IsBatterychargeRateStable(float chargeRate)
{
    int IsChargeRateStable = 1;
  if(IsValueOutofHigherRangeThreshold(chargeRate,ChargeRateControlData.HigherOutOfRangeThreshold))
  {
    IsChargeRateStable = 0;
    ReportToAlertContainer(ChargeRateControlData.BatteryParameter,
                            AlertType_OutOfHigherRange);
    return IsChargeRateStable;
  }
  if(IsValueOutofHigherRangeThreshold(chargeRate,ChargeRateControlData.HigherOutOfRangeWarningThreshold))
  {
    ReportToAlertContainer(ChargeRateControlData.BatteryParameter,
                            AlertType_CloseToHigherRange);
  }
  return IsChargeRateStable;
}