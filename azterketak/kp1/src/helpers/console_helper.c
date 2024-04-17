#ifndef CONSOLE_HELPER_H
#define CONSOLE_HELPER_H

#include <stdio.h>

void CONSOLE_HELPER_itxaron(char prompt[])
{
	printf("%s", prompt);
	getc(stdin);
}

#endif
