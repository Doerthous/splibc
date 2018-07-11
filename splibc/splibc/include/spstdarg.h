#ifndef _SPSTDARG_H_
#define _SPSTDARG_H_

#include <spstddef.h>

typedef const char *va_list;

#define va_start(LIST, ARG)	LIST = (va_list)&ARG
#define va_end(LIST)        LIST = NULL
#define va_arg(LIST, TYPE)	*(TYPE *)(LIST+=sizeof(TYPE))

#endif // _SPSTDARG_H_
