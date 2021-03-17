#include "../../BatteryHealthMonitoring.c"
#include <assert.h>


static void TestCase_ParametersWithinRange(void)
{
  float param_value[1][3] ={{25.0, 0.7, 70.0}};
  FeedBatteryParameterValues(param_value[0]);
  assert(IsbatteryOk());  
}

static void TestCase_ParametersOutOfHigherRange(void)
{
  float param_value[1][3] ={{50.0, 0.9, 85.0}};
  FeedBatteryParameterValues(param_value[0]);
  assert(!IsbatteryOk());  
}

static void TestCase_ParametersOutOfLowerRange(void)
{
  float param_value[1][3] ={{-1.0, 0.0, 19.0}};
  FeedBatteryParameterValues(param_value[0]);
  assert(!IsbatteryOk());  
}

static void TestCase_OnlyTemparatureOutOfRange(void)
{
  float param_value[1][3] ={{50.0,  0.7, 70.0}};
  FeedBatteryParameterValues(param_value[0]);
  assert(!IsbatteryOk());  
}

static void TestCase_OnlyChargeRateOutOfRange(void)
{
  float param_value[1][3] ={{15.0,  0.9, 70.0}};
  FeedBatteryParameterValues(param_value[0]);
  assert(!IsbatteryOk());  
}

static void TestCase_OnlyStateOfChargeRateOutOfRange(void)
{
  float param_value[1][3] ={{15.0,  0.6, 81.0}};
  FeedBatteryParameterValues(param_value[0]);
  assert(!IsbatteryOk());  
}


int main()
{
  TestCase_ParametersWithinRange();
  TestCase_ParametersOutOfHigherRange();
  TestCase_ParametersOutOfLowerRange();
  TestCase_OnlyTemparatureOutOfRange();
  TestCase_OnlyChargeRateOutOfRange();
  TestCase_OnlyStateOfChargeRateOutOfRange();
  return 0;
}
