#ifndef HARDWARE_H_
#define HARDWARE_H_

#define MAX_STR 128
#define TRUE 1
#define FALSE 0

#define NB_ENABLE 1
#define NB_DISABLE 0

#define AURREA_EZK_AUR 18
#define AURREA_EZK_ATZ 23
#define AURREA_ESK_AUR 24
#define AURREA_ESK_ATZ 25

#define ATZEA_EZK_AUR 12
#define ATZEA_EZK_ATZ 16
#define ATZEA_ESK_AUR 20
#define ATZEA_ESK_ATZ 21

typedef enum { ESKUMA, EZKERRA, AURRERA, GELDI, ATZERA }EGOERAK;

void init_hw();
void kotxearen_kontrola(char tekla);

void motorra_akzionatu(EGOERAK egoerak);
void wait_seg(int seg);
int tekla_return_gabe();
void teklak_nagusia ();
#endif
