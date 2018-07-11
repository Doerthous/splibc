#ifndef _SPCTYPE_H_
#define _SPCTYPE_H_

#include <spstddef.h>

int spisalnum(int c);
int spisalpha(int c);
int spiscntrl(int c);
int spisdigit(int ch);
int spisgraph(int ch);
int spislower(int ch);
int spisupper(int ch);
int spisprint(int ch);
int spispunct(int ch);
int spisspace(int ch);
int spisxdigit(int c);
int sptolower(int ch);
int sptoupper(int ch);

#ifdef USE_SPLIBC_AS_STDLIBC

#define isalnum(ch) spisalnum(ch)
#define isalpha(ch) spisalpha(ch)
#define iscntrl(ch) spiscntrl(ch)
#define isdigit(ch) spisdigit(ch)
#define isgraph(ch) spisgraph(ch)
#define islower(ch) spislower(ch)
#define isupper(ch) spisupper(ch)
#define isprint(ch) spisprint(ch)
#define ispunct(ch) spispunct(ch)
#define isspace(ch) spisspace(ch)
#define isxdigit(ch) spisxdigit(ch)
#define tolower(ch) sptolower(ch)
#define toupper(ch) sptoupper(ch)

#endif // USE_SPLIBC_AS_STDLIBC

#endif // _SPCTYPE_H_