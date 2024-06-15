#ifndef TIME_HELPER_H
#define TIME_HELPER_H

typedef struct TIME_HELPER_DATE_s {
	int day; // 1-31
	int month; // 1-12
	int year;
} TIME_HELPER_DATE;

typedef struct TIME_HELPER_TIME_s {
	int hour;
	int min;
	int sec;
} TIME_HELPER_TIME;

int TIME_HELPER_DATE_cmp(TIME_HELPER_DATE d1, TIME_HELPER_DATE d2);
int TIME_HELPER_DATE_elapsed(TIME_HELPER_DATE start, TIME_HELPER_DATE end);

int TIME_HELPER_TIME_cmp(TIME_HELPER_TIME t1, TIME_HELPER_TIME t2);
int TIME_HELPER_TIME_elapsed(TIME_HELPER_TIME start, TIME_HELPER_TIME end);

#endif
