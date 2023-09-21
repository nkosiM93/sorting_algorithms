#include "sort.h"

/**
 * bubble_sort - Function that implements the bubble sort alogrithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size < 2)
		return;
	if (sort_check(array, size)) /*Check if array is sorted already*/
		return;

	for (i = 0; i < size; i++)
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
				if (sort_check(array, size)) /*Check if array is sorted*/
					return;
			}
		}
}

/**
 * sort_check - checks if array is completely sorted
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * Return: True or 1 if completely sorted, false otherwise
 */

int sort_check(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{ /*Check if array is already sorted*/
		if (array[i] > array[i + 1])
			return (0);
	}
	return (1);
}
