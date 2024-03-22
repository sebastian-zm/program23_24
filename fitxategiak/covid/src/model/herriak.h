#ifndef HERRIAK_H
#define HERRIAK_H

#include "gaixoa.h"

#define HERRIAK_MAX 200

typedef struct s_HERRIAK {
	char datuak[HERRIAK_MAX][GAIXOA_MAX_STR];
	int lau;
	int hiru;
	int bi;
	int bat;
	int zero;
} HERRIAK;

HERRIAK HERRIAK_add(HERRIAK herriak, char herria[]);
HERRIAK HERRIAK_add_zero(HERRIAK herriak, char herria[]);

#endif
