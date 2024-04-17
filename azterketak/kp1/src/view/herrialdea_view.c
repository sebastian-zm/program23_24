#include <stdio.h>
#include <string.h>
#include "herrialdea.h"
#include "herrialdea_view.h"

HERRIALDEA HERRIALDEA_VIEW_eskatu()
{
	HERRIALDEA herr;

	printf("Eman herrialdearen izena: ");
	fgets(herr.izena, HERRIALDEA_MAX_STR, stdin);
	herr.izena[strlen(herr.izena) - 1] = '\0';

	HERRIALDEA_VIEW_ip_aldatu(herr.ip);

	return herr;
}
void HERRIALDEA_VIEW_ip_aldatu(int ip[])
{
	char ipb[1 /*lerro-jauzia*/ + 1 /*delimitadorea*/ + 3 /*puntu*/ + 3 /*zifra*/ * 4 /*zenbaki*/];

	printf("Eman herrialdearen ip-a (xxx.xxx.xxx.xxx): ");
	fgets(ipb, sizeof(ipb) / sizeof(ipb[0]), stdin);
	sscanf(ipb, "%d.%d.%d.%d\n", &ip[0], &ip[1], &ip[2], &ip[3]);
}

void HERRIALDEA_VIEW_danak_bistaratu(HERRIALDEAK herrk)
{
	int len = HERRIALDEAK_length(herrk);
	HERRIALDEA herr;
	int idx;
	
	for (idx = 0; idx < len; ++idx) {
		herr = HERRIALDEAK_get(herrk, idx);
		HERRIALDEA_VIEW_bistaratu(herr);
	}
}

void HERRIALDEA_VIEW_bistaratu(HERRIALDEA herr)
{
	printf("%s Herrialdea: ip %d.%d.%d.%d;\n", herr.izena, herr.ip[0], herr.ip[1], herr.ip[2], herr.ip[3]);
}

int HERRIALDEA_VIEW_find_by_name(HERRIALDEAK herrk)
{
	char buffer[HERRIALDEA_MAX_STR];

	printf("Eman herrialdearen izena: ");
	fgets(buffer, HERRIALDEA_MAX_STR, stdin);
	buffer[strlen(buffer) - 1] = '\0';
	return HERRIALDEAK_find_by_name(herrk, buffer);
}
