#include <stdio.h>
#include <stdlib.h>
#include "filesystem_helper.h"
#include "array_funcs_helper.h"
#include "alderdia.h"
#include "herria.h"

#define CACERES_PATH "assets/db/Caceres.txt"
#define BADAJOZ_PATH "assets/db/Badajoz.txt"
#define ARIKETA1_PATH "assets/results/ariketa1.txt"
#define ARIKETA2_PATH "assets/results/ariketa1.txt"

int main() {

	FILESYSTEM_HELPER_cd_base_path();
	ALDERDIA alderdiak[5];
	int i;

	FILE* fps[2] = {
		fopen(CACERES_PATH, "r"),
		fopen(BADAJOZ_PATH, "r")
	};

	HERRIAK herrkk[2];

	ALDERDIAK_ini(alderdiak);

	for (i = 0; i < 2; ++i) {
		ALDERDIAK_irakurri(fps[i], alderdiak); // Berdin dio gainean idaztea
		herrkk[i] = HERRIAK_scan(fps[i]);
		fclose(fps[i]);
	}
	for (i = 0; i < 2; ++i) {
		ALDERDIAK_bozkatu(alderdiak, herrkk[i]);
	}

	FILE *ariketa1 = fopen(ARIKETA1_PATH, "w");

	ALDERDIAK_idatzi(ariketa1, alderdiak);
	ALDERDIAK_idatzi(stdout, alderdiak);

	fclose(ariketa1);

	ARRAY_FUNCS_HELPER_sort_desc(alderdiak, 5, sizeof alderdiak[0], ALDERDIAK_cmp);

	FILE *ariketa2 = fopen(ARIKETA1_PATH, "w");

	ALDERDIAK_idatzi_orden(ariketa2, alderdiak);
	ALDERDIAK_idatzi_orden(stdout, alderdiak);

	fclose(ariketa2);

	return 0;
}
