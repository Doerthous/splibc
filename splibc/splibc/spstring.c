#include <spstring.h>

void *spmemchr(const void *str, int c, size_t n) {}
int   spmemcmp(const void *str1, const void *str2, size_t n) {}

/*	
	从存储区 src 复制 n 个字符到存储区 dest。

	返回一个指向目标存储区 dest 的指针。
*/
void *spmemcpy(void *dest, const void *src, size_t n) {
	char *d = (char *)dest;
	const char *s = (const char *)src;
	for (size_t i = 0; i < n; ++i) {
		d[i] = s[i];
	}
	return dest;
}

/*
	复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符。

	返回指向存储区 str 的指针。
*/
void *spmemset(void *str, int c, size_t n) {
	char *p = (char *)str;
	char *q = (char *)str;
	while (p - q != n) {
		*p = (char)c;
		++p;
	}
	return str;
}
void *spmemmove(void *dest, const void *src, size_t n) {}

/*
	计算字符串 str 的长度，直到空结束字符，但不包括空结束字符'\0'。

	返回字符串 str 的长度。
*/
size_t spstrlen(const char * str) {
	const char *p = str;
	for (; *p; ++p);
	return p - str;
}

/*
	把 src 所指向的字符串复制到 dest。

	返回一个指向最终的目标字符串 dest 的指针。
*/
char *spstrcpy(char * dest, const char *src) { // to 大小问题
	size_t len = spstrlen(src);
	for (size_t i = 0; i < len; ++i) {
		dest[i] = src[i];
	}
	dest[len] = 0;
	return dest;
}

/*
	把 src 所指向的字符串复制到 dest，最多复制 n 个字符。
	当 src 的长度小于 n 时，dest 的剩余部分将用空字节填充。

	返回一个指向最终的目标字符串 dest 的指针。
*/
char *spstrncpy(char * dest, const char *src, size_t n) { // to 大小问题
	size_t len = spstrlen(src);
	size_t i = 0;
	for (; i < len && i < n; ++i) {
		dest[i] = src[i];
	}
	for (; i < n; ++i) {
		dest[i] = 0;
	}
	dest[n] = 0;
	return dest;
}

int spstrcmp(const char *str1, const char *str2) {
	for (; *str1 && *str2; ++str1, ++str2){
		if(*str1 != *str2) {
			return *str1 - *str2;
		}
	}
	if (*str1 && !*str2) {
		return 1;
	}
	if (!*str1 && *str2) {
		return -1;
	}
	return 0;
}

int spstrncmp(const char *str1, const char *str2, size_t n){
	for (; *str1 && *str2 && n; ++str1, ++str2, --n){
		if(*str1 != *str2) {
			return *str1 - *str2;
		}
	}
	if (*str1 && !*str2) {
		return 1;
	}
	if (!*str1 && *str2) {
		return -1;
	}
	return 0;
}

void spstrrsv(char * str)
{
	size_t i, j = spstrlen(str)-1;
	char t;
	for (i = 0; i < j; ++i, --j){
		t = str[i];
		str[i] = str[j];
		str[j] = t;
	}
}