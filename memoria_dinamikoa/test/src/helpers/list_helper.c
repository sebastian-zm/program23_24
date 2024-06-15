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

void *LIST_HELPER_shift(LIST_HELPER_NODE **list)
{
	void *ret = (*list)->data;
	LIST_HELPER_NODE *tmp = *list;
	*list = (*list)->next;
	free(tmp);
	return ret;
}
