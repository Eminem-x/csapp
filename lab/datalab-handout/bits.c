/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // x ^ y = ~(x & y) & ~(~x & ~y)
  int a = x & y;
  int b = (~x) & (~y);
  int c = (~a) & (~b);
  return c;
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) { return (1 << 31); }
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int a = ((x + 1) ^ x) + 1; // expected 0
  int b = ~x;                // expected not 0, make sure not -1
  int d = a | !b;            // expected 0
  return !d;
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int a = 0xAA;
  a = x & a;         // expected 0xAA
  a = (x >> 8) & a;  // expected 0xAA
  a = (x >> 16) & a; // expected 0xAA
  a = (x >> 24) & a; // expected 0xAA
  return !(a ^ 0xAA);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) { return ~x + 1; }
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0'
 * to '9') Example: isAsciiDigit(0x35) = 1. isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int a = 0x30;
  int b = (x & a) ^ a; // expected 0
  int c = 0x3F;
  int d = (c | (x + 6)) ^ c; // expected 0
  int e = (x >> 31) | 0;     // expected 0, make sure postive
  return !(b | d | e);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int mask = !x + ~0; // FF or 00
  return (y & mask) | (z & ~mask);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int x_sign = (x >> 31) & 1;
  int y_sign = (y >> 31) & 1;
  int sub = x + ~y + 1;
  int sub_sign = (sub >> 31) & 1;
  // printf("ycx debug %d %d %d %d\n", x_sign, y_sign, sub, sub_sign);
  // 1. x 是负数，y 是整数，一定成立
  // 2. 异号相减可能会溢出，当 sub 结果小于 0 时，判断是否同号
  // 3. 特殊判断 0
  return (x_sign & !y_sign) | (sub_sign & (x_sign ^ !y_sign)) | !sub;
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
  // 当 x = 0 时，-x = 0，两者符号位相同，而 x ≠ 0 时，-x 与 x 的符号位显然不同
  // 特殊处理 Tmin, 负数特判
  int x_sign = (x >> 31) & 1;
  int neg_x_sign = ((~x + 1)) >> 31 & 1;
  int result = ~(x_sign ^ neg_x_sign) + 2;
  return result & (~x_sign + 2);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // 参考：https://zhuanlan.zhihu.com/p/472188244
  // x 为正数，以八位为例：0011 1010，需找到最高位 1，除此以外，还需一位 0
  // 作为符号位;
  // x 为负数，以八位为例：1100 1001，需找到最高位 0，除此以外，还需更高一位 1
  // 作为符号位;
  // 为了统一，不妨当 x 为负数时，将其取反, 那么也只需要找到最高位 1
  // 后再加一位就好, 即 n + 1.

  // 将所有变量声明都移动到你所在函数或代码块的最前面
  // 避免 bits.c:282: parse error
  // dlc 编译器遵循的是比较古老的 C 语言标准（ANSI C / C89 / C90）
  int bit_16, bit_8, bit_4, bit_2, bit_1, bit_0;
  int flag = x >> 31;

  x = ((~flag) & x) | (flag & (~x));
  bit_16 = !!(x >> 16) << 4;

  x = x >> bit_16;
  bit_8 = !!(x >> 8) << 3;

  x = x >> bit_8;
  bit_4 = !!(x >> 4) << 2;

  x = x >> bit_4;
  bit_2 = !!(x >> 2) << 1;

  x = x >> bit_2;
  bit_1 = !!(x >> 1);

  x = x >> bit_1;
  bit_0 = x;

  return bit_16 + bit_8 + bit_4 + bit_2 + bit_1 + bit_0 + 1;
}
// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  // 获取 sign、exp、frac
  unsigned sign = (uf >> 31) & 0x1;
  unsigned exp = (uf >> 23) & 0xff;
  unsigned frac = uf & 0x7fffff;

  // NaN
  if (exp == 0xff) {
    return uf;
  }

  // 非规格化 frac * 2
  if (exp == 0) {
    frac = frac << 1;
    return (sign << 31) | (exp << 23) | frac;
  }

  // 规格化 e + 1
  exp = exp + 1;
  return (sign << 31) | (exp << 23) | frac;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  // 当前版本的 C 语言所有变量定义要提前声明
  //
  // 获取 sign、exp、frac
  unsigned sign = (uf >> 31) & 0x1;
  unsigned exp = (uf >> 23) & 0xff;
  unsigned frac = uf & 0x7fffff;
  // 不能定义为 unsigned, 因为结果可能会是负数
  int E = exp - 0x7fu;

  // printf("ycx debug %u, %u, %u, %d\n", sign, exp, frac, E);

  // NaN and infinity
  // int(f), 1.x << 31 means infinity
  if (exp == 0xff || E >= 31) {
    return 0x80000000u;
  }

  // 非规格化，直接返回 0
  if (exp == 0) {
    return 0;
  }

  // 规格化, 因为 frac 是 23 位, 加上默认的 1
  frac = (0x1 << 23) | frac;

  // 如果 e - Bias 小于 0，此时整数部分一定是 0
  if (E < 0) {
    return 0;
  }
  // 如果 e - Bias 小于 23，说明 frac 无法全部保留
  if (E < 23) {
    frac = frac >> (23 - E);
  } else {
    frac = frac << (E - 23);
  }

  // 正数直接返回
  if (!sign) {
    return frac;
  }
  return -frac;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // 最小表示 2^(-126 - 23), 即非规格化的最小值，0x1
  if (x < (-126 - 23)) {
    return 0;
  }
  // 最大表示 2^127, 即规格化的最大值
  if (x > 127) {
    return 0x7f800000;
  }

  // 处理 2^-149 ~ 2^127
  if (x >= 0) {
    // 2^(e - Bias) -> e = Bias + x
    return (127 + x) << 23;
  }

  return 0;
}
