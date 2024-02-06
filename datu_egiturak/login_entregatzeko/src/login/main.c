#include <string.h>
#include <stdio.h>

void password_login_irakurri(char* erabiltzaile_izena, char* pasahitza);
int login_konprobatu(char* erabiltzaile_izena, char* pasahitza);
void menua(int erabil_mota, char username[]);
void agur_mezua(void);
void saiakera_gehiegi(void);
void login_erantzun(int logeatua);

#define UNUSED(x) do (void) x; while (0)

int main(int argc, char** argv) {

    UNUSED(argc);
    UNUSED(argv);

    //aldagiak
    int logeatua = 0;
    char username[64];
    char password[64];
    int saiakerak = 3;

    //programa
    while (!logeatua && saiakerak > 0) {
        password_login_irakurri(username, password);
        logeatua = login_konprobatu(username, password);
        login_erantzun(logeatua);
        --saiakerak;
    }
    
    if (logeatua) {
        menua(logeatua, username);
    } else {
        saiakera_gehiegi();
    }
    //bukaera
    agur_mezua();

    return 0;
}


void login_erantzun(int logeatua) {
    if (logeatua) {
        printf("Pasaitza zuzena. Sartzen...\n");
    } else {
        printf("Pasahitza ala erabiltzaile okerra!\n");
    }
}

void saiakera_gehiegi(void) {
    printf("Saiakera gehiegi! Bukatzen...\n");
}

void password_login_irakurri(char* erabiltzaile_izena, char* pasahitza) {
    printf("================Subasta aplikazioan sartzeko logina=========================\n");

    printf("Username: ");
    fgets(erabiltzaile_izena, 64, stdin);
    erabiltzaile_izena[strlen(erabiltzaile_izena) - 1] = '\0';

    printf("Password: ");
    fgets(pasahitza, 64, stdin);
    pasahitza[strlen(pasahitza) - 1] = '\0';
}

int login_konprobatu(char* erabiltzaile_izena, char* pasahitza) {
    return strcmp(erabiltzaile_izena, "Joseba") == 0 && strcmp(pasahitza, "123456") == 0;
}

void menua(int erabil_mota, char username[]) {
    switch (erabil_mota) {
        case 1:
            printf("Ongi etorri, %s! Erabiltzaile mota: %d\n\n", username, erabil_mota);
            break;
        default:
            printf("Errorea: erabiltzaile mota ezezaguna.");
            break;
    }
}

void agur_mezua(void) {
    printf("Sakatu return bukatzeko...");
    getc(stdin);
}
