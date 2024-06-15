#include <stdlib.h>
#include "bidaia.h"
#include "igogailua.h"

IGOGAILUA *IGOGAILUA_sortu()
{
	BIDAIA *bidaia;
	LIST_HELPER_NODE *bidaiak;
	IGOGAILUA *igogailua;

	bidaia = BIDAIA_hasiera();
	LIST_HELPER_create(&bidaiak, bidaia, NULL);

	igogailua = malloc(sizeof *igogailua);
	igogailua->id = 0;
	igogailua->bidaiak = bidaiak;

	return igogailua;
}

void IGOGAILUA_free(void *ig)
{
	IGOGAILUA *igogailua = ig;
	LIST_HELPER_free(igogailua->bidaiak, free);
	free(ig);
}

LIST_HELPER_NODE *IGOGAILUAK_sortu()
{
	IGOGAILUA *igogailua;
	LIST_HELPER_NODE *ret = NULL;
	int i;
	for (i = 1; i <= IGOGAILU_KOP; ++i) {
		igogailua = IGOGAILUA_sortu();
		igogailua->id = i;
		LIST_HELPER_create(&ret, igogailua, ret);
	}
	return ret;
}

int IGOGAILUA_has_this_id(void *igogailua, void *id)
{
	IGOGAILUA *igogailua1 = igogailua;
	int *id1 = id;

	return igogailua1->id == *id1;
}
