#ifndef LIST_H
# define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_node {
	struct	s_node *next;
	int value;
}				t_node;

typedef struct s_list {
	t_node *head;
}				t_list;

void add_list(t_list **list, int x);
void del_list(t_list **list, int x);
void find_list(t_list *list, int x);
void print_list(t_list *list);

#endif
