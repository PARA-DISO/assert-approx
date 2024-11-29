#include "assert_approx.h"
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
void get_fraction(double x,uint8_t* signe, uint64_t* exp,uint64_t* frac) {
  void* ptr = &x;
  uint64_t binary = *(uint64_t*)ptr;
  *exp = (binary >> 52) & 0x7FF;
  *frac = binary & 0xfffffffffffff;
  *signe = (binary >> 63) & 0x1;
}
double rebuild_double(uint8_t signe,uint64_t exp, uint64_t frac) {
  uint64_t binary = (((uint64_t) signe) << 63) | ((exp & 0x7FF) << 52) | frac;
  void* ptr = &binary;
  return *(double*)ptr;
}

inline uint64_t generate_bitmask(uint32_t digit) {
  return ((1ULL << (digit)) -1) << (52 - digit);
}

int assert_approx_core(unsigned int digits,double actual, double expected,const char* fname, unsigned int line) {
  uint8_t actual_signe,expected_signe;
  uint64_t actual_exp, actual_frac;
  uint64_t expected_exp, expected_frac;
  uint64_t digit_mask = generate_bitmask(digits);
  get_fraction(actual,&actual_signe,&actual_exp,&actual_frac);
  get_fraction(expected,&expected_signe,&expected_exp,&expected_frac);
  // get compared value
  uint64_t actual_value = (actual_frac & digit_mask);
  uint64_t expected_value  = (expected_frac & digit_mask);
  // check equals
  int is_eq_signe = actual_signe == expected_signe;
  int is_eq_exp = actual_exp == expected_exp;
  int is_approx_frac = actual_value == expected_value;
  if(!is_eq_signe || !is_eq_exp ||!is_approx_frac) {
    printf("assert failed @ %s:%d\n"
    "  actual: %g, but expected: %lf\n",
    fname,line,
    rebuild_double(actual_signe,actual_exp,actual_value),
    rebuild_double(expected_signe,expected_exp,expected_value)
    );
    exit(-1);
  } else {
    return 0;
  }
}
