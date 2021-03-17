#include "MathUtil.h"

int IsValueOutofLowerRangeThreshold(float value , float LowerThreshold)
{
  return (value < LowerThreshold);
}

int IsValueOutofHigherRangeThreshold(float value , float HigherThreshold)
{
  return (value > HigherThreshold);
}
