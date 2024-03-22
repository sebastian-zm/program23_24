#include <stdio.h>		//fopen , fprint, fgets
#include "ikasle.h"

int main()
{
	int ikop = 0;
	IKASLE ikasleak[MAX_IKASLE];

	ikop = irakurri_fitxategitik_ikasleak_fscanf(ikasleak, ikop, "assets/db/notak.txt");
	bistaratu_ikasleak(ikasleak, ikop);

	printf("Agur...\n");
}
