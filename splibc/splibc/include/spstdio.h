#ifndef _SPSTDIO_H_
#define _SPSTDIO_H_

#include <spstddef.h>
#include <spstdarg.h>

int spprintf(const char *fmt, ...);
int spsnprintf(char *str, size_t size, const char *fmt, ...);
int spputchar(int ch);
int spputs(const char *str);

#ifdef USE_SPLIBC_AS_STDLIBC

// C99 standard
#define printf(fmt, ...)				spprintf(fmt, __VA_ARGS__)
#define snprintf(str, size, fmt, ...) 	spsnprintf(str, size, fmt, __VA_ARGS__) 
#define putchar(ch)						spputchar(ch)
#define puts(str)						spputs(str)

#endif // USE_SPLIBC_AS_STDLIBC

#endif // _SPSTDIO_H_