#ifndef CROCON_PRIV
#define CROCON_PRIV

#ifdef WIN32

	#include <os/win32/crocw32.h>

	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>

#else

	#include <os/unix/crocunix.h>

#endif

#endif
