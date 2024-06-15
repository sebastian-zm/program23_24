#include <stdio.h>
#include <stdlib.h>
#include "list_helper.h"

int LIST_HELPER_create(LIST_HELPER_NODE **list, void *data, LIST_HELPER_NODE *next)
{
	int ret = 1;
	*list = malloc(sizeof *list);
	if (*list) {
		(*list)->data = data;
		(*list)->next = next;
	} else {
		ret = 0;
	}
	return ret;
}

void LIST_HELPER_createOrExit(LIST_HELPER_NODE **list, void *data, LIST_HELPER_NODE *next, char *error)
{
	*list = malloc(sizeof *list);
	if (*list) {
		(*list)->data = data;
		(*list)->next = next;
	} else {
		fprintf(stderr, "%s\n", error);
		exit(EXIT_FAILURE);
	}
}

void *LIST_HELPER_shift(LIST_HELPER_NODE **list)
{
	void *ret = NULL;
	if (*list) {
		ret = (*list)->data;
		LIST_HELPER_NODE *tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
	return ret;
}

void LIST_HELPER_each(LIST_HELPER_NODE *list, void egin(void *))
{
	while (list) {
		egin(list->data);
		list = list->next;
	}
}

void LIST_HELPER_eachWith(LIST_HELPER_NODE *list, void egin(void *, void *), void *data)
{
	while (list) {
		egin(list->data, data);
		list = list->next;
	}
}

void *LIST_HELPER_find(LIST_HELPER_NODE *list, int test(void *))
{
	void *ret;
	while (list && !test(list->data)) {
		list = list->next;
	}
	if (list) {
		ret = list->data;
	} else {
		ret = NULL;
	}
	return ret;
}

void *LIST_HELPER_findDelete(LIST_HELPER_NODE **list, int test(void *))
{
	LIST_HELPER_NODE *prev = NULL;
	LIST_HELPER_NODE *current = *list;
	void *ret;
	while (current && !test(current->data)) {
		prev = current;
		current = current->next;
	}
	if (current) {
		if (prev) {
			prev->next = current->next;
		} else {
			*list = current->next;
		}
		ret = current->data;
		free(current);
	} else {
		ret = NULL;
	}

	return ret;
}

void *LIST_HELPER_findWith(LIST_HELPER_NODE *list, int test(void *, void *), void *data)
{
	void *ret;
	while (list && !test(list->data, data)) {
		list = list->next;
	}
	if (list) {
		ret = list->data;
	} else {
		ret = NULL;
	}
	return ret;
}

void LIST_HELPER_findEach(LIST_HELPER_NODE *list, int test(void *), void egin(void *))
{
	while (list) {
		if (test(list->data)) {
			egin(list->data);
		}
	}
}

void LIST_HELPER_findWithEach(LIST_HELPER_NODE *list, int test(void *, void *), void *testData, void egin(void *))
{
	while (list) {
		if (test(list->data, testData)) {
			egin(list->data);
		}
	}
}

void LIST_HELPER_findEachWith(LIST_HELPER_NODE *list, int test(void *), void egin(void *, void *), void *eginData)
{
	while (list) {
		if (test(list->data)) {
			egin(list->data, eginData);
		}
	}
}

void LIST_HELPER_findWithEachWith(LIST_HELPER_NODE *list, int test(void *, void *), void *testData, void egin(void *, void *), void *eginData)
{
	while (list) {
		if (test(list->data, testData)) {
			egin(list->data, eginData);
		}
	}
}

void LIST_HELPER_sortAsc(LIST_HELPER_NODE **list, int cmp(void *, void *))
{
	LIST_HELPER_NODE *prev = NULL;
	LIST_HELPER_NODE *current = *list;
	LIST_HELPER_NODE *elem = *list;

	while (*list && (*list)->next) {
		while (elem->next) {
			if (cmp(elem->next->data, current->data) < 0) {
				prev = elem;
				current = elem->next;
			}
			elem = elem->next;
		}
		
		if (prev) prev->next = current->next;
		current->next = *list;
		*list = current;
		list = &current->next; // Ezingo dugu berriro *list aldatu, baina berdin zait.
	}
}

void LIST_HELPER_sortDesc(LIST_HELPER_NODE **list, int cmp(void *, void *))
{
	LIST_HELPER_NODE *prev;
	LIST_HELPER_NODE *current;
	LIST_HELPER_NODE *elem;

	while (*list && (*list)->next) {
		prev = NULL;
		current = *list;
		elem = *list;
		while (elem->next) {
			if (cmp(elem->next->data, current->data) > 0) {
				prev = elem;
				current = elem->next;
			}
			elem = elem->next;
		}
		
		if (prev) prev->next = current->next;
		current->next = *list;
		*list = current;
		list = &current->next; // Ezingo dugu berriro *list aldatu, baina berdin zait.
	}
}

void LIST_HELPER_free(LIST_HELPER_NODE *list, void freeData(void *))
{
	LIST_HELPER_NODE *aux;
	while (list) {
		aux = list;
		list = list->next;
		freeData(aux->data);
		free(aux);
	}
}

void LIST_HELPER_keepIf(LIST_HELPER_NODE **list, int test(void *), void freeData(void *))
{
	LIST_HELPER_NODE *e = *list;
	LIST_HELPER_NODE *tmp = NULL;
	LIST_HELPER_NODE *current = NULL;
	*list = NULL;

	while (e) {
		if (test(e->data)) {
			if (current) {
				current->next = e;
			} else {
				*list = e;
			}
			current = e;
			e = e->next;
			current->next = NULL;
		} else {
			tmp = e;
			e = e->next;
			freeData(tmp->data);
			free(tmp);
		}
	}
}

