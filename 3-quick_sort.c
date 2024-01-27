#include "sort.h"

/**
 * swap - swaps two integer values
 * @a: pointer to the first value
 * @b: pointer to the second value
 *
 */
void swap(int *a, int *b)
{
	int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - partitions the array using the Lomuto scheme
 * @array: pointer to the array to be sorted
 * @size: array size
 * @lo: the low index of the sort range
 * @hi: the high index of the sort range
 *
 * Return: the partition index
 */
size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int pivot = array[hi];
    ssize_t i = lo - 1;
    ssize_t j;

    for (j = lo; j <= hi - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }
    swap(&array[i + 1], &array[hi]);
    print_array(array, size);
    return (i + 1);
}

/**
 * quicksort - sorts the array using the quicksort algorithm
 * @array: pointer to the array to be sorted
 * @size: array size
 * @lo: the low index of the sort range
 * @hi: the high index of the sort range
 *
 * Return: void
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	size_t p;

    if (lo < hi)
    {
        p = lomuto_partition(array, lo, hi, size);
        quicksort(array, lo, p - 1, size);
        quicksort(array, p + 1, hi, size);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the above function
 * @array: pointer to the array to be sorted
 * @size: array size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
    return;
    quicksort(array, 0, size - 1, size);
}
