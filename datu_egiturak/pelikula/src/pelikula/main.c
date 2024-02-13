
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MAX_STR 128

#define WESTERN 0
#define DRAMA 1
#define THRILLER 2
#define COMEDIA 3
#define TERROR 4
#define SCIFI 5

#define UNUSED(x) do (void) x; while (0)

#define MAX_PELIKULAK 1000
#define BUFFER_SIZE 60

//1- DATU MOTA BERRIA SORTU
typedef struct Pelikula {
	char *izenburua;
	char *zuzendaria;
	int edizio_urtea;
	int estiloa;
	float diru_bilketa;
	float kalifikazioa;
} PELIKULA;

char *stringEskatu(char *prompt);
void irten_pelikulekin(PELIKULA p[], int *p_kop, int p_max);
void pelikula_sortu_menu(PELIKULA p[], int *p_kop, int p_max);
void pelikula_aldatu_menu(PELIKULA p[], int *p_kop, int p_max);
void pelikulak_bistaratu_menu(PELIKULA p[], int *p_kop, int p_max);
void pelikula_estilo_bistaratu_menu(PELIKULA p[], int *p_kop, int p_max);
void pelikula_zaharrago_baino_bistaratu_menu(PELIKULA p[], int *p_kop, int p_max);
void diru_gehien_pelikula_bistaratu_menu(PELIKULA p[], int *p_kop, int p_max);
void pelikula_ezabatu_menu(PELIKULA p[], int *p_kop, int p_max);
void pelikula_guztien_irabaziak_bistaratu(PELIKULA p[], int *p_kop, int p_max);

#define MENU_AUKERAK \
	X(IRTEN, irten_pelikulekin, "Irten") \
	X(SORTU, pelikula_sortu_menu, "Pelikula bat sortu") \
	X(ALDATU, pelikula_aldatu_menu, "Pelikula bat aldatu") \
	X(DANAK, pelikulak_bistaratu_menu, "Pelikula guztiak bistaratu") \
	X(ESTILO, pelikula_estilo_bistaratu_menu, "Estilo bateko pelikula guztiak bistaratu") \
	X(DATA, pelikula_zaharrago_baino_bistaratu_menu, "Urte bat ala zaharragoak diren pelikulak bistaratu") \
	X(DIRU_GEHIEN, diru_gehien_pelikula_bistaratu_menu, "Diru gehien sortu duen pelikula bistaratu") \
	X(EZABATU, pelikula_ezabatu_menu, "Pelikula bat ezabatu") \
	X(IRABAZI_TOTALA, pelikula_guztien_irabaziak_bistaratu, "Pelikula guztien irabaziak batu eta bistaratu")

typedef enum MenuAukera {
#define X(iden, func, desc) iden,
	MENU_AUKERAK MENU_AUKEREN_TAMAINA
#undef X
} MENU_AUKERA;

typedef void (*MENU_FUNTZIOA)(PELIKULA p[], int *p_kop, int p_max);

MENU_FUNTZIOA MENU_FUNTZIOAK[MENU_AUKEREN_TAMAINA] = {
#define X(iden, func, desc) &func,
	MENU_AUKERAK
#undef X
};

int izenburuzIndexAurkitu(PELIKULA p[], int p_kop, char *izenburua);
void bistaratu_pelikula_bat(PELIKULA pel);
void aldatu_pelikula_bat(PELIKULA * peli);
void pelikula_ezabatu(PELIKULA peli);

int eskatu_estiloa(void);
void bistaratu_estiloa(int estiloa);
void jarraitu(void);
void borratu_pantaila(void);
int menua(void);

int main(void)
{
	int zenbat_pelikula = 0;
	PELIKULA pelikulak[MAX_PELIKULAK];
	MENU_AUKERA aukera = 0;

	borratu_pantaila();
	while ((aukera = menua())) {
		if (aukera < 0 || aukera >= MENU_AUKEREN_TAMAINA) {
			printf("Aukera desegokia.\n");
			jarraitu();
		} else {
			MENU_FUNTZIOAK[aukera] (pelikulak, &zenbat_pelikula, MAX_PELIKULAK);
			jarraitu();
			borratu_pantaila();
		}
	}

	return EXIT_SUCCESS;
}

int menua(void)
{
	char *str;
	int aukera;
	printf("\nMenua:\n");
#define X(iden, func, desc) printf("%d. %s\n", iden, desc);
	MENU_AUKERAK
#undef X
	    str = stringEskatu("Eman aukera: ");
	sscanf(str, "%d", &aukera);
	free(str);

	if (aukera < 0 || aukera >= MENU_AUKEREN_TAMAINA) {
		aukera = -1;
	}

	return aukera;
}

int izenburuzIndexAurkitu(PELIKULA p[], int p_kop, char *izenburua)
{
	int ret = 0;
	int aurkituta = 0;
	while (ret < p_kop && !aurkituta) {
		if (!strcmp(izenburua, p[ret].izenburua)) {
			aurkituta = 1;
		} else {
			++ret;
		}
	}
	return ret;
}

void pelikula_ezabatu(PELIKULA peli)
{
	free(peli.izenburua);
	free(peli.zuzendaria);
}

void aldatu_pelikula_bat(PELIKULA * peli)
{
	char *str;
	peli->izenburua = stringEskatu("Pelikularen izenburua? ");

	peli->zuzendaria = stringEskatu("Pelikularen Zuzendaria? ");

	str = stringEskatu("Pelikula grabatu zen urtea? ");
	sscanf(str, "%i", &peli->edizio_urtea);
	free(str);

	str = stringEskatu("Pelikulak bildu zuen dirua? ");
	sscanf(str, "%f", &peli->diru_bilketa);
	free(str);

	str = stringEskatu("Kalifikazioa (IMDB)? ");
	sscanf(str, "%f", &peli->kalifikazioa);
	free(str);

	peli->estiloa = eskatu_estiloa();
}

void bistaratu_pelikula_bat(PELIKULA pel)
{
	borratu_pantaila();

	printf("===================PELIKULA INFO====================\n");
	printf("Izenburua: %s\n", pel.izenburua);
	printf("Zuzendaria: %s\n", pel.zuzendaria);
	printf("Urtea: %i\n", pel.edizio_urtea);
	printf("Diru bilketa: %.2f€\n", pel.diru_bilketa);
	printf("Kalifikazioa (IMDB):%.2f\n", pel.kalifikazioa);

	bistaratu_estiloa(pel.estiloa);
	jarraitu();
}

int eskatu_estiloa(void)
{
	int estiloa = -1;
	char *str =
	    stringEskatu("Pelikularen estiloa: 0-WESTERN, 1-DRAMA, 2-THRILLER, 3-COMEDIA, 4-TERROR, 5- SCIFI ? ");
	sscanf(str, "%i", &estiloa);
	free(str);

	if (estiloa < 0 || estiloa > 5) {
		estiloa = -1;
	}

	return estiloa;
}

void bistaratu_estiloa(int estiloa)
{
	switch (estiloa) {
	case WESTERN:
		printf("-> Western motako filma. \n");
		break;
	case DRAMA:
		printf("-> Drama motako filma.\n");
		break;
	case THRILLER:
		printf("-> Thriller motako filam.\n");
		break;
	case COMEDIA:
		printf("-> Komedia motako filma.\n");
		break;
	case TERROR:
		printf("-> Beldurrezko filma.\n");
		break;
	case SCIFI:
		printf("Zientzia fikzioazko filma.\n");
		break;
	default:
		printf("Pelikuaren generoa ez dago definituta.\n");
		break;

	}

}

void jarraitu()
{
	printf("Sakatu return jarraitzeko...");
	getchar();
}

void borratu_pantaila()
{
	system("clear");
}

void irten_pelikulekin(PELIKULA p[], int *p_kop, int p_max)
{
	UNUSED(p);
	UNUSED(p_kop);
	UNUSED(p_max);

	fprintf(stderr, "Errorea: irten_pelikulekin deitu da.\n");
}

void pelikula_sortu_menu(PELIKULA p[], int *p_kop, int p_max)
{
	printf("Pelikula sortzen...\n");
	if (*p_kop + 1 > p_max) {
		printf("Ezin dira pelikula gehiago sortu. :(\n");
	} else {
		aldatu_pelikula_bat(&p[*p_kop]);
		++*p_kop;
	}
}

void pelikula_aldatu_menu(PELIKULA p[], int *p_kop, int p_max)
{
	UNUSED(p_max);

	int pelikula_idx = 0;
	char *str;

	str = stringEskatu("Emaidazu pelikularen izena: ");
	pelikula_idx = izenburuzIndexAurkitu(p, *p_kop, str);
	free(str);

	if (pelikula_idx == *p_kop) {
		printf("Ez dut pelikula aurkitu.\n");
	} else {
		printf("Pelikula aldatzen...\n");
		aldatu_pelikula_bat(&p[pelikula_idx]);
	}
}

void pelikulak_bistaratu_menu(PELIKULA p[], int *p_kop, int p_max)
{
	UNUSED(p_max);

	int idx;
	for (idx = 0; idx < *p_kop; ++idx) {
		bistaratu_pelikula_bat(p[idx]);
	}
}

void pelikula_estilo_bistaratu_menu(PELIKULA p[], int *p_kop, int p_max)
{
	UNUSED(p_max);

	int idx;
	int estilo = eskatu_estiloa();

	for (idx = 0; idx < *p_kop; ++idx) {
		if (estilo == p[idx].estiloa) {
			bistaratu_pelikula_bat(p[idx]);
		}
	}
}

void pelikula_zaharrago_baino_bistaratu_menu(PELIKULA p[], int *p_kop, int p_max)
{
	UNUSED(p_max);

	int idx;
	int berriena = 0;
	char *str = stringEskatu("ikusi nahi duzun pelikula berriena grabatu zen urtea? ");
	sscanf(str, "%i", &berriena);
	free(str);

	for (idx = 0; idx < *p_kop; ++idx) {
		if (berriena >= p[idx].edizio_urtea) {
			bistaratu_pelikula_bat(p[idx]);
		}
	}
}

void diru_gehien_pelikula_bistaratu_menu(PELIKULA p[], int *p_kop, int p_max)
{
	UNUSED(p_max);

	PELIKULA *peli = &p[0];
	int idx;
	float max_diru = p[0].diru_bilketa;

	if (*p_kop <= 0) {
		printf("Ez dago pelikularik");
	} else {
		for (idx = 1; idx < *p_kop; ++idx) {
			if (p[idx].diru_bilketa > max_diru) {
				peli = &p[idx];
			}
		}
		bistaratu_pelikula_bat(*peli);
	}
}

void pelikula_ezabatu_menu(PELIKULA p[], int *p_kop, int p_max)
{
	UNUSED(p_max);

	char *str = stringEskatu("Emaidazu pelikularen izena: ");
	int pelikula_idx = izenburuzIndexAurkitu(p, *p_kop, str);
	free(str);

	if (pelikula_idx == *p_kop) {
		printf("Ez dut pelikula aurkitu.\n");
	} else {
		pelikula_ezabatu(p[pelikula_idx]);
		memmove(&p[pelikula_idx], &p[pelikula_idx + 1], sizeof(p[pelikula_idx]) * (*p_kop - pelikula_idx - 1));
		--*p_kop;
	}
}

void pelikula_guztien_irabaziak_bistaratu(PELIKULA p[], int *p_kop, int p_max)
{
	UNUSED(p_max);

	float irabaziak = 0.0;
	int i;

	for (i = 0; i < *p_kop; ++i) {
		irabaziak += p[i].diru_bilketa;
	}

	printf("irabaziak: %f\n", irabaziak);
}

char *stringEskatu(char *prompt)
{
	char *ret;
	char *tmp;
	ptrdiff_t azkenera = 0;

	char *fgets_ondo = NULL;
	char *amaitu_da = NULL;

	printf("%s", prompt);

	ret = malloc(BUFFER_SIZE * sizeof(*ret));

	if (ret) {
		fgets_ondo = fgets(ret + azkenera, BUFFER_SIZE, stdin);
		amaitu_da = strrchr(ret + azkenera, '\n');
	}

	while (ret && fgets_ondo && !amaitu_da) {
		azkenera = strchr(ret + azkenera, '\0') - ret;

		tmp = realloc(ret, sizeof(*ret) * (azkenera + BUFFER_SIZE));

		if (tmp) {
			ret = tmp;
			fgets_ondo = fgets(ret + azkenera, BUFFER_SIZE, stdin);
			amaitu_da = strrchr(ret + azkenera, '\n');
		} else {
			free(ret);
			ret = NULL;
		}
	}

	if (ret && fgets_ondo && amaitu_da) {
		*amaitu_da = '\0';
	} else if (ret && !fgets_ondo && !feof(stdin)) {
		// Errorea gertatu da, eta ez da izan EOF.
		free(ret);
		ret = NULL;
	}

	return ret;
}
