#include <stdio.h>
#include "array_helper.h"
#include "herria.h"

KP1_HELPER_CREATE(
		HERRIAK,
		HERRIA,
		struct HERRIA_s,
		("NOT IMPLEMENTED, some garbage follows: %p\n", (void *) &ins),
		("%d %s %d %d %d %d %d\n", &ins.id, ins.izena, ins.botoak, ins.botoak + 1, ins.botoak + 2, ins.botoak + 3, ins.botoak + 4)
)
