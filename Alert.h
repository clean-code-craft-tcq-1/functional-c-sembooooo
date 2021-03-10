#ifndef FAILUREHANDLING_H_
#define FAILUREHANDLING_H_

typedef enum{
AlertType_NoAlert =0,
AlertType_CloseToLowerRange,
AlertType_OutOfLowerRange,
AlertType_CloseToHigherRange,
AlertType_OutOfHigherRange,
AlertType_TotalNumber
}AlertType_t;

extern void Alert(char *Identifier, AlertType_t AlertType);

#endif  /*FAILUREHANDLING_H_*/