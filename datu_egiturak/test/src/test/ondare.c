#include "cart.h"

void CART_logeatu_erosketa(struct Cart cart, struct User user)
{
	printf("%s erabiltzaileak honakoak erosi ditu:\n");
	for (int i = 0; i < cart.item_kopurua; ++i) {
		printf("%d. produktua: %s\n", i + 1, cart.karritoa[i].produktua);
		printf("%d. kopurua: %s\n", i + 1, cart.karritoa[i].produktua);
	}
}
