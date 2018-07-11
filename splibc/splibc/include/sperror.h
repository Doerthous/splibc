#ifndef _SPERROR_H_
#define _SPERROR_H_

#include <spstddef.h>

#ifdef USE_SPLIBC_AS_STDLIBC

#define EDOM
#define ERANGE

extern int errno;

#endif // USE_SPLIBC_AS_STDLIBC

#endif // _SPERROR_H_ 