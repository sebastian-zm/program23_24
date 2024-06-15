#include <stdio.h>

typedef struct s_pertsona{
	int id;
	char izena[64];
	int korrika;
	int bizikleta;
	int totala;
}PERTSONA;

void ordenatu_arraia(PERTSONA* pertsonak, int kop);
void arraia_bistaratu(PERTSONA* pertsonak, int kop);
void pertsona_bistaratu(PERTSONA pertsona);
void totala_kalkultau(PERTSONA* per);

int main()
{
	PERTSONA p1[]={
		{1,"joseba",4,5,0},
		{2,"jon",3,2,0},
		{3,"iratxe",9,8,0},
		{4,"imanol",2,2,0}
	};
	int kop = 4;

	ordenatu_arraia(p1, kop);
	arraia_bistaratu(p1, kop);
}

void ordenatu_arraia(PERTSONA* pertsonak, int kop)
{
	PERTSONA tmp;
	int i, j, min;
	for (i = 0; i < kop; ++i) {
		totala_kalkultau(pertsonak + i);
	}
	for (i = 0; i < kop - 1; ++i) {
		min = i;
		for (j = min + 1; j < kop; ++j) {
			if ((pertsonak + min)->totala > (pertsonak + j)->totala) {
				min = j;
			}
		}
		tmp = *(pertsonak + i);
		*(pertsonak + i) = *(pertsonak + min);
		*(pertsonak + min) = tmp;
	}
}
void arraia_bistaratu(PERTSONA* pertsonak, int kop)
{
	if (kop > 0) {
		pertsona_bistaratu(*pertsonak);
		arraia_bistaratu(pertsonak + 1, kop - 1);
	}
}
void pertsona_bistaratu(PERTSONA pertsona)
{
	printf("Pertsona: {\n");
	printf("\tid: %d\n", pertsona.id);
	printf("\tizena: %s\n", pertsona.izena);
	printf("\tkorrika: %d\n", pertsona.korrika);
	printf("\tbizikleta: %d\n", pertsona.bizikleta);
	printf("\ttotala: %d\n", pertsona.totala);
	printf("}\n");
}
void totala_kalkultau(PERTSONA* per)
{
	per->totala = per->korrika + per->bizikleta;
}
