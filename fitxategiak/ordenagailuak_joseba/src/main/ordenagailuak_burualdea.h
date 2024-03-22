#ifndef ORDENAGAILUAK
#define ORDENAGAILUAK

#define MAX_STR 64
#define MAX_ORDENAGAILU 100
#define MAX_BEZERO 20

typedef struct s_eskaera {
	int id;
	char mota[4];
	int	kopurua;
	int bezeroaId;
} ESKAERA;

typedef struct s_bezeroa {
	int id;
	char enpresa[30];
	int i3;
	int i5;
	int i7;
	int i9;
}BEZEROA;

int eskaerakFitxategitikIrakurri(ESKAERA eskaeraZerrenda[]);
int menua();
int eskaeraBerriBatGehitu(ESKAERA eskaeraZerrenda[], int eskaeraKop);
void eskaeraModifikatu(ESKAERA eskaeraZerrenda[], int eskaeraKop);
void fabrikazioAginduaSortu(ESKAERA eskaeraZerrenda[], int eskaeraKop);
void eskaeraGuztiakBistaratu(ESKAERA eskaeraZerrenda[], int eskaeraKop);
int bezeroZerrendaIrakurri(BEZEROA bezeroZerrenda[]);
void bezeroGuztiakBistaratu(BEZEROA bezeroZerrenda[], int bezeroKop);
void produkzioakBezerokaKalkulatu(ESKAERA eskaeraZerrenda[], int eskaeraKop,
								BEZEROA bezeroZerrenda[], int bezeroKop);
#endif
