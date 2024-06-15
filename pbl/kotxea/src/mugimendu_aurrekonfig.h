
#ifndef MUGIMENDU_AURREKONFIG_
#define MUGIMENDU_AURREKONFIG_


typedef enum { ESKAILERA_ESKUBI,ESKAILERA_EZKER,BOROBIL,IRTEN_2 }AUKERAK1;

typedef struct ERPINA_s {
    char mugimendua[MAX_STR];
    unsigned int mili_segunduak;
    int abiadura;
    struct ERPINA_s* ptr_hurrengoa;
} ERPINAK;


ERPINAK* irakurri_fitxategitik_erpinak(FILE* fitx, ERPINAK* ptr_hasiera);
ERPINAK* sartu_bukaeran(ERPINAK* ptr_hasiera, ERPINAK* ptr_berria);
ERPINAK* sortu_nodo_bat(int* zenbat_irakurri, FILE* fitx);
ERPINAK* mugimendua_gauzatu(char fitx_izena[], ERPINAK* ptr_hasiera);

int aukera();
void abiadura_aukeratu(char fitxategi_1[], char fitx_2[],char fitx_izena[], int aukera1);
void mugimendua(char  mugimendu[], int denbora, int abiadura);
void stop(int duration_ms, int speed);
void eskubi(int duration_ms, int speed);
void ezkerra(int duration_ms, int speed);
void atzera(int duration_ms, int speed);
void aurrera(int duration_ms, int speed);

void eskailera_eskubi_programa();
void eskailera_ezker_programa();
void borobil_programa();
void hasieratu_gpio();
void mugimendu_aurrekonfig_programa();

#endif

