#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge Sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size - 1);
	free(temp);
}

/**
 * merge_sort_recursive - sorts an array of integers in ascending order
 * using the Merge Sort algorithm
 * @array: array to sort
 * @temp: temporary array
 * @low: low index
 * @high: high index
 *
 * Return: void
 */
void merge_sort_recursive(int *array, int *temp, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort_recursive(array, temp, low, mid);
		merge_sort_recursive(array, temp, mid + 1, high);
		merge(array, temp, low, mid, high);
	}
}

/**
 * merge - merges two subarrays
 * @array: array to sort
 * @temp: temporary array
 * @low: low index
 * @mid: middle index
 * @high: high index
 *
 * Return: void
 */
void merge(int *array, int *temp, int low, int mid, int high)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, mid - low + 1);
	printf("[right]: ");
	print_array(array + mid + 1, high - mid);

	for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}
	while (i <= mid)
	{
		temp[k] = array[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		temp[k] = array[j];
		j++;
		k++;
	}
	for (i = low; i <= high; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(temp + low, high - low + 1);
}
