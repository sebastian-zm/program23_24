#include <stdbool.h>
#include <string.h>
#include "herriak.h"

HERRIAK HERRIAK_add(HERRIAK herriak, char herria[])
{
	int idx = 0;
	int aurkitua = false;
	int min_idx;

	while (!aurkitua && idx < herriak.zero) {
		if (!strcmp(herria, herriak.datuak[idx])) {
			aurkitua = true;
		} else {
			++idx;
		}
	}

	if (idx == herriak.zero) {
		strcpy(herriak.datuak[herriak.zero], herriak.datuak[herriak.bat]);
		strcpy(herriak.datuak[herriak.bat], herria);
		++herriak.zero;
		++herriak.bat;
	} else if (idx >= herriak.lau) {
		if (idx >= herriak.bat) {
			min_idx = herriak.bat;
		} else if (idx >= herriak.bi) {
			min_idx = herriak.bi;
		} else if (idx >= herriak.hiru) {
			min_idx = herriak.hiru;
		} else {
			min_idx = herriak.lau;
		}
		strcpy(herriak.datuak[idx], herriak.datuak[min_idx]);
		strcpy(herriak.datuak[min_idx], herria);

		if (idx >= herriak.bat) {
			++herriak.bat;
		} else if (idx >= herriak.bi) {
			++herriak.bi;
		} else if (idx >= herriak.hiru) {
			++herriak.hiru;
		} else {
			++herriak.lau;
		}
		
	}

	return herriak;
}

HERRIAK HERRIAK_add_zero(HERRIAK herriak, char herria[])
{
	int idx = herriak.bat;
	int aurkitua = false;

	while (!aurkitua && idx < herriak.zero) {
		if (!strcmp(herria, herriak.datuak[idx])) {
			aurkitua = true;
		} else {
			++idx;
		}
	}

	if (idx == herriak.zero) {
		strcpy(herriak.datuak[herriak.zero], herria);
		++herriak.zero;
	}

	return herriak;
}
