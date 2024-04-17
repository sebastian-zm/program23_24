#ifndef ARRAY_HELPER_H
#define ARRAY_HELPER_H

#include <stddef.h>
#include <stdlib.h>

#define ARRAY_HELPER_CREATE_ARRAY_HEADER(prefix, type, size) \
	typedef struct prefix##_s {\
		type data[size];\
		size_t length;\
	} prefix;\
	prefix prefix##_create();\
	prefix prefix##_add(prefix arr, type elem);\
	prefix prefix##_insert(prefix arr, type elem, size_t idx);\
	prefix prefix##_remove(prefix arr, size_t idx);\
	type prefix##_get(prefix arr, size_t idx);\
	prefix prefix##_set(prefix arr, type elem, size_t idx);\
	size_t prefix##_length(prefix arr);\
	int prefix##_find(prefix arr, type findme, int eq(type, type));\
	prefix prefix##_keep_if(prefix arr, int keep(type));\


#define ARRAY_HELPER_CREATE_ARRAY(prefix, type, size) \
	prefix prefix##_create() {\
		prefix ret;\
		ret.length = 0;\
		return ret;\
	}\
	prefix prefix##_add(prefix arr, type elem) {\
		if (arr.length < size) {\
			arr.data[arr.length++] = elem;\
		}\
		return arr;\
	}\
	prefix prefix##_insert(prefix arr, type elem, size_t idx) {\
		if (arr.length < size) {\
			for (size_t i = arr.length - 1; i > idx; --i) {\
				arr.data[i + 1] = arr.data[i];\
			}\
			arr.data[idx] = elem;\
			++arr.length;\
		}\
		return arr;\
	}\
	prefix prefix##_remove(prefix arr, size_t idx) {\
		for (size_t i = idx + 1; i < arr.length; ++i) {\
			arr.data[i - 1] = arr.data[i];\
		}\
		--arr.length;\
		return arr;\
	}\
	type prefix##_get(prefix arr, size_t idx) {\
		return arr.data[idx];\
	}\
	prefix prefix##_set(prefix arr, type elem, size_t idx) {\
		arr.data[idx] = elem;\
		return arr;\
	}\
	size_t prefix##_length(prefix arr) {\
		return arr.length;\
	}\
	int prefix##_min(prefix arr, int cmp(type, type)) {\
		int ret = 0;\
		for (size_t i = 1; i < arr.length; ++i) {\
			if (0 < cmp(arr.data[i - 1], arr.data[i])) ret = i;\
		}\
		return ret;\
	}\
	int prefix##_find(prefix arr, type findme, int eq(type, type)) {\
		int ret = 0;\
		while ((size_t) ret < arr.length && !eq(arr.data[ret], findme)) {\
			++ret;\
		}\
		if ((size_t) ret >= arr.length) ret = -1;\
		return ret;\
	}\
	prefix prefix##_keep_if(prefix arr, int keep(type)) {\
		size_t diff = 0;\
		for (size_t i = 0; i < arr.length; ++i) {\
			if (keep(arr.data[i])) {\
				if (diff) arr.data[i - diff] = arr.data[i];\
			} else {\
				++diff;\
				--arr.length;\
			}\
		}\
		return arr;\
	}\

#endif
