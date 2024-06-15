
#ifndef FLOYD_H_
#define FLOYD_H_

#define GRAFOA_MAX_IZENA 20
#define GRAFOA_ERPINA_MAX_ERTZAK 5
#define MAX_STR 128
#define PI 3.14159265f
typedef struct GRAFOA_ERPINA_s GRAFOA_ERPINA;
typedef struct GRAFOA_ERTZA_s {
	GRAFOA_ERPINA *nora;
	float pisua;
} GRAFOA_ERTZA;
typedef struct GRAFOA_ERTZA_NODOA_s {
	GRAFOA_ERTZA elementua;
	struct GRAFOA_ERTZA_NODOA_s *ptr_hurrengoa;
} GRAFOA_ERTZA_NODOA;
struct GRAFOA_ERPINA_s {
	char izena[GRAFOA_MAX_IZENA];
	int x;
	int y;
	int id;			// del  0 hasta ertza_kop
	GRAFOA_ERTZA_NODOA *ertzak;
};
typedef struct GRAFOA_s {
	GRAFOA_ERPINA elementua;
	struct GRAFOA_s *ptr_hurrengoa;
} GRAFOA;
typedef struct IBILBIDEA_s {
	GRAFOA_ERPINA elementua;
	struct IBILBIDEA_s *ptr_hurrengoa;
} IBILBIDEA;

//GRAFOA_ERPINA* GRAFOA_ERPINA_izenez_aurkitu();
GRAFOA *irakurri_eta_buruan_sartu(FILE * fitx, int *kopurua);
FILE *fitx_ireki(char fitx_izena[]);
void irakurri_fitx_izena(char fitx_izena[]);
GRAFOA *irakurri_fitxategitik_erpinak(FILE * fitx, int *kopurua);
GRAFOA *sortu_nodo_bat(int *zenbat_irakurri, FILE * fitx);
GRAFOA *sartu_buruan(GRAFOA * ptr_hasiera, GRAFOA * ptr_berria);
void ertzak_kargatu(GRAFOA * ptr_hasiera, FILE * fitx);
GRAFOA_ERTZA_NODOA *sortu_nodo_bat_ertza(int *zenbat_irakurri, char izena[], GRAFOA * ptr_hasiera, FILE * ftx);
GRAFOA_ERPINA *aukritu_erpina(char izena[], GRAFOA * ptr_hasiera);
GRAFOA_ERPINA *aukritu_erpina_id(int id, GRAFOA * ptr_hasiera);
void bilatu_ibilbide_motzena(GRAFOA * ptr_hasiera, float **distantzia, int **matrize_laguntzailea);
void floyd_warsall(int **matrize_laguntzailea, float **distantziak, int kopurua);
int **matrize_laguntzailea_hasieratu(int kopurua);
float **distantzia_matrizea_hasieratu(int kopurua);
void distantzia_hasieratu(GRAFOA * ptr_hasiera, float **distantziak);
void bilatu_motzena(GRAFOA * ptr_hasiera, IBILBIDEA * ibilbidea, int **matrize_laguntzailea);
void ikusi_ibilbidea(IBILBIDEA * ibilbidea);
void bistaratu_bat(GRAFOA_ERPINA ibilbidea);
void eskatu_ibilbidea(char izena1[], char izena2[]);
int **matrize_laguntzailea_hasieratu(int kopurua);
void matrizea_askatu(float **matrizea, int kopurua);
int jarraitu_nahi(void);
float calcular_angulo(GRAFOA_ERPINA punto1, GRAFOA_ERPINA punto2, GRAFOA_ERPINA punto3);

#endif				/*  */
