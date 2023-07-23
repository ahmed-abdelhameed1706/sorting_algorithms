#include "sort.h"

/**
 * selection_sort - sorts an array with selection algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest])
			{
				smallest = j;
			}
		}

		temp = array[i];
		array[i] = array[smallest];
		array[smallest] = temp;
		print_array(array, size);
	}
}
