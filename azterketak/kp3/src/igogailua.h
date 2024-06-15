#ifndef IGOGAILUA_H
#define IGOGAILUA_H

#define IGOGAILU_KOP 3

#include "list_helper.h"

typedef struct IGOGAILUA_s {
	int id;
	LIST_HELPER_NODE *bidaiak;
} IGOGAILUA;

LIST_HELPER_NODE *IGOGAILUAK_sortu();
int IGOGAILUA_has_this_id(void *igogailua, void *id);
void IGOGAILUA_free(void *ig);
#endif
