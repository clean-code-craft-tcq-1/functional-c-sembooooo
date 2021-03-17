#include "../../ChargeRateMonitoring.c"
#include "../../Config/ParameterConfig.h"   /* added to reduce work */
#include <stdio.h>
#include <assert.h>



static void Testcase_OutOfHigherRange(void)
{
    assert(IsBatterychargeRateStable(BMS_CHARGERATE_HIGHER_RANGE+0.1) == 0);    
}

static void Testcase_EqualToHigherRange(void)
{
    assert(IsBatterychargeRateStable(BMS_CHARGERATE_HIGHER_RANGE) == 1);    
}

int main()
{
    Testcase_OutOfHigherRange();
    Testcase_EqualToHigherRange();
    return 0;
}