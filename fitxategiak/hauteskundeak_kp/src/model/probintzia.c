#include <limits.h>
#include <string.h>
#include "array_helper.h"
#include "probintzia.h"

ARRAY_HELPER_CREATE_ARRAY(PROBINTZIAK_BOTOAK, PROBINTZIA_BOTOAK, PROBINTZIA_MAX_PROBINTZIA)

PROBINTZIA_BOTOAK PROBINTZIA_BOTOAK_read(char izena[])
{
	PROBINTZIA_BOTOAK pbk;
	char filename[PATH_MAX];
	FILE* fp;

	strncpy(pbk.izena, izena, PROBINTZIA_MAX_STR);
	strncpy(filename, izena, PATH_MAX);
	strncat(filename, ".txt", PATH_MAX - 1 - strlen(filename));
	filename[PATH_MAX - 1] = '\0'
	fp = fopen(filename)

	if (fp) {
		while (fscanf())

		fclose(fp);
	}
}
