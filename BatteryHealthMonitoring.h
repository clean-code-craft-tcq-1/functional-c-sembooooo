#ifndef BATTERYHEALTHMONITORING_H_
#define BATTERYHEALTHMONITORING_H_


typedef enum {
    BatteryParameter_Temparature,
    BatteryParameter_ChargeRate,
    BatteryParameter_StateOfCharge,
    BatteryParameter_TotalNumber
}BatteryParameter_t;

typedef struct {
    float Value;
    int (*Monitoring)(float param);
} parameter_t;

typedef enum{
    BatteryHealthStatus_NotOK,
    BatteryHealthStatus_OK
}BatteryHealthStatus_t;

typedef struct {
    parameter_t parameter[BatteryParameter_TotalNumber];
    BatteryHealthStatus_t HealthStatus;
} BatteryHealthControlData_t;


#endif  /*BATTERYHEALTHMONITORING_H_*/
