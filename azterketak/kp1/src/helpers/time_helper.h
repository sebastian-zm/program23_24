#ifndef TIME_HELPER_H
#define TIME_HELPER_H

typedef struct TIME_HELPER_DATE_s {
	int day;
	int month;
	int year;
} TIME_HELPER_DATE;

typedef struct TIME_HELPER_TIME_s {
	int hour;
	int min;
} TIME_HELPER_TIME;

int TIME_HELPER_DATE_cmp(TIME_HELPER_DATE d1, TIME_HELPER_DATE d2);
int TIME_HELPER_TIME_cmp(TIME_HELPER_TIME d1, TIME_HELPER_TIME d2);

#endif
