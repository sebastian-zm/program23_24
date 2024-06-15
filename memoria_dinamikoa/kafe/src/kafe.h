#ifndef KAFE_H
#define KAFE_H

#define KAFE_GAIZKI "Ez dizut ulertu. Saiatu berriro."

#include "time_helper.h"

typedef struct KAFE_s {
	TIME_HELPER_DATE data;
	float kiloak;
	float kafeina; // 0-1
} KAFE;


KAFE *KAFE_sortu();
void KAFE_bistaratu(KAFE *);

#endif
