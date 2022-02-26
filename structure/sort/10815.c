#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	q_sort(int left, int right, int *list)
{
	int p;
	int j;
	int i;

	p = left;
	i = left + 1;
	j = right;
	if (left < right)
	{
		while (i <= j)
		{
			while (i <= right && list[i] <= list[p])
				i++;
			while (j > left && list[j] >= list[p])
				j--;
			if (i > j)
				swap(&list[j], &list[p]);
			else
				swap(&list[i], &list[j]);
		}
		q_sort(left, j - 1, list);
		q_sort(j + 1, right, list);
	}
}

int binsearch(int data[], int n, int key) {
    int low, high;
    int mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == data[mid]) {
            return 1;
        }
        else if (key < data[mid]) {
            high = mid - 1;
        }
        else if (key > data[mid]) {
            low = mid + 1;
        }
    }
    return 0;
}


int main()
{
	int n, m;
	scanf("%d", &n);
	int list[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &list[i]);
	q_sort(0, n-1, list);
	
	scanf("%d", &m);
	int list2[m];
	int res[m];
	for (int i = 0; i < m; i++)
		scanf("%d", &list2[i]);
	for (int i = 0; i < m; i++) {
		res[i] = binsearch(list, n, list2[i]);
	}
	for (int i = 0; i < m; i++)
		printf("%d ", res[i]);
	return 0;
}
