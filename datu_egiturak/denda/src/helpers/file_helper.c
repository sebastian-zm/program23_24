#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define FILE_HELPER_BUFFER_SIZE 60

char *FILE_HELPER_read_str(FILE * file)
{
	char *ret;
	char *tmp;
	ptrdiff_t azkenera = 0;

	char *fgets_ondo = NULL;
	char *amaitu_da = NULL;

	ret = malloc(FILE_HELPER_BUFFER_SIZE * sizeof(*ret));

	if (ret) {
		fgets_ondo = fgets(ret + azkenera, FILE_HELPER_BUFFER_SIZE, file);
		amaitu_da = strrchr(ret + azkenera, '\n');
	}

	while (ret && fgets_ondo && !amaitu_da) {
		azkenera = strchr(ret + azkenera, '\0') - ret;

		tmp = realloc(ret, sizeof(*ret) * (azkenera + FILE_HELPER_BUFFER_SIZE));

		if (tmp) {
			ret = tmp;
			fgets_ondo = fgets(ret + azkenera, FILE_HELPER_BUFFER_SIZE, file);
			amaitu_da = strrchr(ret + azkenera, '\n');
		} else {
			free(ret);
			ret = NULL;
		}
	}

	if (ret && fgets_ondo && amaitu_da) {
		*amaitu_da = '\0';
	} else if (ret && !fgets_ondo && !feof(file)) {
		// Errorea gertatu da, eta ez da izan EOF.
		free(ret);
		ret = NULL;
	}

	return ret;
}

#endif
