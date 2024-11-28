// assert fail in this program
#define DIGITS 1
// assert pass in this program
// #define DIGITS 1

#include "../assert_approx.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
  double x = 0.5;
  double y = 0.5 + (1. / (8.));
  assert_approx(x, y);
  return 0;
}
