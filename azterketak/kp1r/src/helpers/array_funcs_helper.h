#ifndef ARRAY_FUNCS_HELPER_H
#define ARRAY_FUNCS_HELPER_H

#include <stddef.h>

void *ARRAY_FUNCS_HELPER_find(const void* arr, size_t len, size_t size, int test(void *));
void ARRAY_FUNCS_HELPER_each_with_obj(void *obj, void *arr, size_t len, size_t size, void do_with_obj(void *, void *));
void *ARRAY_FUNCS_HELPER_each_with_obj_abort(void *obj, void* arr, size_t len, size_t size, int test_with_obj(void *, void *));
void ARRAY_FUNCS_HELPER_keep_if(void *arr, size_t *len, size_t size, int keep(void *));
void* ARRAY_FUNCS_HELPER_min(const void *arr, size_t len, size_t size, int cmp(const void *, const void *));
void* ARRAY_FUNCS_HELPER_max(const void *arr, size_t len, size_t size, int cmp(const void *, const void *));
void ARRAY_FUNCS_HELPER_sort_asc(void *arr, size_t len, size_t size, int cmp(const void*, const void*));
void ARRAY_FUNCS_HELPER_sort_desc(void *arr, size_t len, size_t size, int cmp(const void*, const void*));

#endif
