#include "sort.h"

/**
 * quick_sort - Impliments the quicksort algorithm
 * @array: The array to be sorted
 * @size: he number of elements in the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	qsorter(0, size - 1, array, size);
}

/**
 * qsorter - Impliments the quicksort algorithm
 * @start: Wwhere to start from
 * @pv: The Pivot
 * @array: The array to be sorted
 * @size: Number of array memebers
 */
void qsorter(int start, int pv, int *array, size_t size)
{
	int s, i, end, sorted;

	s = start;
	i = start - 1;
	sorted = 1;

	if (start >= pv)
		return;
	for (; s <= pv; s++)
	{
		if (array[s] <= array[pv])
		{
			i++; /* So that we r able to check equality b4 call */
			if (i != s)
			{
				swapper(i, s, array);
				print_array(array, size);
				sorted = 1;
			}
			else
			{
				if (array[s] > array[s + 1])
					sorted = 0;
			}
		}
	}
	if (pv == i && sorted == 1)
		return;
	end = pv;
	pv = i;
	if (!(pv - 1 <= start))
		qsorter(start, pv - 1, array, size);
	if (!(pv + 1 >= end))
		qsorter(pv + 1, end, array, size);
}

/**
 * swapper - performs a swapping operation
 * @array: ...
 * @e: one of the elements to be swapped
 * @s: the other element to be swapped
 */

void swapper(int e, int s, int *array)
{
	int temp;

	temp = array[e];
	array[e] = array[s];
	array[s] = temp;
}
