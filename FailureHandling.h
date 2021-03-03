#ifndef FAILUREHANDLING_H_
#define FAILUREHANDLING_H_

typedef enum{
Failuretype_NoFailure =0,
Failuretype_OutOfLowerRange,
Failuretype_OutOfHigherRange,
Failuretype_TotalNumber
}Failuretype_t;

extern void DisplayFailureOnConsole(char *Identifier, Failuretype_t Failuretype);

#endif  /*FAILUREHANDLING_H_*/