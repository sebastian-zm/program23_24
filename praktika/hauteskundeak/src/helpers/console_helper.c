#ifndef CONSOLE_HELPER_H
#define CONSOLE_HELPER_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

void CONSOLE_HELPER_itxaron(char prompt[])
{
	printf("%s", prompt);
	getc(stdin);
	system("clear");
}

int CONSOLE_HELPER_string_eskatu(char str[], size_t size, char prompt[])
{
    puts(prompt);
    return !!fgets(str, size, stdin);
}

int CONSOLE_HELPER_osoa_eskatu(int *val, char prompt[], char gaizki[])
{
    char buffer[20];
    int ret, ondo;
    printf("%s", prompt);
    do {
	ret = !!fgets(buffer, sizeof buffer, stdin);
	ondo = ret && 0 < sscanf(buffer, "%d", val);
	if (!ondo) puts(gaizki);
    } while (ret && !ondo);
    return ret;
}

int CONSOLE_HELPER_aukera_eskatu(int *val, int max, char prompt[], char gaizki[])
{
    char buffer[20];
    int ret, ondo;
    printf("%s", prompt);
    do {
	ret = !!fgets(buffer, sizeof buffer, stdin);
	ondo = ret && 0 < sscanf(buffer, "%d", val) && (*val > max || 0 > *val);
	if (!ondo) puts(gaizki);
    } while (ret && !ondo);
    return ret;
}

#endif
