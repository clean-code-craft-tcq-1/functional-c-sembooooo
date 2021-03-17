
#include "../../BatteryHealthMonitoring.h"

typedef enum{
AlertType_NoAlert = 0,
AlertType_CloseToLowerRange,
AlertType_OutOfLowerRange,
AlertType_CloseToHigherRange,
AlertType_OutOfHigherRange,
AlertType_TotalNumber
}AlertType_t;

extern int call_ReportToAlertContainer;
extern  BatteryParameter_t BatteryParameter;
extern AlertType_t AlertType;
extern void ReportToAlertContainer(BatteryParameter_t Par_BatteryParameter,AlertType_t Par_AlertType);
