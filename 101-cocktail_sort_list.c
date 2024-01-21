#include "sort.h"
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
    listint_t *temp;

    if (list == NULL || *list == NULL)
        return;

    temp = *list;
    while (swapped != 0)
    {
        swapped = 0;
        while (temp->next != NULL)
        {
            if (temp->next->n < temp->n)
            {
                swap_nodes(list, temp, temp->next);
                swapped = 1;
                print_list(*list);
            }
            else
            {
                temp = temp->next;
            }
        }

        if (swapped == 0)
            break;

        swapped = 0;
        while (temp->prev != NULL)
        {
            if (temp->prev->n > temp->n)
            {
                swap_nodes(list, temp->prev, temp);
                swapped = 1;
                print_list(*list);
            }
            else
            {
                temp = temp->prev;
            }
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the linked list.
 * @node1: First node to swap.
 * @node2: Second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (list == NULL || *list == NULL || node1 == NULL || node2 == NULL)
        return;

    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}