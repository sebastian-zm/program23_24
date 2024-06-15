#ifndef EXIT_HELPER_H
#define EXIT_HELPER_H
#include <stdbool.h>

#define EXIT_HELPER_ENSURE(boolean, ...) \
	do {\
		if (!(boolean)) {\
			fprintf(stderr, __VA_ARGS__);\
			fputs("\n", stderr);\
			exit(EXIT_FAILURE);\
		}\
	} while(0)

void EXIT_HELPER_ensure(bool boolean, char *msg);

#endif
