#include "sort.h"

/**
 * find_largest - Find the largest number in an array.
 * @array: array of integers.
 * @size: size of the array.
 * Return: The largest number in the array.
 */

int find_largest(int *array, size_t size)
{
	size_t a;
	int big = array[0];

	for (a = 1; a < size; a++)
	{
		if (array[a] > big)
		{
			big = array[a];
		}
	}
	return (big);
}


/**
 * radix_sort - Sort an array of integers
 * @array: the array of integers
 * @size: The size of the array.
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int *count, *new;
	size_t a, big, i = 1;

	if (array == NULL || size < 2)
		return;

	big = find_largest(array, size);

	count = malloc((sizeof(int) * 10));
	if (count == NULL)
		return;
	new = malloc(size * sizeof(int));

	while (i <= big)
	{
		for (a = 0; a < 10; a++)
			count[a] = 0;

		for (a = 0; a < size; a++)
		{
			count[(array[a] / i) % 10]++;
		}
		for (a = 1; a < 10; a++)
			count[a] += count[a - 1];

		for (a = size; a > 0; a--)
		{
			new[count[(array[a - 1] / i) % 10] - 1] = array[a - 1];
			count[(array[a - 1] / i) % 10]--;
		}
		for (a = 0; a < size; a++)
		{
			array[a] = new[a];
		}
		i *= 10;
		print_array(array, size);
	}
	free(new);
	free(count);
}
