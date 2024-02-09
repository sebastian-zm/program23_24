#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define UNUSED(x) do (void) x; while (0)

#define MEMORIA_GABE "Memoria gabe geratu gara. :(\\n"
#define SAIAKERAK 3
#define BUFFER_SIZE 60

typedef struct {
	char *izena;
	char *pasahitza;
	int erabiltzailea_mota;	//0-user, 1-admin 2-guest
	char *email;
} USER;

int loginSaiatu(USER user_datu_basea[], int erabiltzaile_kop, int saiakerak, int *erabiltzaile_id);
int loginSaiakera(USER user_datu_basea[], int erabiltzaile_kop, int *erabiltzaile_id);
void ongiEtorri(USER erabiltzaile);
void saiakeraGehiegi(void);
char *stringEskatu(char *prompt);
void agur_mezua(void);
void itxaron(void);

void erabiltzaileak_bistaratu(USER user_datu_basea[], int erabiltzaile_kop);
void erabiltzaile_bat_bistaratu(USER erabiltzaile);
void erabiltzaile_mota_bistaratu(int mota);
char *erabiltzaile_mota_itzuli(int mota);

int main(int num, char *args[])
{
	UNUSED(num);
	UNUSED(args);

	USER user_datu_basea[] = {
		{.izena = "admin",.pasahitza = "qwerty",.erabiltzailea_mota = 1,.email = "admin@example.invalid"},
		{.izena = "irati",.pasahitza = "@g1rr3",.erabiltzailea_mota = 2,.email = "irati@example.invalid"},
		{.izena = "joseba",.pasahitza = "123456",.erabiltzailea_mota = 2,.email = "jaagirre@example.invalid"},
		{.izena = "jon",.pasahitza = "vf4P-8k",.erabiltzailea_mota = 2,.email = "jon@example.invalid"}
	};

	int erabiltzaile_id;

	erabiltzaileak_bistaratu(user_datu_basea, sizeof(user_datu_basea) / sizeof(user_datu_basea[0]));
	itxaron();

	if (loginSaiatu
	    (user_datu_basea, sizeof(user_datu_basea) / sizeof(user_datu_basea[0]), SAIAKERAK, &erabiltzaile_id)) {
		ongiEtorri(user_datu_basea[erabiltzaile_id]);
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

void erabiltzaileak_bistaratu(USER user_datu_basea[], int erabiltzaile_kop)
{
	for (int i = 0; i < erabiltzaile_kop; ++i) {
		erabiltzaile_bat_bistaratu(user_datu_basea[i]);
	}
}

void erabiltzaile_bat_bistaratu(USER erabiltzaile)
{
	printf("Izena: %s\n", erabiltzaile.izena);
	printf("Emaila: %s\n", erabiltzaile.email);
	erabiltzaile_mota_bistaratu(erabiltzaile.erabiltzailea_mota);
	printf("\n");
}

void erabiltzaile_mota_bistaratu(int mota)
{
	char *mota_str = erabiltzaile_mota_itzuli(mota);
	printf("Erabiltzaile mota: %s\n", mota_str);
}

char *erabiltzaile_mota_itzuli(int mota)
{
	char *ret;
	switch (mota) {
	case 1:
		ret = "admin";
		break;
	case 2:
		ret = "guest";
		break;
	default:
		ret = "none";
		break;
	}
	return ret;
}

int loginSaiakera(USER user_datu_basea[], int erabiltzaile_kop, int *erabiltzaile_id)
{
	char *erabiltzailea;

	char *pasahitza;

	int logeatua = 0;
	int bukatu = 0;

	int oraingo_erabiltzaile_idx = 0;

	char *berdin_ikurrak = "====================";	// 20 berdin ikur

	system("clear");
	printf("%s LOGIN %s\n\n", berdin_ikurrak, berdin_ikurrak);

	erabiltzailea = stringEskatu("Eman erabiltzailea: ");
	pasahitza = stringEskatu("Eman pasahitza: ");

	if (!pasahitza || !erabiltzailea) {
		bukatu = 1;
	}

	while (!bukatu && oraingo_erabiltzaile_idx < erabiltzaile_kop) {
		bukatu = !strcmp(erabiltzailea, user_datu_basea[oraingo_erabiltzaile_idx].izena);

		if (bukatu) {
			logeatua = !strcmp(pasahitza, user_datu_basea[oraingo_erabiltzaile_idx].pasahitza);
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

int loginSaiatu(USER user_datu_basea[], int erabiltzaile_kop, int saiakerak, int *erabiltzaile_id)
{
	int logeatua = 0;
	while (!logeatua && saiakerak > 0) {
		logeatua = loginSaiakera(user_datu_basea, erabiltzaile_kop, erabiltzaile_id);
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

void itxaron(void)
{
	printf("Sakatu return jarraitzeko....");
	getc(stdin);
}

void agur_mezua(void)
{
	printf("Sakatu return bukatzeko....");
	getc(stdin);
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
			fgets_ondo = fgets(ret + azkenera, BUFFER_SIZE - 1, stdin);
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
