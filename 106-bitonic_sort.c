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
 * bitonic_sort - sort array using bitonic method
 * @array: the array of the integer
 * @size: the size of the array
 * Return: always 0
 */

void bitonic_sort(int *array, size_t size)
{

	bitonic(array, 0, size, 1);

}

/**
 * bitonic - recursive bitonic function
 * @array: array of integer
 * @begin: index at the beginning
 * @size: size of the array
 * @new:sorting direction
 * Return: always 0
 */

void bitonic(int *array, int begin, int size, int new)
{
	if (size > 1)
	{

		int s = size / 2;

		printf("Merging [%d/%d] ", size, size);
		printf((new == 1) ? "(UP):\n" : "(DOWN):\n");
		print_array(array, size);

		bitonic(array, begin, s, new);
		bitonic(array, begin + s, s, -1);

		bitonic_merge(array, begin, size, new);

		printf("Result [%d/%d] ", size, size * 2);
		printf((new == 1) ? "(UP):\n" : "(DOWN):\n");
		print_array(array, size);

	}

}

/**
 * bitonic_merge - merge the bitonic sub arrays
 * @array: array of integers
 * @begin: index at the beginning
 * @s_size: size of the subarray
 * @new: sorting direction
 * Return: always 0
 */

void bitonic_merge(int *array, int begin, int size, int new)
{

	if (size > 1)
	{
		int s = size / 2;
		int i = 0;

		while (i < s)
		{

			if ((new == 1 && array[begin + i] > array[begin + i + s]) || (new == -1 && array[begin + i] < array[i + s]))
				int_swap(&array[begin + i], &array[begin + i + s]);

			i++;

		}


		bitonic_merge(array, begin, s, new);
		bitonic_merge(array, begin + s, s, new);
	}
}
