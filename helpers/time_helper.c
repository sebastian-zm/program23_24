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
	} else {
		ret = 0;
	}

	return ret;
}

int TIME_HELPER_TIME_elapsed(TIME_HELPER_TIME start, TIME_HELPER_TIME end)
{
	return 60 * (end.hour - start.hour) + end.min - start.min;
	
}

