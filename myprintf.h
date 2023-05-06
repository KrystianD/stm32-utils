#ifndef __PRINTF_H__
#define __PRINTF_H__

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif
extern void myputchar(int c);
#ifdef __cplusplus
}
#endif

int myprintf(const char *format, ...);
int myvprintf(const char *format, va_list args);
int mysprintf(char *out, const char *format, ...);
void printfloat(float val);

#endif
