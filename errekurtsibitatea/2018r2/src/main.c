#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void eskilara(int n);
void lerro(int n);

int main()
{
	eskilara(3);
	eskilara(1);
	eskilara(0);
}

void eskilara(int n)
{
	if (n == 0) return;
	eskilara(n - 1);
	lerro(n);
	printf("\n");
}

void lerro(int n)
{
	if (n == 0) return;
	printf("*");
	lerro(n - 1);
}
