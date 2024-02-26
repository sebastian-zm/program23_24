#include <stdbool.h>
#include <stdlib.h>
#include "array_helper.h"
#include "ibilbidea.h"

ARRAY_HELPER_CREATE_ARRAY(IBILBIDEAK, IBILBIDEA, IBILBIDEA_MAX_IBILBIDEAK)

int IBILBIDEA_belongs_to_user(IBILBIDEA i, USER user)
{
	return i.user_id == user.id;
}

int IBILBIDEAK_aurkitu_id(IBILBIDEAK ibik, int id)
{
	int len = IBILBIDEAK_length(ibik);
	bool aurkitua = false;
	int i = 0;
	IBILBIDEA ibi;

	while (!aurkitua && i < len) {
		ibi = IBILBIDEAK_get(ibik, i);
		aurkitua = ibi.id == id;
		if (!aurkitua) ++i;
	}

	if (i >= len) i = -1;

	return i;
}

int IBILBIDEA_id_sortu(IBILBIDEAK ibik)
{
	int id;

	do {
		id = rand();
	} while (IBILBIDEAK_aurkitu_id(ibik, id) >= 0);

	return id;
}
