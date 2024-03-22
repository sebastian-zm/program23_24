#include <stdio.h>
#include "elur_datu.h"
#include "elur_datu_view.h"

void ELUR_DATU_VIEW_datuak_ikusi(ELUR_DATUAK datuak)
{
	for (int i = 0; i < datuak.len; ++i) {
		printf("herria: %s, elurra: %f\n", datuak.arr[i].herria, datuak.arr[i].elurra);
	}
}
