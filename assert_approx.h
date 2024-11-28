/**
 * @file assert_approx.h
 * @author para-diso (paradiso@ymail.ne.jp)
 * @brief assert for floating point value
 * @version 0.1
 * @date 2024-11-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#ifndef DIGITS
#define DIGITS 15
#endif

#define assert_approx(actual,expected) \
    assert_approx_core(DIGITS,actual,expected,__FILE__,__LINE__)

int assert_approx_core(unsigned int digits,double actual, double expected,const char* fname, unsigned int line);