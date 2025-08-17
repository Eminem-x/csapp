#include <stdio.h>

typedef unsigned char *byte_pointer;

int main() {
  int x = 0x12345678;
  byte_pointer start = (byte_pointer)(&x);
  printf("is little endian: %d\n", start[0] == 0x78);
  return 0;
}
