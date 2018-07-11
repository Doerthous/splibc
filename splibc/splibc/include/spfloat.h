##ifndef _SPFLOAT_H_
#define _SPFLOAT_H_

#include <spstddef.h>
#ifdef USE_SPLIBC_AS_STDLIBC

/*
	定义浮点加法的舍入模式，它可以是下列任何一个值：
	   -1 - 无法确定
		0 - 趋向于零
		1 - 去最近的值
		2 - 趋向于正无穷
		3 - 趋向于负无穷
*/
#define FLT_ROUNDS

/*
	定义指数表示的基数。基数 2 表示二进制，基数 10 表示
	十进制，基数 16 表示十六进制。
*/
#define FLT_RADIX 2	

/*
	这些宏定义了 FLT_RADIX 基数中的位数。
*/
#define FLT_MANT_DIG
#define DBL_MANT_DIG
#define LDBL_MANT_DIG

/*
	这些宏定义了舍入后不会改变表示的十进制数字的最大值（基数 10）。
*/
#define FLT_DIG 6
#define DBL_DIG 10
#define LDBL_DIG 10

/*
	这些宏定义了基数为 FLT_RADIX 时的指数的最小负整数值。
*/
#define FLT_MIN_EXP
#define DBL_MIN_EXP
#define LDBL_MIN_EXP

/*
	这些宏定义了基数为 10 时的指数的最小负整数值。
*/
#define FLT_MIN_10_EXP -37
#define DBL_MIN_10_EXP -37
#define LDBL_MIN_10_EXP -37

/*
	这些宏定义了基数为 FLT_RADIX 时的指数的最大整数值。
*/
#define FLT_MAX_EXP
#define DBL_MAX_EXP
#define LDBL_MAX_EXP

/*
	这些宏定义了基数为 10 时的指数的最大整数值。
*/
#define FLT_MAX_10_EXP +37
#define DBL_MAX_10_EXP +37
#define LDBL_MAX_10_EXP +37

/*
	这些宏定义最大的有限浮点值。
*/
#define FLT_MAX 1E+37
#define DBL_MAX 1E+37
#define LDBL_MAX 1E+37

/*
	这些宏定义了可表示的最小有效数字。
*/
#define FLT_EPSILON 1E-5
#define DBL_EPSILON 1E-9
#define LDBL_EPSILON 1E-9

/*
	这些宏定义了最小的浮点值。
*/
#define FLT_MIN 1E-37
#define DBL_MIN 1E-37
#define LDBL_MIN 1E-37

#endif // USE_SPLIBC_AS_STDLIBC
#endif // _SPFLOAT_H_