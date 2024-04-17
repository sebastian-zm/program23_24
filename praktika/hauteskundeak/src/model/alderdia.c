#include "herria.h"
#include "alderdia.h"

int ALDERDIAK_cmp(const void *a1, const void *a2)
{
	int ret;
	ALDERDIA *al1 = (ALDERDIA *) a1;
	ALDERDIA *al2 = (ALDERDIA *) a2;

	if (al1->botoak > al2->botoak) {
		ret = 1;
	} else if (al1->botoak < al2->botoak) {
		ret = -1;
	} else {
		ret = 0;
	}
	return ret;
}

void ALDERDIAK_ini(ALDERDIA alderdiak[])
{
	for (int i = 0; i < 5; ++i) {
		alderdiak[i].botoak = 0;
	}
}

void ALDERDIAK_irakurri(FILE* fp, ALDERDIA alderdiak[])
{
	fscanf(fp, "Id Herria %s %s %s %s %s\n", alderdiak[0].izena, alderdiak[1].izena, alderdiak[2].izena, alderdiak[3].izena, alderdiak[4].izena);
}

void ALDERDIAK_bozkatu(ALDERDIA alderdiak[], HERRIAK herrk)
{
	size_t i;
	int j;
	for (i = 0; i < herrk.length; ++i) {
		for (j = 0; j < 5; ++j) {
			alderdiak[j].botoak += herrk.data[i].botoak[j];
		}
	}
}

void ALDERDIAK_idatzi(FILE* fp, ALDERDIA alderdiak[])
{
	int i;
	for (i = 0; i < 5; ++i) {
		fprintf(fp, "%s %d boto\n", alderdiak[i].izena, alderdiak[i].botoak);
	}
}

void ALDERDIAK_idatzi_orden(FILE* fp, ALDERDIA alderdiak[])
{
	int botoak = 0;
	int i;
	for (i = 0; i < 5; ++i) {
		botoak += alderdiak[i].botoak;
	}
	for (i = 0; i < 5; ++i) {
		fprintf(fp, "%d-%s %d boto (%d%%)\n", i + 1, alderdiak[i].izena, alderdiak[i].botoak, (int) (100.0 / botoak * alderdiak[i].botoak));
	}
}
