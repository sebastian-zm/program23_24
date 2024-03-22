#ifndef ARRAY_HELPER_H
#define ARRAY_HELPER_H

#define ARRAY_HELPER_CREATE_ARRAY_HEADER(prefix, type, size) \
	typedef struct prefix##_s {\
		type data[size];\
		int length;\
	} prefix;\
	prefix prefix##_create();\
	prefix prefix##_add(prefix arr, type elem);\
	prefix prefix##_insert(prefix arr, type elem, int idx);\
	prefix prefix##_remove(prefix arr, int idx);\
	type prefix##_get(prefix arr, int idx);\
	prefix prefix##_set(prefix arr, type elem, int idx);\
	int prefix##_length(prefix arr);\


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
	prefix prefix##_insert(prefix arr, type elem, int idx) {\
		if (arr.length < size) {\
			for (int i = arr.length - 1; i > idx; --i) {\
				arr.data[i + 1] = arr.data[i];\
			}\
			arr.data[idx] = elem;\
			++arr.length;\
		}\
		return arr;\
	}\
	prefix prefix##_remove(prefix arr, int idx) {\
		for (int i = idx + 1; i < arr.length; ++i) {\
			arr.data[i - 1] = arr.data[i];\
		}\
		--arr.length;\
		return arr;\
	}\
	type prefix##_get(prefix arr, int idx) {\
		return arr.data[idx];\
	}\
	prefix prefix##_set(prefix arr, type elem, int idx) {\
		arr.data[idx] = elem;\
		return arr;\
	}\
	int prefix##_length(prefix arr) {\
		return arr.length;\
	}\

#endif
