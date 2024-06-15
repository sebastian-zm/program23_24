#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>//malloc
#include <string.h>

#include "menua.h"
#include "jarraitzailea.h"
#include "teklak.h"
#include "bluetooth.h"
#include "mugimendu_aurrekonfig.h"
#include "floyd_warshall.h"

int main(void)
{
	floyd_warshall_nagusia();
}
