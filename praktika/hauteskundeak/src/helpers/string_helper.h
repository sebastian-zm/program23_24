#ifndef STRING_HELPER_H
#define STRING_HELPER_H

void *STRING_HELPER_memcpy(void *dest, const void *src, size_t num);
void *STRING_HELPER_memmove(void *dst, const void *src, size_t num);
char *STRING_HELPER_strcpy(char *dst, const char *src);
char *STRING_HELPER_strncpy(char *dst, const char *src, size_t num);
char *STRING_HELPER_seb_strncpy(char *dst, const char *src, size_t num);
char *STRING_HELPER_strcat(char *dst, const char *src);
char *STRING_HELPER_strncat(char *dst, const char *src, size_t num);
char *STRING_HELPER_seb_strncat(char *dst, const char *src, size_t num);


#endif
