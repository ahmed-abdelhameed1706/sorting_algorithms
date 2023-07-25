#include "sort.h"

/**
 * quick_sort - sorts an array using quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	int start = 0, end = size - 1;

	if (size < 2)
		return;

	quick_sort_function(array, start, end, size);
}

/**
 * lomuto - partitioning the array using the lomotu scheme
 * @array: array to be partitioned
 * @start: start of the array
 * @end: end of the array
 * @size: array size to be passed to print_Array
 * Return: index of the pivot
 */
int lomuto(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start - 1, j, temp;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	i++;
	temp = array[i];
	array[i] = array[end];
	array[end] = temp;
	print_array(array, size);
	return (i);
}


/**
 * quick_sort_function - sorts the array recursively
 * @array: array to be sorted
 * @start: start of the array
 * @end: end of the array
 * @size: array size to be passed to print_array
 * Return: nothing
 */
void quick_sort_function(int *array, int start, int end, size_t size)
{
	int pivot_index;

	if (end <= start)
		return;

	pivot_index = lomuto(array, start, end, size);

	quick_sort_function(array, start, pivot_index - 1, size);
	quick_sort_function(array, pivot_index + 1, end, size);
}
