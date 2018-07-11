#ifndef _SPSTDDEF_H_
#define _SPSTDDEF_H_

/*
	所有实现都应包含头文件，以判断是否作为标准C函数库使用。
*/
// #define USE_SPLIBC_AS_STDLIBC
#ifdef USE_SPLIBC_AS_STDLIBC
#define NULL (void *)0
typedef int ptrdiff_t;
typedef unsigned int size_t;
typedef short wchar_t;
#define offsetof(type, member) ((size_t)((&type) - (&type.member)))
#else
#include <stddef.h>
#endif // USE_SPLIBC_AS_STDLIBC

#endif // _SPSTDDEF_H_
