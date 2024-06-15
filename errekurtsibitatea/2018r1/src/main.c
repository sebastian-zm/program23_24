#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int handiena(int arr[], int len);

int main()
{
	int arr[] = {1,2,-40,10};
	int kop = 4;
	printf("%d ", handiena(arr, kop));
	printf("%d ", handiena(arr, 3));
	printf("%d ", handiena(arr, 0));
}

int handiena(int arr[], int len)
{
	if (len == 0) return INT_MIN;
	int max = handiena(arr + 1, len - 1);
	return max > *arr ? max : *arr;
}

