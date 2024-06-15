#ifndef DISKA_H
#define DISKA_H

#define DISKA_MAX_STR 101

typedef struct DISKA_s {
	char izenburua[DISKA_MAX_STR];
	char taldea[DISKA_MAX_STR];
	int urtea;
	char estiloa[DISKA_MAX_STR];
	int prezioa;
} DISKA;

float DISKA_getPrezioa(DISKA d);
void DISKA_bistaratu(void *d);
int DISKA_sortu(DISKA **d);

#endif
