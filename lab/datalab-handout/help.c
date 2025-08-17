#include <stdio.h>

int main() {
  printf("~5 result is: %d\n", ~5);
  printf("negate Tmin is %0x\n", -0x80000000);
  printf("negative number >> 31 is %x\n", -2 >> 31);
  printf("negative number >> 31 sign is %d\n", (-2 >> 31) & 1);
  return 0;
}
