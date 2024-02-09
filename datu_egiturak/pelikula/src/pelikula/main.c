
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 128

#define WESTERN 0
#define DRAMA 1
#define THRILLER 2
#define COMEDIA 3
#define TERROR 4
#define SCIFI 5

#define MAX_PELIKULAK 1000


//1- DATU MOTA BERRIA SORTU
typedef struct Pelikula{
	char izenburua[MAX_STR];
	char zuzendaria[MAX_STR];
	int edizio_urtea;
	int estiloa;
	float diru_bilketa;
	float kalifikazioa;
}PELIKULA;



void bistartu_pelikuka_bat(PELIKULA pelikula);
PELIKULA sortu_pelikula_bat();


void bistaratu_estiloa(int estiloa);
void jarraitu();
void borratu_pantila();



int main(void) {
	// int zenbakia;
	//2- ALDAGIAK SORTU
	PELIKULA pelikula_a;
	PELIKULA pelikula_b;
	PELIKULA pelikula_c;

	//zenbakia = irakurri_zenbaki_bat();

	printf("=================Lehen pelikula sortzen=============\n");
	pelikula_a = sortu_pelikula_bat();


	printf("=================Bigarren pelikula sortzen=============\n");
	pelikula_b = sortu_pelikula_bat();


	printf("=================Hirugarren pelikula sortzen=============\n");
	pelikula_c = sortu_pelikula_bat();


	printf("=================Lehen pelikula bistaratzen=============\n");
	bistartu_pelikuka_bat(pelikula_a);


	printf("=================Bigarren pelikula bistaratzen=============\n");
	bistartu_pelikuka_bat(pelikula_b);

	printf("=================Hirugarren pelikula bistaratzen=============\n");
	bistartu_pelikuka_bat(pelikula_c);


	return EXIT_SUCCESS;
}

PELIKULA sortu_pelikula_bat(){
	char str[MAX_STR];
	PELIKULA ret;
	printf("Pelikularen izenburua?");
	fgets(ret.izenburua, MAX_STR, stdin);
	ret.izenburua[strlen(ret.izenburua)-1]='\0';

	printf("Pelikularen Zuzendaria?");
	fgets(ret.zuzendaria , MAX_STR, stdin);
	ret.zuzendaria[strlen(ret.zuzendaria)-1]='\0';

	printf("Pelikula grabatu zen urtea?");
	fgets(str , MAX_STR, stdin);
	sscanf(str , "%i", &ret.edizio_urtea);

	printf("Pelikulak bildu zuen dirua?");
	fgets(str , MAX_STR, stdin);
	sscanf(str , "%f", &ret.diru_bilketa);

	printf("Kalifikazioa (IMDB)?");
	fgets(str , MAX_STR, stdin);
	sscanf(str , "%f", &ret.kalifikazioa);

	printf("Pelikularen estiloa: 0-WESTERN, 1-DRAMA, 2-THRILLER, 3-COMEDIA, 4-TERROR 4,5- SCIFI 5 ?");
	fgets(str , MAX_STR, stdin);
	sscanf(str , "%i", &ret.estiloa);

	borratu_pantila();
	return ret;

}

void bistartu_pelikuka_bat(PELIKULA pel){

	printf("===================PELIKULA INFO====================\n");
	printf("Izenburua: %s\n", pel.izenburua);
	printf("Zuzendaria: %s\n", pel.zuzendaria);
	printf("Urtea: %i\n", pel.edizio_urtea);
	printf("Diru bilketa: %.2f€\n", pel.diru_bilketa);
	printf("Kalifikazioa (IMDB):%.2f\n", pel.kalifikazioa);

	bistaratu_estiloa(pel.estiloa);

	jarraitu();
	borratu_pantila();
}

void bistaratu_estiloa(int estiloa){
	switch(estiloa){
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
		case SCIFI :
			printf("Zientzia fikzioazko filma.\n");
			break;
		default:
			printf("Pelikuaren generoa ez dago definituta.\n");
			break;

	}

}


void jarraitu(){
	printf("Sakatu return jarraitzeko...");
	getchar();
}

void borratu_pantila(){
	system("clear");
}
