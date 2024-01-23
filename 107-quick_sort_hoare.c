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

/**
 * quick_sort_hoare- sorting via quick sort method
 * @array: int
 * @size: size_t
 * Return: always 0
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_sort(array, 0, size - 1, size);
}

/**
 * hoare_partition- partition function to sort using quicksort
 * @array: int
 * @start: int
 * @end: int
 * @size: size_t
 * Return: int
 */

int hoare_partition(int *array, int start, int end, int size)
{
	int present = start - 1, pivot = array[end];
	int prev = end + 1;


	while (present < prev)
	{
		do
		{
			present++;
		}
		while (array[present] < pivot);

		do
		{
			prev--;
		}
		while (array[prev] > pivot);

		if (prev > present)
		{

			int_swap(&array[present], &array[prev]);
			print_array(array, size);
		}


	}
	return (present);
}

/**
 * hoare_sort- using this function recursively to call partitioner
 * @array: int
 * @start: int
 * @end: int
 * @size: size_t
 * Return: always 0
 */

void hoare_sort(int *array, int start, int end, size_t size)
{

	int pivot;

	if (start < end)
	{
		pivot = hoare_partition(array, start, end, size);
		hoare_sort(array, start, pivot - 1, size);
		hoare_sort(array, pivot, end, size);

	}


}
