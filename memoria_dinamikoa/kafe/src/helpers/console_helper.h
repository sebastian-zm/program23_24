#ifndef CONSOLE_HELPER_H
#define CONSOLE_HELPER_H

#include <stddef.h>

void CONSOLE_HELPER_itxaron(char prompt[]);
int CONSOLE_HELPER_string_eskatu(char str[], size_t size, char prompt[]);
int CONSOLE_HELPER_float_eskatu(float *val, char prompt[], char gaizki[]);
int CONSOLE_HELPER_float_tartean_eskatu(float *val, float min, float max, char prompt[], char gaizki[]);
int CONSOLE_HELPER_osoa_eskatu(int *val, char prompt[], char gaizki[]);
int CONSOLE_HELPER_osoa_tartean_eskatu(int *val, int min, int max, char prompt[], char gaizki[]);

#endif
