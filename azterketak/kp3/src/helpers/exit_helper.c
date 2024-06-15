#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "exit_helper.h"


void EXIT_HELPER_ensure(bool boolean, char *msg)
{
	if (!boolean) {
		fprintf(stderr, "%s\n", msg);
		exit(EXIT_FAILURE);
	}
}
