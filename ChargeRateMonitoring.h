#ifndef CHARGERATEMONITORING_H_
#define CHARGERATEMONITORING_H_

#include "Alert.h"

typedef struct {
  float HigherOutOfRangeThreshold;
  float HigherOutOfRangeWarningThreshold;
  char *Identifier;
}ChargeRateControlData_t;

extern int IsBatterychargeRateStable(float chargeRate);
#endif  /*CHARGERATEMONITORING_H_*/