#ifndef IKASLE_H
#define IKASLE_H

#define NESKA 0
#define MUTILA 1
#define MAX_IKASLE 30
#define MAX_STRING 100
#define KP_KOP 4

typedef struct s_nota {
	float KP[KP_KOP];
	float otsailekoNota;
	float ekainekoNota;
	float notaFinala;
} NOTA;

typedef struct s_ikaslea {
	int ID;
	char izena[MAX_STRING];
	char abizena[MAX_STRING];
	int sexua;
	NOTA notak;

} IKASLE;

void bistaratu_ikasleak(IKASLE ikasleak[], int kop);
void bistaratu_ikaslea(IKASLE ikaslea);

int irakurri_fitxategitik_ikasleak(IKASLE ikasleak[], int kop, char fitxIzena[]);
int irakurri_fitxategitik_ikasleak_fscanf(IKASLE ikasleak[], int kop, char fitxIzena[]);
IKASLE irakurri_fitxategitik_ikasle_bat(FILE * fitx_tuberia);

#endif
