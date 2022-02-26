#include "list.h"

void add_node(t_list *list, int val)
{
	t_node *new;
	t_node *tmp;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return ;
	new->value = val;
	new->next = NULL;

	tmp = list->head;
	if (tmp == NULL){
		list->head = new;
	} else {
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void delete(t_list *list, int x)
{
	t_node *tmp;
	t_node *n;

	tmp = list->head;
	if (tmp->value == x)
	{
		list->head = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp != NULL)
	{
		n = tmp->next;
		if (n->value == x)
		{
			tmp->next = n->next;
			free(tmp);
			return ;
		}
		tmp = tmp->next;
	}
}

void print_list(t_list *list)
{
	t_node *tmp;

	tmp = list->head;
	while (tmp != NULL){
		printf("%d > ", tmp->value);
		tmp = tmp->next;
	}
}

void	free_node(t_node **node)
{
	t_node **now;
	t_node *tmp;

	now = node;
	while (*now)
	{
		tmp = *now;
		*now = (*now)->next;
		free(tmp);
		tmp = 0;
	}
}

int main()
{
	t_list	*list;
	t_node	*tmp;
	int		num;
	int		sum = 0;;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return 1;
	list->head = NULL;
	printf("노드의 개수 : ");
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int x;
		printf("노드 #%d 데이터 :", i + 1);
		scanf("%d", &x);
		add_node(list, x);
	}
	print_list(list);

	int x;

	printf("\ndelete value : ");
	scanf("%d", &x);
	delete(list, x);

	tmp = list->head;
	while (tmp != NULL){
		printf(">> %d\n", tmp->value);
		tmp = tmp->next;
	}
	free_node(&list->head);
	free(list);
	list = 0;
	while (1);
	return 0;
}


