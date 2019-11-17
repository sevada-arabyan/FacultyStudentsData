#include"SortingAlgorithms.h"
#include<iostream>
void swap(int*x, int*y)
{
	int tmp{ *x };
	*x = *y;
	*y = tmp;
}

void selectionSort(int *x, const int& sz)
{
	int min_i;
	for (int i{ 0 }; i < sz-1; i++)
	{
		min_i = i;
		for (int j{ i + 1 }; j < sz;j++)
		if (x[j] < x[min_i])
			min_i = j;
		swap(&x[i], &x[min_i]);
	}

}

void insertionSort(int *x, const int& sz)
{
	int key, j;
	for (int i{ 1 }; i < sz; i++)
	{
		key = x[i];
		j = i - 1;
		while (j >= 0 && x[j]>key)
		{
			x[j + 1] = x[j];
			j--;
		}
		x[j + 1] = key;
	}
}
void bubbleSort(int *x, const int& sz)
{
	for (int i{ 0 }; i < sz-1; i++)
	{
		bool swaps{ false };
		for (int j{ 0 }; j < sz - i - 1; j++)
		{
			if (x[j]>x[j + 1])
			{
				swap(&x[j], &x[j + 1]);
				swaps = true;
			}
		}
		if (!swaps)
			break;
	}
}
void merge(int* x, const int& lindex, const int& mindex, const int& rindex);
void mergeSort(int* x, const int& lindex, const int& rindex)
{
	if (lindex < rindex)
	{
		int mindex{ (rindex + lindex) / 2 };
		mergeSort(x, lindex, mindex);
		mergeSort(x, mindex + 1, rindex);
		merge(x, lindex, mindex, rindex);
	}
}

void merge(int* x, const int& lindex, const int& mindex, const int& rindex)
{
	int li{ lindex }, ri{ mindex + 1 }, i{ 0 };
	const int sz{ rindex - lindex + 1 };
	int* arr = new int[sz];
	while (li <= mindex && ri <= rindex)
	{
		arr[i++] = (x[li] < x[ri]) ? x[li++] : x[ri++];
	}

	while (li <= mindex)
	{
		arr[i++] = x[li++];
	}
	while (ri <= rindex)
	{
		arr[i++] = x[ri++];
	}
	for (int i{ 0 }; i < sz; i++)
	{
		x[lindex + i] = arr[i];
	}
}