#include "sort.h"
#include <stdio.h>

/**
 * size_merge -  Sort an array
 * @array: array if integers
 * @lef: pointer to left array
 * @rig: pointer to right array
 * @size: size of the array
 **/
void size_merge(int *array, int *lef, int *rig, size_t size)
{
    int i = 0, j = 0, k = 0;
    int left = size / 2;
    int right = size - left;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(lef, left);
    printf("[right]: ");
    print_array(rig, right);

    while (i < left && j < right)
    {
        array[k++] = (lef[i] < rig[j]) ? lef[i++] : rig[j++];
    }

    while (i < left)
    array[k++] = lef[i++];
    
    while (j < right)
    array[k++] = rig[j++];

    printf("[Done]: ");
    print_array(array, size);
}

/**
 * merge_sort - sorts an array of integers in
 * ascending order using the Merge sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
    size_t inn = size / 2;
    int left[1000];
    int right[1000];
    size_t i;

    if (!array || size < 2)
        return;

    for (i = 0; i < inn; i++)
        left[i] = array[i];

    for (i = inn; i < size; i++)
        right[i - inn] = array[i];

    merge_sort(left, inn);
    merge_sort(right, size - inn);
    size_merge(array, left, right, size);
}