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
 * heap_size - heap
 * @array: the array of integers
 * @size: size of the array
 * @i: index of the node
 * @space: the size of the array
 */

void heap_size(int *array, int size, int i, int space)
{
	int len = i;
	int right = 2 * i + 2;
	int left = 2 * i + 1;

	if (left < size && array[len] < array[left])
		len = left;

	if (right < size && array[len] < array[right])
		len = right;

	if (len != i)
	{
		int_swap(&array[i], &array[len]);
		print_array(array, space);
		heap_size(array, size, len, space);

	}
}

/**
 * heap_sort - sort via heap method
 * @array: the array of the integer
 * @size: size of the array
 * Return: always 0
 */

void heap_sort(int *array, size_t size)
{

	int i, len = (int)size;

	if (size < 2 || !array)
		return;

	for (i = len / 2 - 1; i >= 0; i--)
		heap_size(array, len, i, len);

	for (i = len - 1; i > 0; i--)
	{
		int_swap(&array[0], &array[i]);
		print_array(array, len);
		heap_size(array, i, 0, len);
	}

}