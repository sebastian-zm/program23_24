#ifndef HELPERS_CONSOLE_H
#define HELPERS_CONSOLE_H

#include <string.h>
#include <stdio.h>

#define HELPERS_CONSOLE_BUFFER_SIZE 60

void HELPERS_CONSOLE_return_amaitzeko()
{
	fprintf(stdout, "Sakatu return amaitzeko...\n");
	getc(stdin);
}

void HELPERS_CONSOLE_eskatu_str(char *buffer, int n)
{
	fgets(buffer, n, stdin);
	buffer[strlen(buffer) - 1] = '\0';
}

char *HELPERS_CONSOLE_stringEskatu(char *prompt)
{
	char *ret;
	char *tmp;
	ptrdiff_t azkenera = 0;

	char *fgets_ondo = NULL;
	char *amaitu_da = NULL;

	printf("%s", prompt);

	ret = malloc(HELPERS_CONSOLE_BUFFER_SIZE * sizeof(*ret));

	if (ret) {
		fgets_ondo =
		    fgets(ret + azkenera, HELPERS_CONSOLE_BUFFER_SIZE,
			  stdin);
		amaitu_da = strrchr(ret + azkenera, '\n');
	}

	while (ret && fgets_ondo && !amaitu_da) {
		azkenera = strchr(ret + azkenera, '\0') - ret;

		tmp =
		    realloc(ret,
			    sizeof(*ret) * (azkenera +
					    HELPERS_CONSOLE_BUFFER_SIZE));

		if (tmp) {
			ret = tmp;
			fgets_ondo =
			    fgets(ret + azkenera,
				  HELPERS_CONSOLE_BUFFER_SIZE, stdin);
			amaitu_da = strrchr(ret + azkenera, '\n');
		} else {
			free(ret);
			ret = NULL;
		}
	}

	if (ret && fgets_ondo && amaitu_da) {
		*amaitu_da = '\0';
	} else if (ret && !fgets_ondo && !feof(stdin)) {
		// Errorea gertatu da, eta ez da izan EOF.
		free(ret);
		ret = NULL;
	}

	return ret;
}

#endif
