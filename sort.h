#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void exchange(listint_t **temp);
void subSorter(listint_t *temp2, listint_t *list);
void swap(int *array, size_t i, size_t j);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
int sort_check(int *array, size_t size);
void bubble_sort(int *array, size_t size);
int sortCheck_seleck(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swapper(int e, int s, int *array);
void qsorter(int start, int end, int *array, size_t size);
void swapShell(size_t i, size_t j, int *array);
void shell_sort(int *array, size_t size);
void insertionSort(int *array, int inter, int i);
int sorted(int *array, size_t size);
int allSame(int *array, size_t size);

#endif
