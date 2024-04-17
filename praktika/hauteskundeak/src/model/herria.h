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
		struct HERRIA_s,
		("NOT IMPLEMENTED %p", &ins),
		("%d %s %d %d %d %d %d\n", &ins.id, ins.izena, ins.botoak, ins.botoak + 1, ins.botoak + 2, ins.botoak + 3, ins.botoak + 4)
)

#endif
