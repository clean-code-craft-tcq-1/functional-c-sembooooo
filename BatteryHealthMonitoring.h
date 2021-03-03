#ifndef BATTERYHEALTHMONITORING_H_
#define BATTERYHEALTHMONITORING_H_

typedef struct {
    int IsTemparatureStable;
    int IsChargeRateStable;
    int IsStateOfChargeStable;
} BatteryHealthControlData_t;


#endif  /*BATTERYHEALTHMONITORING_H_*/