#include "time_helper.h"

int TIME_HELPER_DATE_cmp(TIME_HELPER_DATE d1, TIME_HELPER_DATE d2)
{
	int ret;
	if (d1.year > d2.year) {
		ret = 1;
	} else if (d1.year < d2.year) {
		ret = -1;
	} else if (d1.month > d2.month) {
		ret = 1;
	} else if (d1.month < d2.month) {
		ret = -1;
	} else if (d1.day > d2.day) {
		ret = 1;
	} else if (d1.day < d2.day) {
		ret = -1;
	} else {
		ret = 0;
	}

	return ret;
}

int TIME_HELPER_leapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int TIME_HELPER_DATE_diff(TIME_HELPER_DATE d1, TIME_HELPER_DATE d2)
{
	TIME_HELPER_DATE d[2] = {d1, d2};
	int days[2] = {0, 0};
	const int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year, month;
	int miny = d1.year < d2.year ? d1.year : d2.year;

	for (int i = 0; i < 2; ++i) {
		month = 0;
		for (year = miny; year < d[i].year; ++year) {
			if (TIME_HELPER_leapYear(year)) {
				days[i] += 366;
			} else {
				days[i] += 365;
			}
		}
		while (month < d[i].month && month <= 12) {
			days[i] += months[month - 1];
			++month;
		}
		if (month > 2 && TIME_HELPER_leapYear(d[i].year)) {
			++days[i];
		}
		days[i] += d[i].day;
	}
	return days[1] - days[0];
}

int TIME_HELPER_TIME_cmp(TIME_HELPER_TIME t1, TIME_HELPER_TIME t2)
{
	int ret;
	if (t1.hour > t2.hour) {
		ret = 1;
	} else if (t1.hour < t2.hour) {
		ret = -1;
	} else if (t1.min > t2.min) {
		ret = 1;
	} else if (t1.min < t2.min) {
		ret = -1;
	} else if (t1.sec > t2.sec) {
		ret = 1;
	} else if (t1.sec < t2.sec) {
		ret = -1;
	} else {
		ret = 0;
	}

	return ret;
}

int TIME_HELPER_TIME_diff(TIME_HELPER_TIME t1, TIME_HELPER_TIME t2)
{
	return 60 * (60 * (t2.hour - t1.hour) + t2.min - t1.min) + t2.sec - t1.sec;
}

