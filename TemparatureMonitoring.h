#ifndef TEMPARATUREMONITORING_H_
#define TEMPARATUREMONITORING_H_

#include "FailureHandling.h"

typedef struct {
  float LowerOutOfRangeThreshold;
  float HigherOutOfRangeThreshold;
  Failuretype_t Failure;
  char *Identifier;
}TemparatureControlData_t;

extern int IsBatteryTemparatureStable(float Temparature);

#endif /*TEMPARATUREMONITORING_H_*/