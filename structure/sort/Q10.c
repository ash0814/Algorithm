#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binsearch(int data[], int n, int key)
{
	int low, high;
	int mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		printf("{low = %d high = %d mid = %d}\n", low, high, mid);
		if (low == high)
		{
			if (key > data[low])
				return -1;
			else 
				return 0;
		}
		else if (key < data[mid]){
			high = mid - 1;
			if (low <= high && data[high] < key)
				return high + 1;
		}
		else if (key > data[mid]){
			low = mid + 1;
			if (low <= high && data[low] > key){
				return low;
			}
		}
	}
	return -1;
}

void insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++)
	{
		int tmp = a[i];
		int bin = binsearch(a, i, tmp);
		printf("bin = %d\ntmp = %d\n\n", binsearch(a, i, tmp), tmp);
		if (bin != -1)
		{
			int k = 0;
			while (k < bin)
				k++;
			for (j = i; j > bin; j--)
				a[j] = a[j-1];
			a[bin] = tmp;
		}
	}
}

int main(void)
{
	int i, nx;
	int *x;
	puts("Insertion sort");

	printf("A number of element: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);
	puts("sorted in ascending order now");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}
