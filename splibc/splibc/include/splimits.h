##ifndef _SPLIMITS_H_
#define _SPLIMITS_H_

#include <spstddef.h>
#ifdef USE_SPLIBC_AS_STDLIBC
#define CHAR_BIT	8
#define SCHAR_MIN	-128
#define SCHAR_MAX 	127
#define UCHAR_MAX	255
#define CHAR_MIN	0
#define CHAR_MAX 	127
#define MB_LEN_MAX	1 // 定义多字节字符中的最大字节数
#define SHRT_MIN	-32768
#define SHRT_MAX	+32767
#define USHRT_MAX 	65535
#define INT_MIN		-32768
#define INT_MAX		+32767
#define UINT_MAX	65535
#define LONG_MIN	-2147483648
#define LONG_MAX 	+2147483648
#define ULONG_MAX	4294967295
#endif // USE_SPLIBC_AS_STDLIBC

#endif // _SPLIMITS_H_