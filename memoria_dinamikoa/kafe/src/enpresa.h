#ifndef ENPRESA_H
#define ENPRESA_H

#include <stdlib.h>
#include "list_helper.h"
#include "console_helper.h"

#define ENPRESA_MAX_STR 60

typedef struct ENPRESA_s {
	char izena[ENPRESA_MAX_STR];
	LIST_HELPER_NODE *ekoizpena;
} ENPRESA;

ENPRESA *ENPRESA_sortu()
{
	ENPRESA* enp = malloc(sizeof *enp);
	CONSOLE_HELPER_string_eskatu(enp->izena, ENPRESA_MAX_STR, "Eman izena: ");
	enp->ekoizpena = NULL;
	return enp;
}

ENPRESA *ENPRESA_bistaratu()
{
	ENPRESA* enp = malloc(sizeof *enp);
	CONSOLE_HELPER_string_eskatu(enp->izena, ENPRESA_MAX_STR, "Eman izena: ");
	enp->ekoizpena = NULL;
	return enp;
}

#endif
