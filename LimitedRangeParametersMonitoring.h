#ifndef LIMITEDRANGEPARAMETERSMONITORING_H_
#define LIMITEDRANGEPARAMETERSMONITORING_H_

#include "Alert.h"


typedef struct {
  float LowerOutOfRangeThreshold;
  float HigherOutOfRangeThreshold;
}ParameterThresholds_t;

typedef struct {
  ParameterThresholds_t ErrorThreshold;
  ParameterThresholds_t WarningThreshold;
  char *Identifier;
}TemparatureControlData_t;

typedef struct {
  ParameterThresholds_t ErrorThreshold;
  ParameterThresholds_t WarningThreshold;
  char *Identifier;
}StateOfControlData_t;

extern int IsBatteryTemparatureStable(float Temparature);

extern int IsBatteryStateOfChargeStable(float StateOfCharge);
#endif /*LIMITEDRANGEPARAMETERMONITORING_H_*/