#include "sort.h"

/**
 * selection_sort - Impliments the selection sort algorithm
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (!array || size == 0)
		return;

	if (sortCheck_seleck(array, size))
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap(array, i, min);
			print_array(array, size);
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
