#ifndef _SPSTDLIB_H_
#define _SPSTDLIB_H_ 

#include <spstddef.h>

double spatof(const char *str);
int spatoi(const char *str);
long int spatol(const char *str);
double spstrtod(const char *str, char **endptr);
long int spstrtol(const char *str, char **endptr, int base);
unsigned long int spstrtoul(const char *str, char **endptr, int base);

void *	spbsearch(const void *key, const void *base, size_t nitems, 
				size_t size, int (*compar)(const void *, const void *));
void spqsort(void *base, size_t nitems, size_t size, 
			int (*compar)(const void *, const void*));

int spabs(int x);
long int splabs(long int x);

#ifdef USE_SPLIBC_AS_STDLIBC
#define atof(str)									spatof(str)	
#define atoi(str)									spatoi(str)
#define atol(str)									spatol(str)
#define strtod(str, endptr)							spstrtod(str, endptr)
#define strtol(str, endptr, base) 					spstrtol(str, endptr, base)
#define strtoul(str, endptr, base)					spstrtoul(str, endptr, base)
#define bsearch(key, base, nitems, size, compar)	spbsearch(key, base, nitems, size, compar)
#define qsort(base, nitems, size, compar)			spqsort(base, nitems, size, compar)
#define abs(x)										spabs(x)
#define labs(x)										splabs(x)
#endif // USE_SPLIBC_AS_STDLIBC

#endif // _SPSTDLIB_H_