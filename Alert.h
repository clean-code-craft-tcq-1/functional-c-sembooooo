#ifndef FAILUREHANDLING_H_
#define FAILUREHANDLING_H_

typedef enum{
AlertType_CloseToLowerRange,
AlertType_OutOfLowerRange,
AlertType_CloseToHigherRange,
AlertType_OutOfHigherRange,
AlertType_TotalNumber
}AlertType_t;

#define NUMBER_OF_BATTERYMON_PARAMETERS (3)

extern void Alert(char *Identifier, AlertType_t AlertType);
extern void FeedAlertContainer(char *Identifier, AlertType_t AlertType);
extern void AlertFromContainerData(void);

#endif  /*FAILUREHANDLING_H_*/