#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ikasle.h"

ERABILTZAILEA eskatuHelbidea()
{
	ERABILTZAILEA erabil;
	//.....
	system("clear");	//system("cls");
	printf("Sartu zure emaila?");
	/*fgets( str , MAX_STR, stdin);
	   str[strlen(str)-1]='\0';
	   strcpy( erabil.emaila , str ); */

	fgets(erabil.emaila, MAX_STR, stdin);
	erabil.emaila[strlen(erabil.emaila) - 1] = '\0';

	/*egokia = balidatuEmaila(erabil.emaila);
	   if (egokia == 0) primtf("[ERROR] Email desegokia.\n"); */

	return erabil;
}

void bistaratuErabiltzailea(ERABILTZAILEA erabil)
{
	printf("Bistaratzen erabilztrailearen emaila:%s\n", erabil.emaila);

}

void bistaratuErabiltzaileaPTRgaz(ERABILTZAILEA * ptr_erabil)
{
	printf("Bistaratzen erabilztrailearen emaila:%s\n", ptr_erabil->emaila);
}

void eskatuHainbatHelbidev2(ERABILTZAILEA * erabiltzaileak, int *kop)
{
	do {
		erabiltzaileak[*kop] = eskatuHelbidea();
		++*kop;
	} while (erabiltzaileak[*kop - 1].emaila[0]);
}

void pantailaratu(ERABILTZAILEA * erabiltzaileak, int kop)
{
	int i;
	for (i = 0; i < kop; ++i) {
		bistaratuErabiltzaileaPTRgaz(erabiltzaileak + i);
		++i;
	}
}

void ateraIzenav2 (ERABILTZAILEA  *erak){
	char* c_emaila = erak->emaila;
	char* c_izena = erak->izena;
	while (*c_emaila != '\0' && *c_emaila != '.') {
		*c_izena = *c_emaila;
		++c_izena;
		++c_emaila;
	}
}

void ateraAbizena (ERABILTZAILEA  *erak){
	char* c_emaila = strchr(erak->emaila, '.');
	char* c_abizena = erak->abizena;
	if (c_emaila) {
		++c_emaila;
		while (*c_emaila != '\0' && *c_emaila != '@') {
			*c_abizena = *c_emaila;
			++c_abizena;
			++c_emaila;
		}
	}
}
