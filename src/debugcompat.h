
#ifndef __DEBUGCOMPAT_H__
#define __DEBUGCOMPAT_H__ 1

#ifdef DEBUG
#include <stdio.h>

extern void debugPrint(const char *x);
extern void debugPrint(const float x);
extern void debugPrintln(const char *x);
extern void debugPrintln(const unsigned int x);

#ifdef ARDUINO
extern unsigned int __bss_end;
extern unsigned int __heap_start;
extern void *__brkval;

uint16_t getFreeSram();

#else
// NOT Arduino

#endif

#else

#define debugPrint(x)
#define debugPrintln(x)

#endif


#endif
