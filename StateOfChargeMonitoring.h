#ifndef STATEOFCHARGEMONITORING_H_
#define STATEOFCHARGEMONITORING_H_

#include "FailureHandling.h"

typedef struct {
  float LowerOutOfRangeThreshold;
  float HigherOutOfRangeThreshold;
  Failuretype_t Failure;
  char *Identifier;
}StateOfChargeControlData_t;

extern int IsBatteryStateOfChargeStable(float StateOfCharge);

#endif  /*STATEOFCHARGEMONITORING_H_*/