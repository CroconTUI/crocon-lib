#ifndef _CROCON_PRIV
#define _CROCON_PRIV

#include <stdarg.h>

#ifdef WIN32
	#include <os/win32/crocw32.h>
#else
	#include <os/unix/crocunix.h>
#endif

#endif
