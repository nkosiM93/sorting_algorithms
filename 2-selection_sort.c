#include "sort.h"

/**
 * selection_sort - Impliments the selection sort algorithm
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i + 1] < array[i])
		{
			swap(array, i, i + 1);
			print_array(array, size);
			if (sortCheck_seleck(array, size))
				break;
		}
		for (j = (i + 2); j < size; j++)
		{
			if (array[i] > array[j])
			{
				swap(array, i, j);
				/*					print_array(array, size);*/
				if (sortCheck_seleck(array, size))
					break;
			}
		}
	}
}

/**
 * sortCheck_seleck - checks if array is sorted already
 * @array: the ....
 * @size: ..
 * Return: ...
 */

int sortCheck_seleck(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{ /*Check if array is already sorted*/
		if (array[i] > array[i + 1])
			return (0);
	}
	return (1);
}

/**
 * swap - swaps two elements
 * @i: the one element to be swapped
 * @j: The other element to be swapped
 * @array: The array with the elements
 */

void swap(int *array, size_t i, size_t j)
{
	int temp;

	temp = array[j];
	array[j] = array[i];
	array[i] = temp;
}
