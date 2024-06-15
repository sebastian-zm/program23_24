#include <string.h>
#include <stdio.h>
#include "orokorrak.h"

FILE* fitx_ireki(char fitx_izena[]) {
	FILE* fitx = 0;

	fitx = fopen(fitx_izena, "r");
	if (fitx) {
		printf("%s fitxategia ondo irekia\n\n", fitx_izena);
	}
	else{
		printf("[ERROREA] %s fitxategia ezin izan da zabaldu\n", fitx_izena);
	}

	return fitx;
}
void irakurri_fitx_izena(char fitx_izena[]) {

	printf("Sartu fitxategiaren izena .txt barne\n");
	fgets(fitx_izena, 128, stdin);
	fitx_izena[strlen(fitx_izena) - 1] = '\0';

}
