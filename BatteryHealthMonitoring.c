#include <stdio.h>
#include <assert.h>
#include "BatteryHealthMonitoring.h"
#include "TemparatureMonitoring.h"
#include "ChargeRateMonitoring.h"
#include "StateOfChargeMonitoring.h"

#define TRUE 1
#define FALSE 0

BatteryHealthControlData_t BatteryHealthControlData ={
  FALSE,
  FALSE,
  FALSE
};

int batteryIsOk(float temperature, float soc, float chargeRate) {

  BatteryHealthControlData.IsTemparatureStable = IsBatteryTemparatureStable(temperature);
  BatteryHealthControlData.IsStateOfChargeStable = IsBatteryStateOfChargeStable(soc);
  BatteryHealthControlData.IsChargeRateStable = IsBatterychargeRateStable(chargeRate);
  return ( BatteryHealthControlData.IsTemparatureStable &&
           BatteryHealthControlData.IsStateOfChargeStable &&
           BatteryHealthControlData.IsChargeRateStable);
}

int main() {
  assert(batteryIsOk(25.0, 70.0, 0.7));
  assert(!batteryIsOk(50.0, 85.0, 0));
  return 0;
}
