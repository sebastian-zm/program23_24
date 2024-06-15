#ifndef VECTOR_HELPER_H
#define VECTOR_HELPER_H

#include <stdlib.h>
#include <string.h>

#define VECTOR_HELPER_DEFAULT_SIZE 8

#define VECTOR_HELPER_CREATE_VECTOR_HEADER(prefix, type) \
	typedef struct {\
		type* data;\
		int length;\
		int size;\
	} prefix;\
	prefix* prefix##_create();\
	void prefix##_destroy(prefix* v);\
	int prefix##_add(prefix* v, type elem);\
	int prefix##_remove(prefix* v, int idx);\
	type prefix##_get(prefix* v, int idx);\
	void prefix##_set(prefix* v, type elem, int idx);\
	int prefix##_length(prefix* v);\

#define VECTOR_HELPER_CREATE_VECTOR(prefix, type) \
	prefix* prefix##_create() {\
		prefix* ret;\
		ret = malloc(sizeof(*ret));\
		if (ret) {\
			ret->data = malloc(VECTOR_HELPER_DEFAULT_SIZE * sizeof(type));\
			ret->length = 0;\
			ret->size = VECTOR_HELPER_DEFAULT_SIZE;\
			if (!ret->data) {\
				free(ret);\
				ret = NULL;\
			}\
		}\
		return ret;\
	}\
	void prefix##_destroy(prefix* v) {\
		free(v->data);\
		free(v);\
	}\
	int prefix##_add(prefix* v, type elem) {\
		type* tmp;\
		int ret = 1;\
		if (v->length < v->size) {\
			v->data[v->length++] = elem;\
		} else if (v->size == 0) {\
			tmp = realloc(v->data, VECTOR_HELPER_DEFAULT_SIZE * sizeof(type));\
			if (!tmp) {\
				ret = 0;\
			} else {\
				v->size = VECTOR_HELPER_DEFAULT_SIZE;\
				v->data = tmp;\
				v->data[v->length++] = elem;\
			}\
		} else {\
			tmp = realloc(v->data, 2 * v->size * sizeof(type));\
			if (!tmp) {\
				ret = 0;\
			} else {\
				v->data = tmp;\
				v->size *= 2;\
				v->data[v->length++] = elem;\
			}\
		}\
		return ret;\
	}\
	int prefix##_remove(prefix* v, int idx) {\
		type* tmp;\
		int ret = 1;\
		if (idx < 0 || idx >= v->length) {\
			ret = 0;\
		} else if (v->length >= v->size / 2) {\
			memmove(&v->data[idx], &v->data[idx+1], (--v->length - idx) * sizeof(type));\
		} else {\
			tmp = realloc(v->data, v->size / 2 * sizeof(type));\
			if (!tmp) {\
				ret = 0;\
			} else {\
				v->size /= 2;\
				v->data = tmp;\
				memmove(&v->data[idx], &v->data[idx+1], (--v->length - idx) * sizeof(type));\
			}\
		}\
		return ret;\
	}\
	type prefix##_get(prefix* v, int idx) {\
		return v->data[idx];\
	}\
	void prefix##_set(prefix* v, type elem, int idx) {\
		v->data[idx] = elem;\
	}\
	int prefix##_length(prefix* v) {\
		return v->length;\
	}\


#endif				// VECTOR_HELPER_H
