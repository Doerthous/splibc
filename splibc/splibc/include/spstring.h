#ifndef _SPSTRING_H_
#define _SPSTRING_H_

#include <spstddef.h>

void *spmemchr(const void *str, int c, size_t n);
int   spmemcmp(const void *str1, const void *str2, size_t n);
void *spmemcpy(void *dest, const void *src, size_t n);
void *spmemset(void *str, int c, size_t n);
void *spmemmove(void *dest, const void *src, size_t n);

size_t spstrlen(const char * str);
char *spstrcpy(char * dest, const char * src);
char *spstrncpy(char * dest, const char * src, size_t n);
int spstrcmp(const char *str1, const char *str2);
int spstrncmp(const char *str1, const char *str2, size_t n);


#ifdef USE_SPLIBC_AS_STDLIBC

#define memchr(str, c, n) 		spmemchr(str, c, n) 
#define memcmp(str1, str2, n)	spmemcmp(str1, str2, n)
#define memcpy(dest, src, n)	spmemcpy(dest, src, n)
#define memset(str, c, n)		spmemset(str, c, n)
#define memmove(dest, src, n) 	spmemmove(dest, src, n)

#define strlen(str)				spstrlen(str)
#define strcpy(dest, src)		spstrcpy(dest, src)
#define strncpy(dest, src, n)	spstrncpy(dest, src, n)
#define strcmp(str1, str2)		spstrcmp(str1, str2)
#define strncmp(str1, str2, n)	spstrncmp(str1, str2, n)

#endif // USE_SPLIBC_AS_STDLIBC

/*
	非标准库部分
*/
/*
	倒置字符数组（字符串）
*/
void strrsv(char *str);

#endif // _SPSTRING_H_ 