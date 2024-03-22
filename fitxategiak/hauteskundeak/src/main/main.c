#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filesystem_helper.h"

#define MAX_ALDERDI 30
#define MAX_STR 50
#define MAX_LERRO 400
#define FILE_PATH "assets/db/Caceres.txt"

typedef struct s_ALDERDI {
	char izena[MAX_STR];
	int botoak;
} ALDERDI;

int alderdicmp(const void *p1, const void *p2)
{
	ALDERDI a1 = *(ALDERDI *) p1;
	ALDERDI a2 = *(ALDERDI *) p2;
	int ret = 1;
	if (a1.botoak == a2.botoak) {
		ret = 0;
	} else if (a1.botoak > a2.botoak) {
		ret = -1;
	}

	return ret;
}

int main()
{
	FILESYSTEM_HELPER_cd_base_path();

	ALDERDI alderdiak[MAX_ALDERDI];
	int alderdi_kop = 0;
	int boto_totalak = 0;
	char lerro[MAX_LERRO];
	char *tok;
	int i;
	int herri_boto;

	FILE* fd = fopen(FILE_PATH, "r");
	fgets(lerro, MAX_LERRO, fd);
	lerro[strlen(lerro) - 1] = '\0';

	strtok(lerro, " "); // Id beti dago
	strtok(NULL, " "); // Herria beti dago
	
	while (alderdi_kop < MAX_ALDERDI && (tok = strtok(NULL, " "))) {
		strncpy(alderdiak[alderdi_kop].izena, tok, MAX_STR);
		alderdiak[alderdi_kop].izena[MAX_STR - 1] = '\0';
		alderdiak[alderdi_kop].botoak = 0;
		++alderdi_kop;
	}

	while (fgets(lerro, MAX_LERRO, fd)) {
		strtok(lerro, " "); // Id
		strtok(NULL, " "); // Herria
		for (i = 0; i < alderdi_kop; ++i) {
			tok = strtok(NULL, " ");
			herri_boto = 0;

			sscanf(tok, "%d", &herri_boto);
			alderdiak[i].botoak += herri_boto;
			boto_totalak += herri_boto;
		}
	}

	fclose(fd);

	qsort(alderdiak, alderdi_kop, sizeof(alderdiak[0]), alderdicmp);

	for (i = 0; i < alderdi_kop; ++i) {
		printf("%i-%s %i boto (%f%%)\n", i + 1, alderdiak[i].izena, alderdiak[i].botoak, 100.0 * (double) alderdiak[i].botoak / (double) boto_totalak);
	}


}
