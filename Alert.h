#ifndef FAILUREHANDLING_H_
#define FAILUREHANDLING_H_

#include "BatteryHealthMonitoring.h"

typedef enum{
AlertType_NoAlert = 0,
AlertType_CloseToLowerRange,
AlertType_OutOfLowerRange,
AlertType_CloseToHigherRange,
AlertType_OutOfHigherRange,
AlertType_TotalNumber
}AlertType_t;


extern void AlertFromContainerData(void);
extern void ReportToAlertContainer(BatteryParameter_t BatteryParameter,AlertType_t AlertType);


#endif  /*FAILUREHANDLING_H_*/