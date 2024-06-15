#include <stdio.h>
#include "menu_helper.h"


int MENU_HELPER_menua(int *val, char *aukerak[], int aukerakKop, char *prompt, char *gaizki)
{
    MENU_HELPER_aukerak_eman(aukerak, aukerakKop);
    return MENU_HELPER_aukera_eskatu(val, aukerakKop, prompt, gaizki);
}

void MENU_HELPER_aukerak_eman(char *aukerak[], int aukerakKop)
{
    int i;

    printf("0. Irten\n");
    for (i = 1; i <= aukerakKop; ++i) {
	printf("%d. %s\n", i, aukerak[i - 1]);
    }
}

int MENU_HELPER_aukera_eskatu(int *val, int maxVal, char prompt[], char gaizki[])
{
    char buffer[20];
    int ret, ondo;
    int newVal;
    do {
	puts(prompt);
	ret = !!fgets(buffer, sizeof buffer, stdin);
	ondo = ret && 0 < sscanf(buffer, "%d", &newVal) && 0 <= newVal && newVal <= maxVal;
	if (!ondo) puts(gaizki);
    } while (ret && !ondo);
    if (ret) *val = newVal;
    return ret;
}
