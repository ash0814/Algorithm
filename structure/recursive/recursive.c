#include <stdio.h>
#include <stdlib.h>

void recur3(int n)
{
	if (n > 0)
	{
		recur3(n-1);
		recur3(n-2);
		printf("%d ", n);
	}
}

void my_recur3(int n)
{
}

int main(int argc, char **argv)
{
	(void) argc;

	printf("origin\n===\n");
	recur3(atoi(argv[1]));
	printf("\n===\n");
	printf("mine\n===\n");
	my_recur3(atoi(argv[1]));
	printf("\n");
	// fac(atoi(argv[1]));
	return 0;
}
