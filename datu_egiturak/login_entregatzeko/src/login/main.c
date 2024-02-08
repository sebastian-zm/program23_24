#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define UNUSED(x) do (void) x; while (0)

#define MEMORIA_GABE "Memoria gabe geratu gara. :(\\n"
#define SAIAKERAK 3
#define BUFFER_SIZE 64

typedef struct {
	char *izena;
	char *pasahitza;
	int erabiltzailea_mota;	//0-user, 1-admin 2-guest
	char *email;
} USER;

int loginSaiatu(USER datubasea[], int erabiltzaile_kop, int saiakerak,
		int *erabiltzaile_id);
int loginSaiakera(USER datubasea[], int erabiltzaile_kop, int *erabiltzaile_id);
void ongiEtorri(USER erabiltzaile);
void saiakeraGehiegi(void);
char *stringEskatu(char *prompt);
void agur_mezua(void);

int main(int num, char *args[])
{
	UNUSED(num);
	UNUSED(args);

	USER datubasea[] = {
		{.izena = "admin",.pasahitza = "qwerty",.erabiltzailea_mota =
		 1,.email = "admin@example.invalid"}
	};

	int erabiltzaile_id;
	if (loginSaiatu
	    (datubasea, sizeof(datubasea) / sizeof(datubasea[0]), SAIAKERAK,
	     &erabiltzaile_id)) {
		ongiEtorri(datubasea[erabiltzaile_id]);
	} else {
		saiakeraGehiegi();
	}

	//programa
	//1-ESKATU username eta password
	//2-konprobatu admin qwerty
	//3-admin qwerty bada emon ongi etorria
	//4-bestela esan desegokia dela
	//5-3 saiakera

	//bukaera
	agur_mezua();

	return 0;
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
		fgets_ondo = fgets(ret + azkenera, BUFFER_SIZE - 1, stdin);
		amaitu_da = strrchr(ret + azkenera, '\n');
	}

	while (ret && fgets_ondo && !amaitu_da) {
		azkenera = strchr(ret + azkenera, '\0') - ret;

		tmp = realloc(ret, sizeof(*ret) * (azkenera + BUFFER_SIZE));

		if (tmp) {
			ret = tmp;
			fgets_ondo =
			    fgets(ret + azkenera, BUFFER_SIZE - 1, stdin);
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

int loginSaiakera(USER datubasea[], int erabiltzaile_kop, int *erabiltzaile_id)
{
	char *erabiltzailea;

	char *pasahitza;

	int logeatua = 0;
	int bukatu = 0;

	int oraingo_erabiltzaile_idx = 0;

	erabiltzailea = stringEskatu("Eman erabiltzailea: ");
	pasahitza = stringEskatu("Eman pasahitza: ");

	if (!pasahitza || !erabiltzailea) {
		bukatu = 1;
	}

	while (!bukatu && oraingo_erabiltzaile_idx < erabiltzaile_kop) {
		bukatu =
		    !strcmp(erabiltzailea,
			    datubasea[oraingo_erabiltzaile_idx].izena);

		if (bukatu) {
			logeatua =
			    !strcmp(pasahitza,
				    datubasea
				    [oraingo_erabiltzaile_idx].pasahitza);
		} else {
			++oraingo_erabiltzaile_idx;
		}
	}

	if (logeatua) {
		*erabiltzaile_id = oraingo_erabiltzaile_idx;
	}

	free(erabiltzailea);
	free(pasahitza);

	return logeatua;
}

int loginSaiatu(USER datubasea[], int erabiltzaile_kop, int saiakerak,
		int *erabiltzaile_id)
{
	int logeatua = 0;
	while (!logeatua && saiakerak > 0) {
		logeatua =
		    loginSaiakera(datubasea, erabiltzaile_kop, erabiltzaile_id);
		--saiakerak;
	}

	return logeatua;
}

void ongiEtorri(USER erabiltzaile)
{
	printf("Kaixo, %s\n", erabiltzaile.izena);
}

void saiakeraGehiegi(void)
{
	printf("Saiakera gehiegi egin dituzu.\n");
}

void agur_mezua(void)
{
	printf("Sakatu return bukatzeko....");
	getc(stdin);
}
