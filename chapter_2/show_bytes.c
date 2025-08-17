/* $begin show-bytes */
#include <stdio.h>
/* $end show-bytes */
#include <stdlib.h>
#include <string.h>
/* $begin show-bytes */

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  size_t i;
  for (i = 0; i < len; i++)
    printf(" %.2x", start[i]); // line:data:show_bytes_printf
  printf("\n");
}

void show_short(int x) {
  show_bytes((byte_pointer)&x, sizeof(short)); // line:data:show_bytes_short
}

void show_int(int x) {
  show_bytes((byte_pointer)&x, sizeof(int)); // line:data:show_bytes_amp1
}

void show_long(int x) {
  show_bytes((byte_pointer)&x, sizeof(long)); // line:data:show_bytes_long
}

void show_float(float x) {
  show_bytes((byte_pointer)&x, sizeof(float)); // line:data:show_bytes_amp2
}

void show_double(int x) {
  show_bytes((byte_pointer)&x, sizeof(double)); // line:data:show_bytes_double
}

void show_pointer(void *x) {
  show_bytes((byte_pointer)&x, sizeof(void *)); // line:data:show_bytes_amp3
}
/* $end show-bytes */

/* $begin test-show-bytes */
void test_show_bytes(int val) {
  int ival = val;
  float fval = (float)ival;
  int *pval = &ival;
  show_int(ival);
  show_float(fval);
  show_pointer(pval);

  short s = 0x12;
  long l = 0x12345678;
  double d = 1.2;
  show_short(s);
  show_long(l);
  show_double(d);
}
/* $end test-show-bytes */

void simple_show_a() {
  /* $begin simple-show-a */
  int val = 0x87654321;
  byte_pointer valp = (byte_pointer)&val;
  show_bytes(valp, 1); /* A. */
  show_bytes(valp, 2); /* B. */
  show_bytes(valp, 3); /* C. */
  /* $end simple-show-a */
}

void simple_show_b() {
  /* $begin simple-show-b */
  int val = 0x12345678;
  byte_pointer valp = (byte_pointer)&val;
  show_bytes(valp, 1); /* A. */
  show_bytes(valp, 2); /* B. */
  show_bytes(valp, 3); /* C. */
  /* $end simple-show-b */
}

void float_eg() {
  int x = 3490593;
  float f = (float)x;
  printf("For x = %d\n", x);
  show_int(x);
  show_float(f);

  x = 3510593;
  f = (float)x;
  printf("For x = %d\n", x);
  show_int(x);
  show_float(f);
}

void string_ueg() {
  /* $begin show-ustring */
  const char *s = "ABCDEF";
  show_bytes((byte_pointer)s, strlen(s));
  /* $end show-ustring */
}

void string_leg() {
  /* $begin show-lstring */
  const char *s = "abcdef";
  show_bytes((byte_pointer)s, strlen(s));
  /* $end show-lstring */
}

// show_twocomp 理解补码
void show_twocomp() {
  /* $begin show-twocomp */
  short x = 12345;
  short mx = -x;

  show_bytes((byte_pointer)&x, sizeof(short));
  show_bytes((byte_pointer)&mx, sizeof(short));
  /* $end show-twocomp */
}

int main(int argc, char *argv[]) {
  printf("sizeof short is: %ld\n", sizeof(short));
  printf("sizeof float is: %ld\n", sizeof(float));
  printf("sizeof long is: %ld\n", sizeof(long));
  printf("sizeof char is: %ld\n", sizeof(char));
  printf("sizeof unsigned char: %ld\n", sizeof(unsigned char));

  int val = 12345;

  if (argc > 1) {
    if (argc > 1) {
      val = strtol(argv[1], NULL, 0);
    }
    printf("\ncalling test_show_bytes\n");
    test_show_bytes(val);
  } else {
    printf("\ncalling show_twocomp\n");
    show_twocomp();
    printf("\nCalling simple_show_a\n");
    simple_show_a();
    printf("\nCalling simple_show_b\n");
    simple_show_b();
    printf("\nCalling float_eg\n");
    float_eg();
    printf("\nCalling string_ueg\n");
    string_ueg();
    printf("\nCalling string_leg\n");
    string_leg();
  }
  return 0;
}
