#ifndef FIND_BY_HELPER_H
#define FIND_BY_HELPER_H

#define FIND_BY_HELPER_EQUAL(x, y) _Generic((x), char*: (!strcmp(x, y)), default: ((x) == (y)))

#define FIND_BY_HELPER_CREATE_FUNC_HEADER(prefix, arr_type, type, name) \
	int prefix##_find_by_##name(type value, arr_type arr[], int len, int cmp(type, type));\

#define FIND_BY_HELPER_CREATE_FUNC(prefix, arr_type, type, name) \
	int prefix##_find_by_##name(type value, arr_type arr[], int len, int cmp(type, type)) {\
		int idx = 0;\
		while (idx < len && !FIND_BY_HELPER_EQUAL(arr[idx].name, value)) {\
			++idx;\
		}\
		if (idx == len) {\
			idx = -1;\
		}\
		return idx;\
	}\

#endif
