#ifndef JARRAITZAILEA_H_
#define JARRAITZAILEA_H_

#define EZKERREKO_SENTSOREA 22
#define ESKUMAKO_SENTSOREA 19

#define BELTZA_DEFAULT_EZKERRA 400
#define TXURIA_DEFAULT_EZKERRA 285

#define BELTZA_DEFAULT_ESKUMA 410
#define TXURIA_DEFAULT_ESKUMA 240

#define READING_TIMEOUT 1000
#define CHARGE_TIME 10

#define AURREA_EZK_AUR 18
#define AURREA_EZK_ATZ 23
#define AURREA_ESK_AUR 24
#define AURREA_ESK_ATZ 25

#define ATZEA_EZK_AUR 12
#define ATZEA_EZK_ATZ 16
#define ATZEA_ESK_AUR 20
#define ATZEA_ESK_ATZ 21

int ezkerra_beltzean_dago(float sentsorearen_balioa);
int eskuma_beltzean_dago(float sentsorearen_balioa);
int ezkerreko_sentsorea_irakurri();
int eskumako_sentsorea_irakurri();
void lerro_jarraitzailea();

#endif
