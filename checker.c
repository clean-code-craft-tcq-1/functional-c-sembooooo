#include <stdio.h>
#include <assert.h>
#include "checker.h"

#define TRUE 1
#define FALSE 0

int IsValueOutofLowerRangeThreshold(float value , float LowerThreshold)
{
  return (value < LowerThreshold);
}

int IsValueOutofHigherRangeThreshold(float value , float HigherThreshold)
{
  return (value > HigherThreshold);
}

char *Failuretype_str[Failuretype_TotalNumber] =
{
  "Out of Lower Range ",
  "Out of Higher Range"
};

TemparatureControlData_t TemparatureControlData = {
  0.0,            
  45.0,           
  "Temparature" 
  };

int IsTempStable(float Temparature)
{
  int isTemparaturestable = TRUE;
  if(IsValueOutofLowerRangeThreshold(Temparature,TemparatureControlData.LowerOutOfRangeThreshold))
  {
    printf("%s %s\n",
          TemparatureControlData.Identifier,
          Failuretype_str[Failuretype_OutOfLowerRange]);
          isTemparaturestable = FALSE;
  }
  
  if(IsValueOutofHigherRangeThreshold(Temparature,TemparatureControlData.HigherOutOfRangeThreshold))
  {
        printf("%s %s\n",
          TemparatureControlData.Identifier, Failuretype_str[Failuretype_OutOfHigherRange]);
          isTemparaturestable = FALSE;
  }
     return isTemparaturestable;
}

StateOfChargeDeterminationControlData_t StateOfChargeDeterminationControlData ={
  20.0,             
  80.0,             
  "StateOfCharge" 
  };

int IsStateOfChargeDetermination(float soc)
{
  int IsStateOfChargeDeterminationok = TRUE;
    if(IsValueOutofLowerRangeThreshold(soc,StateOfChargeDeterminationControlData.LowerOutOfRangeThreshold))
  {
    printf("%s %s\n",
          StateOfChargeDeterminationControlData.Identifier,
          Failuretype_str[Failuretype_OutOfLowerRange]);
          IsStateOfChargeDeterminationok = FALSE;
  }
  
  if(IsValueOutofHigherRangeThreshold(soc,StateOfChargeDeterminationControlData.HigherOutOfRangeThreshold))
  {
        printf("%s %s\n",
          StateOfChargeDeterminationControlData.Identifier,
          Failuretype_str[Failuretype_OutOfHigherRange]);
        IsStateOfChargeDeterminationok = FALSE;
  }
  return IsStateOfChargeDeterminationok;
}

ChargeRateControlData_t ChargeRateControlData = {0.8,"ChargeRate"};

int IschargeRateOk(float chargeRate)
{
  int IsChargeRateok = TRUE;
  if(IsValueOutofHigherRangeThreshold(chargeRate,ChargeRateControlData.HigherOutOfRangeThreshold))
  {
    printf("%s %s\n",
          ChargeRateControlData.Identifier,
          Failuretype_str[Failuretype_OutOfHigherRange]);
          IsChargeRateok = FALSE;
  }
  return IsChargeRateok;
}


int batteryIsOk(float temperature, float soc, float chargeRate) {
  int istemparatureok, issocok, ischargerateok;
  istemparatureok = IsTempStable(temperature);
  issocok = IsStateOfChargeDetermination(soc);
  ischargerateok = IschargeRateOk(chargeRate);
  return ( istemparatureok && issocok && ischargerateok);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
