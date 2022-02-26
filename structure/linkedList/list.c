#include "list.h"

int main()
{
	t_list *list;
	int menu = 1;
	int x;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return 1;
	list->head = NULL;
	while (menu != 0)
	{
		printf("(1)ADD (2)DEL (3)FIND (4)PRINT (0)EXIT : ");
		scanf("%d", &menu);
		if (menu == 0)
			break;
		else if (menu == 1)
		{
			printf("Add Data : ");
			scanf("%d", &x);
			add_list(&list, x);
		}
		else if (menu == 2)
		{
			printf("Delete Data : ");
			scanf("%d", &x);
			del_list(&list, x);
		}
		else if (menu == 3)
		{
			printf("Find Data : ");
			scanf("%d", &x);
			find_list(list, x);
		}
		else if (menu == 4)
		{
			print_list(list);
		}
		else
			break;
	}
	free(list);
	return (0);
}