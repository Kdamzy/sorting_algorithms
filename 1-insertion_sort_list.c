#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list 
 * @list: pointer to the head of the list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *element, *last;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    node = (*list)->next;

    while (node != NULL)
    {
        element = node;

        while (element->prev != NULL && element->prev->n > element->n)
        {
            last = element->prev;

            last->next = element->next;
            if (element->next)
                element->next->prev = last;

            element->next = last;
            element->prev = last->prev;
            last->prev = element;

            if (element->prev)
                element->prev->next = element;
            else
                *list = element;

            print_list(*list);
        }

        node = node->next;
    }
}
