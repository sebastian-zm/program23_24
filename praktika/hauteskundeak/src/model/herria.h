#ifndef HERRIA_H
#define HERRIA_H

#include "kp1_helper.h"
#include <stdio.h>

#define HERRIA_MAX_STR 64
#define HERRIAK_MAX 20

typedef struct HERRIA_s {
	int id;
	char izena[HERRIA_MAX_STR];
	int botoak[5];
} HERRIA;

KP1_HELPER_CREATE_HEADER(
		HERRIAK,
		HERRIA,
		struct HERRIA_s
)

#endif
