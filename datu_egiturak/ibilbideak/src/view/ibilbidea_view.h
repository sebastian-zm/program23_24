#ifndef IBILBIDEA_VIEW_H
#define IBILBIDEA_VIEW_H

#include "user.h"

void IBILBIDEA_erakutsi(IBILBIDEA i);
int IBILBIDEA_aurkitu(IBILBIDEAK ibik);
IBILBIDEAK IBILBIDEA_eskatu_eta_gehitu(IBILBIDEAK ibik, USER user);
void IBILBIDEAK_erabiltzailearenak_ikusi(IBILBIDEAK ibik, USER user);
void IBILBIDEAK_ikusi(IBILBIDEAK ibik);
IBILBIDEAK IBILBIDEAK_ezabatzeko_eskatu(IBILBIDEAK ibik, USER user);


#endif // IBILBIDEA_H
