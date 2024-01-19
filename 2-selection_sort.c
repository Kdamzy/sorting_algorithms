#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in
 * ascending order
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t a, num;
    int index, temp;

    if (size < 2)
    {
        return;
    }

    a = 0;

    while (a < size - 1)
    {
        num = a + 1;
        index = a;

        while (num < size)
        {
            if (array[num] < array[index])
                index = num;

            num++;
        }

        if (array[a] != array[index])
        {
            temp = array[a];
            array[a] = array[index];
            array[index] = temp;
            print_array(array, size);
        }

        a++;
    }
}