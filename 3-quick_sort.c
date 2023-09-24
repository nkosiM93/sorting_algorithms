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
 * @end: where to end
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void qsorter(int start, int end, int *array, size_t size)
{
	int pv, e, s, d;

	pv = start;
	s = start;
	e = end;
	d = 0;

	if (start == end)
		return;
	while (s != e)
	{
		if (array[s] > array[e])
		{
			swapper(e, s, array);
			print_array(array, size);
			if (d == 0)
			{
				pv = e;
				d = 1;
				s++;
			}
			else
			{
				pv = s;
				d = 0;
				e--;
			}
		}
		else
		{
			if (d == 1)
				s++;
			else
				e--;
		}
	}
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
