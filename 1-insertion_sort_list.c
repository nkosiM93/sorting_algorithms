#include "sort.h"

/**
 * insertion_sort_list - Function implements the insertion sort algorithm
 * @list: Head of the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp2;
	int exch;

	temp = *list;

	if (!temp->next)
		return;
	while (temp)
	{
		exch = 0;
		if (temp->next)
			if (temp->next->n < temp->n)
			{
				exchange(&temp);
				while ((*list)->prev)
					(*list) = (*list)->prev;
				print_list(*list);
				exch = 1;

				temp2 = temp->prev;
				subSorter(temp2, *list);
			}
		if (exch == 0)
			temp = temp->next;
	}
	while ((*list)->prev)
		(*list) = (*list)->prev;
}

/**
 * subSorter - Sorts the left side after an excahange
 * @temp2: the point from where to sort
 * @list: ...
 */
void subSorter(listint_t *temp2, listint_t *list)
{
	while (temp2->prev)
	{
		if (temp2->n < temp2->prev->n)
		{
			exchange(&(temp2->prev));
			while (list->prev)
				list = list->prev;
			print_list(list);
		}
		else
			break;
	}
}

/**
 * exchange - performs the exchange of two nodes
 * @temp: address of the node on the list
 */
void exchange(listint_t **temp)
{
	listint_t *t, *t2, *tempHolder;

	tempHolder = *temp;
	t = (*temp)->next;
	t2 = (*temp)->next->next;
	if ((*temp)->prev)
		tempHolder->prev->next = tempHolder->next;
	tempHolder->next->prev = tempHolder->prev;
	if (tempHolder->next->next)
		tempHolder->next->next->prev = tempHolder;
	tempHolder->next->next = tempHolder;
	tempHolder->next = t2;
	tempHolder->prev = t;

}
