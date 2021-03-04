#ifndef LIMITEDRANGEPARAMETERSMONITORING_H_
#define LIMITEDRANGEPARAMETERSMONITORING_H_

#include "FailureHandling.h"

typedef struct {
  float LowerOutOfRangeThreshold;
  float HigherOutOfRangeThreshold;
  Failuretype_t Failure;
  char *Identifier;
}LimitedRangeParameterControlData_t;

extern int IsBatteryTemparatureStable(float Temparature);

extern int IsBatteryStateOfChargeStable(float StateOfCharge);
#endif /*LIMITEDRANGEPARAMETERMONITORING_H_*/