#include "ikaslea.h"

double IKASLEA_otsaileko_nota(IKASLEA ik)
{
	int i;
	double sum = 0;
	int kp_lim = ik.kp_kop < IKASLEA_OTSAILA_KP_MAX ? ik.kp_kop : IKASLEA_OTSAILA_KP_MAX;

	for (i = IKASLEA_OTSAILA_KP_MIN; i < kp_lim; ++i) {
		sum += ik.kp[i];
	}

	return sum / (IKASLEA_OTSAILA_KP_MAX - IKASLEA_OTSAILA_KP_MIN);
}

double IKASLEA_ekaineko_nota(IKASLEA ik)
{
	int i;
	double sum = 0;
	int kp_lim = ik.kp_kop < IKASLEA_EKAINA_KP_MAX ? ik.kp_kop : IKASLEA_EKAINA_KP_MAX;

	for (i = IKASLEA_EKAINA_KP_MIN; i < kp_lim; ++i) {
		sum += ik.kp[i];
	}

	return sum / (IKASLEA_EKAINA_KP_MAX - IKASLEA_EKAINA_KP_MIN);
}

double IKASLEA_nota_finala(IKASLEA ik)
{
	int i;
	double sum = 0;

	for (i = 0; i < ik.kp_kop; ++i) {
		sum += ik.kp[i];
	}

	return sum / IKASLEA_KP_KOP;
}

IKASLEA IKASLEA_notak_borratu(IKASLEA ik)
{
	ik.kp_kop = 0;
	return ik;
}
