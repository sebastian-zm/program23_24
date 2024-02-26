#ifndef TEST_ONDARE_H
#define TEST_ONDARE_H

#include <stdint.h>
#include "user.h"

struct Ondare {
	int64_t zentimoak;
	char* izena;
};

void ONDARE_logeatu_erosketa(struct Ondare ondare, struct User user);

#endif // TEST_ONDARE_H
