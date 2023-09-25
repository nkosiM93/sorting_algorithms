#include "sort.h"

/**
 * shell_sort - Impliments the shell sort algorithm
 * @size: The number of elements in the array
 * @array: the array to be sorted
 */

void shell_sort(int *array, size_t size)
{
	size_t inter;
	size_t c, i;

	inter = 1;

	if (!array || size == 0)
		return;

	if (allSame(array, size) == 1 || sorted(array, size) == 1)
		return;

	while (inter < size)
		inter *= 3 + 1;
	inter = (inter - 1) / 3;

	while (inter >= 1)
	{
		for (c = 0; c < inter; c++)
			for (i = c; i < (size - inter); i += inter)
			{
				insertionSort(array, (int)inter, (int)i);
			}
		print_array(array, size);
		inter = (inter - 1) / 3;
	}
}

/**
 * insertionSort - Impliments the insertion sort algorithm
 * @array: The array to be sorted
 * @inter: the interval
 * @i: the current index on the array
 */
void insertionSort(int *array, int inter, int i)
{
	int g;

	if (array[i] > array[i + inter])
	{
		swapShell(i, i + inter, array);
		if (i - inter >= 0)
		{
			g = i;
			while (g - inter >= 0)
			{
				if (array[g] < array[g - inter])
				{
					swapShell(g, g - inter, array);
					g = g - inter;
				}
				else
					break;
			}
		}
	}
}

/**
 * swapShell - sawapping function for the Shell sort algo
 * @i: the one element
 * @j: the other element
 * @array: the array where swapping is perfomed
 */
void swapShell(size_t i, size_t j, int *array)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * allSame - checks if an array has only one value
 * @array: The array
 * @size: The number of elements in the array
 * Return: 1 if true and 0 if not
 */

int allSame(int *array, size_t size)
{
	size--;
	while (size > 0)
	{
		if (array[size] != array[size - 1])
			return (0);
		size--;
	}
	return (1);
}

/**
 * sorted - checks if array is already sorted in ascending order
 * @array: The array
 * @size: Number of elements in the array
 * Return: 1 if true and 0 if not
 */
int sorted(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{ /*Check if array is already sorted*/
		if (array[i] > array[i + 1])
			return (0);
	}
	return (1);
}
