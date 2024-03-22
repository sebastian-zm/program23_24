#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "ordenagailuak_burualdea.h"


int main(void)
{
	ESKAERA eskaeraZerrenda[MAX_ORDENAGAILU];
	BEZEROA bezeroZerrenda[MAX_BEZERO];
	int eskaeraKop, bezeroKop;
	int aukera;

	eskaeraKop = eskaerakFitxategitikIrakurri(eskaeraZerrenda);
	bezeroKop = bezeroZerrendaIrakurri(bezeroZerrenda);
	printf("%d eskaera irakurri dira,\n", eskaeraKop);
	printf("bezero kopurua = %d\n", bezeroKop);

	do
	{
		aukera = menua();
		{
			switch (aukera)
			{
			case 1:
				eskaeraKop = eskaeraBerriBatGehitu(eskaeraZerrenda, eskaeraKop);
				printf("eskaera kopurua =%d\n", eskaeraKop);
				break;

			case 2:
				eskaeraModifikatu(eskaeraZerrenda, eskaeraKop);
				break;
			case 3:
				eskaeraGuztiakBistaratu(eskaeraZerrenda, eskaeraKop);
				break;
			case 4:
				bezeroGuztiakBistaratu(bezeroZerrenda, bezeroKop);
				break;
			case 5:
				produkzioakBezerokaKalkulatu(eskaeraZerrenda, eskaeraKop, bezeroZerrenda, bezeroKop);
			}
		}
	} while (aukera != 0);

	//fabrikazioAginduaSortu(eskaeraZerrenda, eskaeraKop);

	return 0;
}