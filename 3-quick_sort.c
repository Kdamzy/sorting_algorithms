#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: array to be sorted.
 * @size: size of the array.
 */

void quick_sort(int *array, size_t size)
{

	if (size < 2)
		return;

	recuss_sort(array, 0, size - 1, size);
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

/**
 * partition - partitions an array
 * @array: The array to be sorted.
 * @first: The first element
 * @last: The last elment
 * @size: The size of the array.
 * Return: The index of the pivot element.
 */

int partition(int *array, int first, int last, size_t size)
{
    int pivot = array[last];
    int begin = first - 1;
	int c;

    for (c = first; c < last; c++)
    {
        if (array[c] <= pivot)
        {
            begin++;
            if (c != begin)
            {
        		int_swap(&array[begin], &array[c]);
                print_array(array, size);
            }
        }
    }

    begin++;
    int_swap(&array[begin], &array[last]);
    print_array(array, size);

    return (begin);
}


/**
 * recuss_sort - Recursively 
 * @array: The array to be sorted.
 * @small: the smallest value of the array.
 * @big: The biggest value of the array.
 * @size: The size of the array.
 * Return: void
 */

void recuss_sort(int *array, int small, int big, size_t size)
{

	int start;

	if (small < big)
	{
		start = partition(array, small, big, size);
		recuss_sort(array, small, start - 1, size);
		recuss_sort(array, start + 1, big, size);

	}
}