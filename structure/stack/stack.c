#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *stack;
	int a = 0;
	int b = 63;
	int aorb;
	int menu, x;

	if (!(stack = (int *)calloc(sizeof(int), 64)))
		return 1;
	while (1){
		printf("(1) A (2) B (0) Exit: ");
		scanf("%d", &aorb);
		if (aorb == 1)
		{
			printf("now data : %d / %d\n", a, 32);
			printf("(1) PUSH (2) POP (3) Peek (4) Print (0) EXIT : ");
			scanf("%d", &menu);
			if (menu == 0)
				break;
			else if (menu == 1)
			{
				if (a > 32)
				{
					printf("A stack is full\n");
					continue ;
				}
				printf("push_data : ");
				scanf("%d", &x);
				stack[a] = x;
				a++;
			}
			else if (menu == 2)
			{
				if (a <= 0)
				{
					printf("A stack is empty\n");
					continue;
				}
				x = stack[--a];
				stack[a] = NULL;
				printf("pop data : %d\n", x);
			}
			else if (menu == 3)
			{
				if (a > 0)
					printf ("peek data : %d\n", stack[a - 1]);
				else
					printf("No peek data\n");
			}
			else if (menu == 4)
			{
				for (int i = 0; stack[i] != 0; i++)
					printf("%d ", stack[i]);
				printf("\n");
			}
			else
				printf("error\n");
		}
		else if (aorb == 2)
		{
			printf("now data : %d/%d\n", 63 - b, 32);
			printf("(1) PUSH (2) POP (3) Peek (4) Print (0) EXIT : ");
			scanf("%d", &menu);
			if (menu == 0)
				break;
			else if (menu == 1)
			{
				if (b <= 32)
				{
					printf("B stack is full\n");
					continue ;
				}
				printf("push_data : ");
				scanf("%d", &x);
				stack[b] = x;
				b--;
			}
			else if (menu == 2)
			{
				if (b >= 63)
				{
					printf("B stack is empty\n");
					continue;
				}
				x= stack[++b];
				stack[b] = 0;
				printf("pop data : %d\n", x);
			}
			else if (menu == 3)
			{
				if (b < 63)
					printf ("peek data : %d\n", stack[b + 1]);
				else
					printf("No peek data\n");
			}
			else if (menu == 4)
			{
				for (int i = 63; stack[i] != 0; i--)
					printf("%d ", stack[i]);
				printf("\n");
			}
			else
				printf("error\n");
		}
		else if (aorb == 0)
			break;
		else
			printf("error\n");
	}
	free (stack);
	return 0;
}