#ifndef KP1_HELPER_H
#define KP1_HELPER_H

#include <stdio.h>
#include <stdbool.h>
#include "array_helper.h"

/* I HATE to copy code from one project to another, so I made this */

#define KP1_HELPER_MAX_ARRAY 20
#define KP1_HELPER_MAX_STR 50
#define KP1_HELPER_FILE_VARIABLE_NAME fp
#define KP1_HELPER_FSCANF(...) fscanf(KP1_HELPER_FILE_VARIABLE_NAME, __VA_ARGS__)
#define KP1_HELPER_FPRINTF(...) fprintf(KP1_HELPER_FILE_VARIABLE_NAME, __VA_ARGS__)

/* Recieves two namespaces, one in plural and another in singular for all the functions this creates.
 * Type is the struct type to be modified.
 * format_print is the arguments printf would recieve, inside parentheses. Reference the struct with the following variable name: ins
 * format_scan is the arguments scanf would recieve, inside parentheses. Reference the struct with the following variable name: ins
 * Example: KP1_HELPER_CREATE(
 *	HERRIALDEAK,
 *	HERRIALDEA,
 *	struct HERRIALDEA_s,
 *	("Herrialdea: %s; ip: %d.%d.%d.%d", ins.izena, ins.ip[0], ins.ip[1], ins.ip[2], ins.ip[3]),
 *	("%s %d.%d.%d.%d", ins.izena, &ins.ip[0], &ins.ip[1], &ins.ip[2], &ins.ip[3])
 * )
 * You put this in a .c file
 * You need to use this alongside KP1_HELPER_CREATE_HEADER in a .h file
 * */
#define KP1_HELPER_CREATE(plural, singular, type, format_print, format_scan) \
	ARRAY_HELPER_CREATE_ARRAY(plural, type, KP1_HELPER_MAX_ARRAY)\
	singular##_OK singular##_scan(FILE *KP1_HELPER_FILE_VARIABLE_NAME) {\
		type ins;\
		singular##_OK ret = {false};\
		if (0 < KP1_HELPER_FSCANF format_scan) {\
			ret.ok = true;\
			ret.data = ins;\
		}\
		return ret;\
	}\
	plural plural##_scan(FILE *KP1_HELPER_FILE_VARIABLE_NAME) {\
		singular##_OK s_ok;\
		plural ret = plural##_create();\
		do {\
			s_ok = singular##_scan(KP1_HELPER_FILE_VARIABLE_NAME);\
			if (s_ok.ok) ret = plural##_add(ret, s_ok.data);\
		} while (s_ok.ok);\
		return ret;\
	}\
	void singular##_print(FILE *KP1_HELPER_FILE_VARIABLE_NAME, type ins) {\
		KP1_HELPER_FPRINTF format_print;\
	}\
	void plural##_print(FILE *KP1_HELPER_FILE_VARIABLE_NAME, plural inss) {\
		for (size_t idx = 0; idx < inss.length; ++idx) {\
			singular##_print(KP1_HELPER_FILE_VARIABLE_NAME, inss.data[idx]);\
		}\
	}\

#define KP1_HELPER_CREATE_HEADER(plural, singular, type) \
	typedef struct singular##_OK_s {\
		bool ok;\
		type data;\
	} singular##_OK;\
	ARRAY_HELPER_CREATE_ARRAY_HEADER(plural, type, KP1_HELPER_MAX_ARRAY) \
	singular##_OK singular##_scan(FILE *KP1_HELPER_FILE_VARIABLE_NAME);\
	plural plural##_scan(FILE *KP1_HELPER_FILE_VARIABLE_NAME);\
	void singular##_print(FILE *KP1_HELPER_FILE_VARIABLE_NAME, type ins);\
	void plural##_print(FILE *KP1_HELPER_FILE_VARIABLE_NAME, plural inss);\

#endif
