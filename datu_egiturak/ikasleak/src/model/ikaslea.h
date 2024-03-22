#ifndef IKASLEA_H
#define IKASLEA_H

#define IKASLEA_MAX_STR 127
#define IKASLEA_KP_KOP 4
#define IKASLEA_OTSAILA_KP_MIN 0	// Lehen kontrol puntuaren indizea
#define IKASLEA_OTSAILA_KP_MAX 2	// Azken kontrol puntuaren indizea gehi bat
#define IKASLEA_EKAINA_KP_MIN 2	// Lehen kontrol puntuaren indizea
#define IKASLEA_EKAINA_KP_MAX 4	// Azken kontrol puntuaren indizea gehi bat
#define IKASLEAK_MAX 100

typedef struct IKASLEA_s {
	int id;
	char izena[IKASLEA_MAX_STR];
	double kp[IKASLEA_KP_KOP];
	int kp_kop;		// Egindako kontrol puntuak
} IKASLEA;

double IKASLEA_otsaileko_nota(IKASLEA ik);
double IKASLEA_ekaineko_nota(IKASLEA ik);
double IKASLEA_nota_finala(IKASLEA ik);
IKASLEA IKASLEA_notak_borratu(IKASLEA ik);

#endif
