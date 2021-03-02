typedef enum{
Failuretype_OutOfLowerRange,
Failuretype_OutOfHigherRange,
Failuretype_TotalNumber
}Failuretype_t;

typedef struct {
  float LowerOutOfRangeThreshold;
  float HigherOutOfRangeThreshold;
  char *Identifier;
}TemparatureControlData_t;

typedef struct {
  float LowerOutOfRangeThreshold;
  float HigherOutOfRangeThreshold;
  char *Identifier;
}StateOfChargeDeterminationControlData_t;

typedef struct {
  float HigherOutOfRangeThreshold;
  char *Identifier;
}ChargeRateControlData_t;