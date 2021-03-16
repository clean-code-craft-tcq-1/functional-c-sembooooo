#ifndef LIMITEDRANGEPARAMETERSMONITORING_H_
#define LIMITEDRANGEPARAMETERSMONITORING_H_

#include "Alert.h"
#include "BatteryHealthMonitoring.h"


typedef struct {
  float LowerOutOfRangeThreshold;
  float HigherOutOfRangeThreshold;
}ParameterThresholds_t;

typedef struct {
  ParameterThresholds_t ErrorThreshold;
  ParameterThresholds_t WarningThreshold;
  BatteryParameter_t BatteryParameter;
}TemparatureControlData_t;

typedef struct {
  ParameterThresholds_t ErrorThreshold;
  ParameterThresholds_t WarningThreshold;
  BatteryParameter_t BatteryParameter;
}StateOfControlData_t;

extern int IsBatteryTemparatureStable(float Temparature);

extern int IsBatteryStateOfChargeStable(float StateOfCharge);
#endif /*LIMITEDRANGEPARAMETERMONITORING_H_*/