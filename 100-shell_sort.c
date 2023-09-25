#include "sort.h"

/**
 * shell_sort - Impliments the shell sort algorithm
 * @size: The number of elements in the array
 * @array: the array to be sorted
 */

void shell_sort(int *array, size_t size)
{
	size_t inter;
	int c, i;

	inter = 1;
	while (inter < size)
		inter *= 3 + 1;
	inter = (inter - 1)/3;

	for (c = 0; c < inter; c++)
		for (i = c; i < (s - inter); i += inter)
		{
			if (array[i] > array[i + inter])
			{
				swapShell(array[i], array[i + inter], array);
				if (i - inter >= 0)
				{
					g = i - inter;
					while (g - inter >= 0)
					{
						if (array[g] < array[g - inter])
						{
							swapShell();
							g = g - inter;
						}
						else
							break;
					}
				}
			}
		}
}
