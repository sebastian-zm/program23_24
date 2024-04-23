#include <stddef.h>
#include "string_helper.h"

void *STRING_HELPER_memcpy(void *dst, const void *src, size_t num)
{
	size_t i;

	unsigned char *dst_c = dst;
	const unsigned char *src_c = src;

	for (i = 0; i < num; ++i) {
		*(dst_c + i) = *(src_c + i);
	}

	return dst;
}

void *STRING_HELPER_memmove(void *dst, const void *src, size_t num)
{
	size_t i;

	unsigned char *dst_c = dst;
	const unsigned char *src_c = src;

	if (dst < src) {
		for (i = 0; i < num; ++i) {
			*(dst_c + i) = *(src_c + i);
		}
	} else if (dst > src) {
		for (i = num; i > 0; --i) {
			*(dst_c + i - 1) = *(src_c + i - 1);
		}
	}

	return dst;
}

char *STRING_HELPER_strcpy(char *dst, const char *src)
{
	ptrdiff_t i = -1;
	while (*(src + i) != '\0') {
		++i;
		*(dst + i) = *(src + i);
	}
	return dst;
}

char *STRING_HELPER_strncpy(char *dst, const char *src, size_t num)
{
	size_t i = 0;
	while (i < num && *(src + i) != '\0') {
		*(dst + i) = *(src + i);
		++i;
	}
	for (i = i; i < num; ++i) {
		*(dst + i) = '\0';
	}
	return dst;
}

char *STRING_HELPER_seb_strncpy(char *dst, const char *src, size_t num)
{
	size_t i = 0;
	if (num) {
		while (*(src + i) != '\0' && i < num - 1) {
			*(dst + i) = *(src + i);
			++i;
		}
		*(dst + i) = '\0';
	}
	return dst;
}

char *STRING_HELPER_strcat(char *dst, const char *src)
{
	size_t i = 0;
	size_t j = 0;
	while (*(dst + i) != '\0') {
		++i;
	}
	while (*(src + j) != '\0') {
		*(dst + i + j) = *(src + j);
		++j;
	}
	*(dst + i + j) = '\0';

	return dst;
}

char *STRING_HELPER_strncat(char *dst, const char *src, size_t num)
{
	size_t i = 0;
	size_t j = 0;
	if (num) {
		while (*(dst + i) != '\0') {
			++i;
		}
		while (*(src + j) != '\0' && j < num - 1) {
			*(dst + i + j) = *(src + j);
			++j;
		}
		*(dst + i + j) = '\0';
	}
	return dst;
}

char *STRING_HELPER_seb_strncat(char *dst, const char *src, size_t num)
{
	size_t i = 0;
	size_t j = 0;
	if (num) {
		while (*(dst + i) != '\0' && i < num - 1) {
			++i;
		}
		while (*(src + j) != '\0' && i + j < num - 1) {
			*(dst + i + j) = *(src + j);
			++j;
		}
		*(dst + i + j) = '\0';
	}
	return dst;
}

int string_helper_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t i = 0;
	int ret = 0;
	const unsigned char *ptr1_c = ptr1;
	const unsigned char *ptr2_c = ptr2;
	while (i < num && !ret) {
		if (*(ptr1_c + i) > *(ptr2_c + i)) ret = 1;
		else if (*(ptr1_c + i) < *(ptr2_c + i)) ret = -1;
		++i;
	}
	return ret;
}

int string_helper_strcmp(const char *ptr1, const char *ptr2, size_t num)
{
	size_t i = 0;
	int ret = 0;
	while (i < num && !ret && (*ptr1 || *ptr2)) {
		if (*(ptr1 + i) > *(ptr2 + i)) ret = 1;
		else if (*(ptr1 + i) < *(ptr2 + i)) ret = -1;
		++i;
	}
	return ret;
}
