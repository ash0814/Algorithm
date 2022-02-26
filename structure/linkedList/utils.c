#include "list.h"

void add_list(t_list **list, int x)
{
	t_node *new;
	t_node *tmp;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		exit(1);
	new->value = x;
	new->next = NULL;

	tmp = (*list)->head;
	if (tmp == NULL){
		(*list)->head = new;
	}
	else {
		while (tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void del_list(t_list **list, int x)
{
	t_node *tmp;

	tmp = (*list)->head;
	
}

void find_list(t_list *list, int x)
{
	t_node *tmp;
	int i;

	tmp = list->head;
	i = 1;
	while (tmp != NULL)
	{
		if (tmp->value == x)
		{
			printf("%d is at node %d.\n", x, i);
			return ;
		}
		tmp = tmp->next;
		i++;
	}
	printf("%d is not in list\n", x);
}

void print_list(t_list *list)
{
	t_node *tmp;

	tmp = list->head;
	while (tmp != NULL)
	{
		printf("> %d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}