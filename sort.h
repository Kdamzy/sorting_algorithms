#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>


/**
 *struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */


typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*function prototype*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
int partition(int *array, int first, int last, size_t size);
void int_swap(int *m, int *n);
void recuss_sort(int *array, int small, int big, size_t size);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void size_merge(int *array, int *lef, int *rig, size_t size);
void counting_sort(int *array, size_t size);
void heap_size(int *array, int size, int i, int space);
void heap_sort(int *array, size_t size);
int find_largest(int *array, size_t size);
void radix_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void bitonic(int *array, int begin, int size, int new);
void bitonic_merge(int *array, int begin, int size, int new);
void insertion_sort_list(listint_t **list);
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, int start, int end, int size);
void hoare_sort(int *array, int start, int end, size_t size);


#endif