#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of array to be sorted
 * Return: always 0
 */
void counting_sort(int *array, size_t size)
{
	int *count, *copy;
	size_t i, j;

	if (!array || size < 2)
		return;

	/* Find the largest element in the array */
	for (i = 1, j = array[0]; i < size; i++)
	{
		if ((size_t)array[i] > j)
			j = array[i];
	}

	count = malloc((j + 1) * sizeof(int));
	if (count == NULL)
		return;

	copy = malloc(size * sizeof(int));
	if (copy == NULL)
	{
		free(count);
		return;
	}
		
	for (i = 0; i < j + 1; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i < j + 1; i++)
		count[i] = count[i] + count[i - 1];

	print_array(count, j + 1);

	for (i = 0; i < size; i++)
	{
		copy[i] = array[i];
	}

	for (i = 0; i < size; i++)
	{
		copy[count[copy[i]] - 1] = copy[i];
		count[copy[i]]--;
	}


	free(copy);
	free(count);
}
