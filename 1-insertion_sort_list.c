#include "sort.h"
/**
 *insertion_sort_list - sorts a doubly linked list
 *using insertion sort algorithm
 *
 *@list: Structure list
 *
 */
void insertion_sort_list(listint_t **list) {
    if (*list == NULL || (*list)->next == NULL)
        return;

    listint_t *sorted = NULL;
    listint_t *current = *list;

    while (current != NULL) {
        listint_t *next = current->next;

        if (sorted == NULL || current->n < sorted->n) {
            current->next = sorted;
            current->prev = NULL;

            if (sorted != NULL)
                sorted->prev = current;

            sorted = current;
        }
        else {
            listint_t *temp = sorted;

            while (temp != NULL && temp->n < current->n)
                temp = temp->next;

            current->prev = temp->prev;
            current->next = temp;

            if (temp->prev != NULL)
                temp->prev->next = current;

            temp->prev = current;
        }

        current = next;

        while (sorted != NULL) {
        printf("%d ", sorted->n);
        sorted = sorted->next;
    }
    }

    *list = sorted;
}
