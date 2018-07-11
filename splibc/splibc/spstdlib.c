#include <spstdlib.h>

#define spatointeger(str, type, ipt) \
	const char *end = str; \
	for (; *end; ++end); \
	type oi = 0, a = 1; \
	*ipt = 0; \
	do { \
		--end; \
		oi = *ipt; \
		*ipt += a * (*end - '0'); \
		if (oi > *ipt) { /* overflow */ \
			return 0; \
		} \
		a *= 10; \
	} while (end != str); 

/*
	把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型）。
*/
double spatof(const char *str) {}

/*	
	把参数 str 所指向的字符串转换为一个整数（类型为 int 型）。
	该函数返回转换后的长整数，如果没有执行有效的转换，则返回零。
*/
int spatoi(const char *str) {
	int i = 0;
	spatointeger(str, int, &i);
	return i;
}

/*
	把参数 str 所指向的字符串转换为一个长整数（类型为 long int 型）。
*/
long int spatol(const char *str) {
	int i = 0;
	spatointeger(str, long int, &i);
	return i;
}

/*
	把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型）。
*/
double spstrtod(const char *str, char **endptr) {}

/*
	把参数 str 所指向的字符串转换为一个长整数（类型为 long int 型）。
*/
long int spstrtol(const char *str, char **endptr, int base) {}

/*
	把参数 str 所指向的字符串转换为一个无符号长整数（类型为 unsigned long int 型）。
*/
unsigned long int spstrtoul(const char *str, char **endptr, int base) {}

/*
	执行二分查找。
*/
void *	spbsearch(const void *key, const void *base, size_t nitems, 
				size_t size, int (*compar)(const void *, const void *)) {}

/*
	快排
*/
void spqsort(void *base, size_t nitems, size_t size, 
			int (*compar)(const void *, const void*)) {}



/*
	返回 x 的绝对值。
*/
int spabs(int x) {
	return (int)splabs(x);
}

/*
	返回 x 的绝对值。
*/
long int splabs(long int x) {
	if (x < 0) { 
		x = -x; 
	}
	return x;
}