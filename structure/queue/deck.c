#include <stdio.h>
#include <stdlib.h>

typedef struct	s_deck
{
	int *deck;
	int front;
	int rear;
	int num;
	int max;
}				t_deck;

int		init_deck(t_deck *d, int max)
{
	if (!(d->deck = calloc(sizeof(int), max)))
		return 1;
	d->max = max;
	d->front = 0;
	d->num = 0;
	d->rear = 0;
	return (0);
}

int	push_front(t_deck *d, int x)
{
	if (d->num >= d->max)
		return 1;
	if (d->front <= 0)
	{
		d->front = d->max - 1;
		d->deck[d->front] = x;
		d->num++;
		return 0;
	}
	else
	{
		d->deck[d->front - 1] = x;
		d->front--;
		d->num++;
		return (0);
	}
	return 1;
}

int push_end(t_deck *d, int x)
{
	if (d->num >= d->max)
		return 1;
	if (d->rear < d->max){
		d->deck[d->rear] = x;
		d->rear++;
		d->num++;
		return 0;
	}
	else
	{
		d->rear = 0;
		d->deck[d->rear] = x;
		d->rear++;
		d->num++;
		return (0);
	}
	return 1;
}

int pop_front(t_deck *d, int *x)
{
	if (d->num <= 0)
		return 1;
	if (d->front < d->max){
		*x = d->deck[d->front];
		d->front++;
		d->num--;
		return 0;
	}
	else
	{
		d->front = 0;
		*x = d->deck[d->front];
		d->num--;
		return 0;
	}
	return 1;
}

int pop_end(t_deck *d, int *x)
{
	if (d->num <= 0)
		return 1;
	if (d->rear > 0){
		*x = d->deck[d->rear - 1];
		d->rear--;
		d->num--;
		return 0;
	}
	else
	{
		d->rear = d->max - 1;
		*x = d->deck[d->rear];
		d->num--;
		return 0;
	}
	return 1;
}

void Print(t_deck *d)
{
	for (int i = 0; i < d->num; i++)
		printf("%d ", d->deck[(d->front + i) % d->max]);
	printf("\n");
}

int main()
{
	t_deck *d;

	if (!(d = (t_deck *)malloc(sizeof(t_deck))))
		return 1;
	if (init_deck(d, 5))
		return 1;
	while (1)
	{
		int m, x;
		printf("Data : %d / %d\n", d->num, d->max);
		printf("(1) push_front (2) push_end (3) pop_front (4) pop_end (5) Print (0) Exit : ");
		scanf("%d", &m);
		if (m == 1)
		{
			printf("Push Data : ");
			scanf("%d", &x);
			if (push_front(d, x))
				printf("Push_error\n");
			continue;
		}
		else if (m == 2)
		{
			printf("Push Data : ");
			scanf("%d", &x);
			if (push_end(d, x))
				printf("Push_error\n");
			continue;
		}
		else if (m == 3)
		{
			if (pop_front(d, &x))
				printf("pop_error\n");
			printf("Pop Data : %d\n", x);
			continue;
		}
		else if (m == 4)
		{
			if (pop_end(d, &x))
				printf("pop_error\n");
			printf("Pop Data : %d\n", x);
			continue;
		}
		else if (m == 5)
		{
			Print(d);
			continue;
		}
		else
			break;
	}
	free(d->deck);
	free(d);
	return 0;
}
