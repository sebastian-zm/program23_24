#include <stddef.h>
#include "string_helper.h"

void *STRING_HELPER_memcpy(void *dst, const void *src, size_t num)
{
	unsigned char *dst_c = dst;
	const unsigned char *src_c = src;

	if (num) {
		*(dst_c + num - 1) = *(src_c + num - 1);
		STRING_HELPER_memcpy(dst, src, num - 1);
	}

	return dst;
}


void *STRING_HELPER_memmove(void *dst, const void *src, size_t num)
{
	unsigned char *dst_c = dst;
	const unsigned char *src_c = src;

	if (dst < src && num) {
		*dst_c = *src_c;
		STRING_HELPER_memmove(dst_c + 1, src_c + 1, num - 1);
	} else if (dst > src && num) {
		*(dst_c + num - 1) = *(src_c + num - 1);
		STRING_HELPER_memmove(dst_c, src_c, num - 1);
	}

	return dst;
}


char *STRING_HELPER_strcpy(char *dst, const char *src)
{
	*dst = *src;
	if (*src) {
		STRING_HELPER_strcpy(dst + 1, src + 1);
	}
	return dst;
}


char *STRING_HELPER_strncpy(char *dst, const char *src, size_t num)
{
	if (num == 1) {
		*dst = '\0';
	} else if (num) {
		*dst = *src;
		STRING_HELPER_strncpy(dst + 1, src + 1, num - 1);
	}
	return dst;
}


char *STRING_HELPER_strcat(char *dst, const char *src)
{
	char *dst_b = STRING_HELPER_strchr(dst, '\0');
	STRING_HELPER_strcpy(dst_b, src);
	return dst;
}


char *STRING_HELPER_strncat(char *dst, const char *src, size_t num)
{
	size_t len = STRING_HELPER_strlen(dst);
	if (num > len) {
		STRING_HELPER_strncpy(dst + len, src, num - len);
	}
	return dst;
}


int STRING_HELPER_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char *ptr1_c = ptr1;
	const unsigned char *ptr2_c = ptr2;
	int ret;
	if (!num) {
		ret = 0;
	} else if (*ptr1_c > *ptr2_c) {
		ret = 1;
	} else if (*ptr1_c == *ptr2_c) {
		ret = STRING_HELPER_memcmp(ptr1_c + 1, ptr2_c + 1, num - 1);
	} else {
		ret = -1;
	}
	return ret;
}


int STRING_HELPER_strcmp(const char *str1, const char *str2)
{
	int ret;
	if (*str1 > *str2) {
		ret = 1;
	} else if (*str1 < *str2) {
		ret = -1;
	} else if (*str1 == '\0') {
		ret = 0;
	} else {
		ret = STRING_HELPER_strcmp(str1 + 1, str2 + 1);
	}
	return ret;
}


int STRING_HELPER_strncmp(const char *str1, const char *str2, size_t num)
{
	int ret;
	if (!num) {
		ret = 0;
	}
	if (*str1 > *str2) {
		ret = 1;
	} else if (*str1 < *str2) {
		ret = -1;
	} else if (*str1 == '\0') {
		ret = 0;
	} else {
		ret = STRING_HELPER_strncmp(str1 + 1, str2 + 1, num - 1);
	}
	return ret;
}


void *STRING_HELPER_memchr(const void *ptr, int value, size_t num)
{
	void *ret;
	const unsigned char *ptr_c = ptr;
	if (!num) {
		ret = NULL;
	} else if (*ptr_c == (unsigned char) value) {
		ret = (void *) ptr;
	} else {
		ret = STRING_HELPER_memchr(ptr_c + 1, value, num - 1);
	}
	return ret;
}


char *STRING_HELPER_strchr(const char *ptr, int c)
{
	char *ret;
	if (*ptr == (char) c) {
		ret = (char *) ptr;
	} else if (!*ptr) {
		ret = NULL;
	} else {
		ret = STRING_HELPER_strchr(ptr + 1, c);
	}
	return ret;
}


size_t STRING_HELPER_strcspn(const char *str1, const char *str2)
{
	size_t ret;
	if (STRING_HELPER_strchr(str2, *str1)) {
		ret = 0;
	} else {
		ret = 1 + STRING_HELPER_strcspn(str1 + 1, str2);
	}
	return ret;
}


char *STRING_HELPER_strpbrk(const char *str1, const char *str2)
{
	char *ret;
	if (*str1 == '\0') {
		ret = NULL;
	} else if (STRING_HELPER_strchr(str2, *str1)) {
		ret = (char *) str1;
	} else {
		ret = STRING_HELPER_strpbrk(str1 + 1, str2);
	}
	return ret;
}


char *STRING_HELPER_strrchr(const char *str, int chr)
{
	char *ret = NULL;
	if (*str) {
		ret = STRING_HELPER_strrchr(str + 1, chr);
	}
	if (!ret && (char) chr == *str) {
		ret = (char *) str;
	}
	return ret;
}


size_t STRING_HELPER_strspn(const char *str1, const char *str2)
{
	size_t ret;
	if (!STRING_HELPER_strchr(str2, *str1)) {
		ret = 0;
	} else {
		ret = 1 + STRING_HELPER_strspn(str1 + 1, str2);
	}
	return ret;
}


void *STRING_HELPER_memset(void *ptr, int val, size_t num)
{
	unsigned char *ptr_c = ptr;
	if (num) {
		STRING_HELPER_memset(ptr, val, num - 1);
		*(ptr_c + num - 1) = (unsigned char) val;
	}
	return ptr;
}


size_t STRING_HELPER_strlen(const char *str)
{
	size_t ret;
	if (!*str) {
		ret = 1 + STRING_HELPER_strlen(str + 1);
	} else {
		ret = 0;
	}
	return ret;
}

