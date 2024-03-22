/*
 * main.c
 *
 *  Created on: 2024(e)ko mar. 14(a)
 *      Author: joseba
 */




#include <stdio.h>

#include "ikasleak.h"
#include "filesystem_helper.h"



int main(){
	FILESYSTEM_HELPER_cd_base_path();

	IKASLE idazteko[MAX_IKASLE];
	int kop1 = 0;
	IKASLE irakurtzeko[MAX_IKASLE];
	int kop2 = 0;

	kop1 =  ikasleak_sortu_eta_sartu_arraian(4 , idazteko);

	ikasleak_idatzi_testu_bitarrean_banan_banan(idazteko, kop1);
	ikasleak_idatzi_testu_bitarrean(idazteko, kop1);

	kop2 = ikasleak_irakurri_bitarrean(irakurtzeko);
	ikasleak_idatzi_testu_fitxategia_fp(irakurtzeko, kop2, stdout);

	kop2 = ikasleak_irakurri_bitarrean_banan_banan(irakurtzeko);
	ikasleak_idatzi_testu_fitxategia_fp(irakurtzeko, kop2, stdout);

	return 0;
}
