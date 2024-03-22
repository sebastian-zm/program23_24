#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "ordenagailuak_burualdea.h"


int eskaerakFitxategitikIrakurri(ESKAERA eskaeraZerrenda[])
{
	int i = 0;
	int irakurritakoak = 0;
	FILE* fp;

	if ((fp = fopen("eskaerak.txt", "r")) == NULL) printf("Ez da fitxategia aurkitu\n");
	else
	{
		do {
			irakurritakoak = fscanf(fp, "%d %s %d %d ",
				&eskaeraZerrenda[i].id,
				eskaeraZerrenda[i].mota,
				&eskaeraZerrenda[i].kopurua,
				&eskaeraZerrenda[i].bezeroaId);
			if (irakurritakoak != EOF) i++;
		} while (irakurritakoak != EOF);

		fclose(fp);
	}
	return i;

}

int menua()
{
	int auk = 0;
	char str[MAX_STR];

	do {
		printf("Ordenagailu eskaerak kudeatzeko menua...\n");
		printf("1- Eskaera berri bat gehitu.\n");
		printf("2- Eskaera bat modifikatu.\n");
		printf("3- Eskaera guztiak bistaratu.\n");
		printf("4- Bezeroak bistaratu.\n");
		printf("5-Fakturak sortu.\n");
		printf("0.-Irteteko\n");
		fgets(str, MAX_STR, stdin);
		sscanf(str, "%d", &auk);
	} while (auk < 0 || auk>5);

	return auk;
}

int eskaeraBerriBatGehitu(ESKAERA eskaeraZerrenda[], int kop)
{
	char str[10];

	eskaeraZerrenda[kop].id = kop + 1;
	printf("Sartu ordenagailu mota:");
	fgets(str, 4, stdin);
	str[strlen(str)-1]='\0';
	strcpy(eskaeraZerrenda[kop].mota, str);
	printf("Sartu fabrikatu beharreko ordenagailu kopurua:");
	fgets(str, 8, stdin);
	sscanf(str, "%d", &eskaeraZerrenda[kop].kopurua);
	printf("Sartu bezeroaren ID-a:");
	fgets(str, 8, stdin);
	sscanf(str, "%d", &eskaeraZerrenda[kop].bezeroaId);
	kop++;
	return (kop);
}

void fabrikazioAginduaSortu(ESKAERA eskaeraZerrenda[], int eskaeraKop)
{
	FILE* fp;
	int i = 0, i3 = 0, i5 = 0, i7 = 0, i9 = 0;


	for (i = 0; i < eskaeraKop; i++)
	{
		if (strcmp(eskaeraZerrenda[i].mota, "i3") == 0) i3 = i3 + eskaeraZerrenda[i].kopurua;
		else if (strcmp(eskaeraZerrenda[i].mota, "i5") == 0) i5 = i5 + eskaeraZerrenda[i].kopurua;
		else if (strcmp(eskaeraZerrenda[i].mota, "i7") == 0) i7 = i7 + eskaeraZerrenda[i].kopurua;
		else if (strcmp(eskaeraZerrenda[i].mota, "i9") == 0) i9 = i9 + eskaeraZerrenda[i].kopurua;
	}

	fp = fopen("fabrikazioa_aginduak.txt", "w");
	fprintf(fp, "i3 %d\n", i3);
	fprintf(fp, "i5 %d\n", i5);
	fprintf(fp, "i7 %d\n", i7);
	fprintf(fp, "i9 %d\n", i9);
	fclose(fp);
}

void eskaeraModifikatu(ESKAERA eskaeraZerrenda[], int eskaeraKop)
{
	char str[6];
	int pos;

	printf("Zein da modifikatu nahi duzun eskaeraren zenbakia?\n");
	printf("1 eta %d artean egon behar da.\n", eskaeraKop);
	fgets(str, 4, stdin);
	sscanf(str, "%d", &pos);

	printf("Zein da fabrikatu behar den modeloa (i3, i5, i7, i9)?\n");
	fgets(str,  4, stdin);
	str[strlen(str)-1]='\0';
	strcpy(eskaeraZerrenda[pos - 1].mota, str);
	printf("Zein da kopuru berria:");
	fgets(str, 6, stdin);
	sscanf(str, "%d", &eskaeraZerrenda[pos - 1].kopurua);
	printf("Sartu bezeroaren ID-a:");
	fgets(str, 6, stdin);
	sscanf(str, "%d", &eskaeraZerrenda[pos-1].bezeroaId);

}

void eskaeraGuztiakBistaratu(ESKAERA eskaeraZerrenda[], int eskaeraKop)
{
	int i;

	printf("Eskaera zerrenda:\n");
	for (i = 0; i < eskaeraKop; i++)
	{
		printf("%d %s %d %d\n", eskaeraZerrenda[i].id,
			eskaeraZerrenda[i].mota,
			eskaeraZerrenda[i].kopurua,
			eskaeraZerrenda[i].bezeroaId);
	}
}

int bezeroZerrendaIrakurri(BEZEROA bezeroZerrenda[])
{
	int irakurritakoak;
	int i = 0;
	FILE* fp;

	if ((fp = fopen("bezeroak.txt", "r")) == NULL) printf("Ez da fitxategia aurkitu\n");
	else
	{
		do {
			irakurritakoak = fscanf(fp, "%d %s",
				&bezeroZerrenda[i].id,
				bezeroZerrenda[i].enpresa);
			if (irakurritakoak != EOF) i++;
		} while (irakurritakoak != EOF);

		fclose(fp);
	}
	return i;
}

void bezeroGuztiakBistaratu(BEZEROA bezeroZerrenda[], int bezeroKop)
{
	int i;

	printf("Bezero zerrenda:\n");
	for (i = 0; i < bezeroKop; i++)
	{
		printf("%d %s\n", bezeroZerrenda[i].id,
			bezeroZerrenda[i].enpresa);
	}
}

void produkzioakBezerokaKalkulatu(ESKAERA eskaeraZerrenda[], int eskaeraKop,
	BEZEROA bezeroZerrenda[], int bezeroKop)
{
	int bez = 0, esk = 0;
	int i3, i5, i7, i9;
	int totala;
	char fitxIzena[30];
	FILE* fp;

	for (bez = 0; bez < bezeroKop; bez++)
	{
		i3 = 0; i5 = 0; i7 = 0; i9 = 0;
		for (esk = 0; esk < eskaeraKop; esk++)
		{
			if (bezeroZerrenda[bez].id == eskaeraZerrenda[esk].bezeroaId)
			{
				if (strcmp(eskaeraZerrenda[esk].mota, "i3") == 0) i3 = i3 + eskaeraZerrenda[esk].kopurua;
				else if (strcmp(eskaeraZerrenda[esk].mota, "i5") == 0) i5 = i5 + eskaeraZerrenda[esk].kopurua;
				else if (strcmp(eskaeraZerrenda[esk].mota, "i7") == 0) i7 = i7 + eskaeraZerrenda[esk].kopurua;
				else if (strcmp(eskaeraZerrenda[esk].mota, "i9") == 0) i9 = i9 + eskaeraZerrenda[esk].kopurua;
			}
		}
		bezeroZerrenda[bez].i3 = i3;
		bezeroZerrenda[bez].i5 = i5;
		bezeroZerrenda[bez].i7 = i7;
		bezeroZerrenda[bez].i9 = i9;
		strcpy(fitxIzena, bezeroZerrenda[bez].enpresa);
		strcat(fitxIzena, "_faktura.txt");
		fp = fopen(fitxIzena, "w");
		fprintf(fp, "Faktura %s:\n", bezeroZerrenda[bez].enpresa);
		fprintf(fp, "i3 %d\n", i3);
		fprintf(fp, "i5 %d\n", i5);
		fprintf(fp, "i7 %d\n", i7);
		fprintf(fp, "i9 %d\n", i9);
		totala = (i3 + i5 + i7 + i9) * 500;
		fprintf(fp, "Totala: %d", totala);
		fclose(fp);
	}
}
