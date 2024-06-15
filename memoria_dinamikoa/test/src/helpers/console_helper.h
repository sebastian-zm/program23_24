#ifndef CONSOLE_HELPER_H
#define CONSOLE_HELPER_H

void CONSOLE_HELPER_itxaron(char prompt[]);
int CONSOLE_HELPER_string_eskatu(char str[], size_t size, char prompt[]);
int CONSOLE_HELPER_osoa_eskatu(int *val, char prompt[], char gaizki[]);
int CONSOLE_HELPER_aukera_eskatu(int *val, int max, char prompt[], char gaizki[]);

#endif
