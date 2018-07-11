#include <spstdio.h>


/*
	次函数转由底层函数实现
*/
#ifdef USE_SPLIBC_AS_STDLIBC
#define __spputchar(ch)  // 此函数转由底层函数实现
#else
#include <stdio.h>
#define __spputchar(ch) putchar(ch)
#endif

int spputchar(int ch) {
	__spputchar(ch);
}
int spputs(const char *str) {
	for (; *str; ++str) {
		spputchar(*str);
	}
}