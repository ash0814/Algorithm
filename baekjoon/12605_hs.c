#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split(char *c)
{
	char *temp = strtok(c, " ");
	int i = 0;
	int j;
	char **nc;

	nc = (char **)malloc(sizeof(char *) * 50);
	for (int i = 0; i < 50; i++)
		nc[i] = (char *)malloc(sizeof(char) * 50);
	nc[0] = temp;
	while (temp != NULL)
	{
		nc[i] = temp;
		temp = strtok(NULL, " ");
		i++;
	}
	j = i-1;
	while (j > 0)
	{
		printf("%s ", nc[j]);
		j--;
	}
	printf("%s", nc[0]);
	free(nc);
}

int main(void)
{
	int i;
	int n = 0;
	scanf("%d", &n);
	fflush(stdin);
	char str[5][81];
	int k = 0;

	for (i = 0; i < 5; i++)
	{
		gets(str[i]);
	}

	for (i = 0; i < 5; i++)
	{
		printf("Case #%d: ", i + 1);
		split(str[i]);
		printf("\n");
	}
	return 0;
}