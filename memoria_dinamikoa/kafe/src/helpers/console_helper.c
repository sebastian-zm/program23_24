#ifndef CONSOLE_HELPER_H
#define CONSOLE_HELPER_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void CONSOLE_HELPER_itxaron(char prompt[])
{
    printf("%s", prompt);
    getc(stdin);
    system("clear");
}

int CONSOLE_HELPER_string_eskatu(char str[], size_t size, char prompt[])
{
    int ret;
    puts(prompt);
    ret = !!fgets(str, size, stdin);
    *strrchr(str, '\n') = '\0';

    return ret;
}

int CONSOLE_HELPER_float_eskatu(float *val, char prompt[], char gaizki[])
{
    char buffer[20];
    int ret, ondo;
    do {
	puts(prompt);
	ret = !!fgets(buffer, sizeof buffer, stdin);
	ondo = ret && 0 < sscanf(buffer, "%f", val);
	if (!ondo) puts(gaizki);
    } while (ret && !ondo);
    return ret;
}

int CONSOLE_HELPER_float_tartean_eskatu(float *val, float min, float max, char prompt[], char gaizki[])
{
    char buffer[20];
    int ret, ondo;
    do {
	puts(prompt);
	ret = !!fgets(buffer, sizeof buffer, stdin);
	ondo = ret && 0 < sscanf(buffer, "%f", val) && min <= *val && *val <= max;
	if (!ondo) puts(gaizki);
    } while (ret && !ondo);
    return ret;
}

int CONSOLE_HELPER_osoa_eskatu(int *val, char prompt[], char gaizki[])
{
    char buffer[20];
    int ret, ondo;
    do {
	puts(prompt);
	ret = !!fgets(buffer, sizeof buffer, stdin);
	ondo = ret && 0 < sscanf(buffer, "%d", val);
	if (!ondo) puts(gaizki);
    } while (ret && !ondo);
    return ret;
}


int CONSOLE_HELPER_osoa_tartean_eskatu(int *val, int min, int max, char prompt[], char gaizki[])
{
    char buffer[20];
    int ret, ondo;
    do {
	puts(prompt);
	ret = !!fgets(buffer, sizeof buffer, stdin);
	ondo = ret && 0 < sscanf(buffer, "%d", val) && min <= *val && *val <= max;
	if (!ondo) puts(gaizki);
    } while (ret && !ondo);
    return ret;
}

#endif
