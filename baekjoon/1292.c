#include <stdio.h>

int main(void)
{
	int a, b, tmp;
	int list[1000];
	int count = 0;
	int res = 0;
	int i = 0;

	scanf("%d%d", &a, &b);
	// if (a > b)
	// {
	// 	tmp = a;
	// 	a = b;
	// 	b = tmp;
	// }
	while (i < 1000){
		count++;
		for (int j = 0; j < count && i < 1000; j++){
			list[i] = count;
			i++;
		}
	}
	while (a - 1 < b)
	{
		res += list[a - 1];
		a++;
	}
	printf("%d\n", res);
	return (0);
}
