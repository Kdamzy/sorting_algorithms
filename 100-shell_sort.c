#include "sort.h"
/**
 * shell_sort - Sorts an array of integers 
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;

	if (array == NULL || size < 2)
		return;

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i; j < size - gap; j += gap)
			{
				while (j >= gap && array[j - gap] > array[j])
				{
					int_swap(&array[j - gap], &array[j]);
					j -= gap;
				}
			}
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}

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