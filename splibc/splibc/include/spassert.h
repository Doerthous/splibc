#ifndef _SPASSERT_H_
#define _SPASSERT_H_

#include <spstddef.h>

#ifdef USE_SPLIBC_AS_STDLIBC
#define assert(ignore) ((void)0)
#endif // USE_SPLIBC_AS_STDLIBC

#endif // _SPASSERT_H_ 