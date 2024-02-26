#include "user.h"

int loginSaiatu(USER user_datu_basea[], int erabiltzaile_kop, int saiakerak, int *erabiltzaile_id)
{
	int logeatua = 0;
	while (!logeatua && saiakerak > 0) {
		logeatua = loginSaiakera(user_datu_basea, erabiltzaile_kop, erabiltzaile_id);
		--saiakerak;
	}

	return logeatua;
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

	erabiltzailea = CONSOLE_HELPER_eskatu_str("Eman erabiltzailea: ");
	pasahitza = CONSOLE_HELPER_eskatu_str("Eman pasahitza: ");

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

void ongiEtorri(USER erabiltzaile)
{
	printf("Kaixo, %s\n", erabiltzaile.izena);
}

void saiakeraGehiegi(void)
{
	printf("Saiakera gehiegi egin dituzu.\n");
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
