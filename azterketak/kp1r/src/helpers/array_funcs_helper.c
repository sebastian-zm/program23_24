#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "array_funcs_helper.h"

void *ARRAY_FUNCS_HELPER_find(const void* arr, size_t len, size_t size, int test(void *))
{
	size_t i = 0;
	char *arr_c = (char *) arr;
	void *ret = arr_c;
	while (i < len && !test(arr_c)) {
		++i;
		arr_c += size;
		ret = arr_c;
	}

	return i == len ? NULL : ret;
}

void ARRAY_FUNCS_HELPER_each_with_obj(void *obj, void *arr, size_t len, size_t size, void do_with_obj(void *, void *))
{
	size_t i;
	char *arr_c = (char *) arr;

	for (i = 0; i < len; ++i) {
		do_with_obj(arr_c, obj);
		arr_c += size;
	}
}

void *ARRAY_FUNCS_HELPER_each_with_obj_abort(void *obj, void* arr, size_t len, size_t size, int test_with_obj(void *, void *))
{
	size_t i = 0;
	char *arr_c = (char *) arr;
	void *ret = arr_c;
	while (i < len && !test_with_obj(arr_c, obj)) {
		++i;
		arr_c += size;
		ret = arr_c;
	}

	return i == len ? NULL : ret;
}

void ARRAY_FUNCS_HELPER_keep_if(void *arr, size_t *len, size_t size, int keep(void *))
{
	size_t i = 0;
	ptrdiff_t diff = 0;

	char *arr_c = (char *) arr;

	for (i = 0; i < *len; ++i) {
		if (keep(arr_c)) {
			if (diff) memcpy(arr_c - diff, arr_c, size);
		} else {
			diff += size;
			--*len;
			--i;
		}
		arr_c += size;
	}
}

void* ARRAY_FUNCS_HELPER_min(const void *arr, size_t len, size_t size, int cmp(const void *, const void *))
{
	const void *ret = NULL;
	const char *curr = (const char *) arr;
	size_t i = 0;
	if (len) {
		ret = arr;
		for (i = 1; i < len; ++i) {
			curr += size;
			if (0 < cmp(ret, curr)) ret = curr;
		}
	}
	return (void *) ret;
}

void* ARRAY_FUNCS_HELPER_max(const void *arr, size_t len, size_t size, int cmp(const void *, const void *))
{
	const void *ret = NULL;
	const char *curr = (const char *) arr;
	size_t i = 0;
	if (len) {
		ret = arr;
		for (i = 1; i < len; ++i) {
			curr += size;
			if (0 > cmp(ret, curr)) ret = curr;
		}
	}
	return (void *) ret;
}

void ARRAY_FUNCS_HELPER_sort_asc(void *arr, size_t len, size_t size, int cmp(const void *, const void *))
{
	size_t i;
	char *curr = arr;
	char *toswap = arr;
	char buffer[size];

	for (i = len; i > 0; --i) {
		toswap = ARRAY_FUNCS_HELPER_min(curr, i, size, cmp); // i > 0; so not null
		memcpy(buffer, curr, size);
		memcpy(curr, toswap, size);
		memcpy(toswap, buffer, size);
		curr += size;
	}
}

void ARRAY_FUNCS_HELPER_sort_desc(void *arr, size_t len, size_t size, int cmp(const void *, const void *))
{
	size_t i;
	char *curr = arr;
	char *toswap = arr;
	char buffer[size];

	for (i = len; i > 0; --i) {
		toswap = ARRAY_FUNCS_HELPER_max(curr, i, size, cmp); // i > 0; so not null
		memcpy(buffer, curr, size);
		memcpy(curr, toswap, size);
		memcpy(toswap, buffer, size);
		curr += size;
	}
}
