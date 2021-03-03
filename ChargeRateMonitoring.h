#ifndef CHARGERATEMONITORING_H_
#define CHARGERATEMONITORING_H_

#include "FailureHandling.h"

typedef struct {
  float HigherOutOfRangeThreshold;
  Failuretype_t Failure;
  char *Identifier;
}ChargeRateControlData_t;

extern int IsBatterychargeRateStable(float chargeRate);
#endif  /*CHARGERATEMONITORING_H_*/