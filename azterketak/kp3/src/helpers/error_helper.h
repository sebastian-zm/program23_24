#ifndef ERROR_HELPER_H
#define ERROR_HELPER_H

#include <stdio.h>
#include <stdlib.h>

#define ERROR_HELPER(cond, ...) \
	do {\
		if (!(cond)) {\
			fprintf(stderr, __VA_ARGS__);\
			exit(EXIT_FAILURE);\
		}\
	} while (0)

#endif
