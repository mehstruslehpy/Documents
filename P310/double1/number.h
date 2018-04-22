#ifndef NUMBER_H
#define NUMBER_H
#include <stdint.h>
struct Number
{
  int sign;
  uint64_t mantissa;
  int16_t exp10;
  int16_t exp2;
};

#endif
