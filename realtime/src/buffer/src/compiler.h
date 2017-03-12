/* prevent double include */
#ifndef COMPILER_H
#define COMPILER_H

#if defined (__BORLANDC__)
#define COMPILER_BORLAND

#elif defined (_MSC_VER)
#define COMPILER_MSVC

#elif defined (__CYGWIN32__)
#define COMPILER_CYGWIN

#elif defined (__MINGW64__) /* this should go before the __MINGW32__ check */
#define COMPILER_MINGW_W64 /* this is the 64 bit version */
#define COMPILER_MINGW

#elif defined (__MINGW32__)
#include <_mingw.h> /* private MinGW header */
#if defined(__MINGW64_VERSION_MAJOR)
#define COMPILER_MINGW_W64 /* this could be either the 32 or 64 bit version */
#define COMPILER_MINGW
#else
#define COMPILER_MINGW_ORG
#define COMPILER_MINGW
#endif

#elif defined (__LCC__)
#define COMPILER_LCC

#else
/* the compiler cannot be determined at compile time */
#error "Unknown compiler - please report this to http://bugzilla.fieldtriptoolbox.org"

#endif

#endif /* COMPILER_H */
