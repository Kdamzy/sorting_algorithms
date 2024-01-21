#include "sort.h"
/**
 * int_swap - Swaps two elements in an array.
 * @m: first int to be swapped.
 * @n: second int to be swapped.
 */

void int_swap(int *m, int *n)
{
	int temp;

	temp = *m;
	*m = *n;
	*n = temp;
}