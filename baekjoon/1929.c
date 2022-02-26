#include <stdio.h>

int list[1000000] = {0, };
int j = 0;

int foo(int m, int n)
{
	if (m == 1)
		return (0);
	
	return (1);
}

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		list[i] = i;
	}
	foo(m, n);
	return (0);
}
