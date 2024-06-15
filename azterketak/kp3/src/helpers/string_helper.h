#ifndef STRING_HELPER_H
#define STRING_HELPER_H

#define STRING_HELPER_MAX_STR 100

#include <stddef.h>

void *STRING_HELPER_memcpy(void *dest, const void *src, size_t num);
void *STRING_HELPER_memmove(void *dst, const void *src, size_t num);
char *STRING_HELPER_strcpy(char *dst, const char *src);
char *STRING_HELPER_strncpy(char *dst, const char *src, size_t num);
char *STRING_HELPER_strcat(char *dst, const char *src);
char *STRING_HELPER_strncat(char *dst, const char *src, size_t num);
int STRING_HELPER_memcmp(const void *ptr1, const void *ptr2, size_t num);
int STRING_HELPER_strcmp(const char *str1, const char *str2);
int STRING_HELPER_strncmp(const char *str1, const char *str2, size_t num);
void *STRING_HELPER_memchr(const void *ptr, int value, size_t num);
char *STRING_HELPER_strchr(const char *ptr, int c);
size_t STRING_HELPER_strcspn(const char *str1, const char *str2);
char *STRING_HELPER_strpbrk(const char *str1, const char *str2);
char *STRING_HELPER_strrchr(const char *str, int chr);
size_t STRING_HELPER_strspn(const char *str1, const char *str2);

void *STRING_HELPER_memset(void *ptr, int val, size_t num);
size_t STRING_HELPER_strlen(const char *str);


#endif
