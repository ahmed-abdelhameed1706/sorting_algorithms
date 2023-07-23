#include "sort.h"

/**
 * bubble_sort - function to bubble sort an array
 * @array: array of ints to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int temp, sorted_flag = 0;
	size_t i;

	if (size < 2)
		return;

	while (sorted_flag == 0)
	{
		sorted_flag = 1;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				sorted_flag = 0;
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
