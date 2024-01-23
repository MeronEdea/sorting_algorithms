#ifndef _SORT_H
#define _SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);

#endif