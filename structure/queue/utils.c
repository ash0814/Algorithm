#include "q.h"

int init(intque *q, int max)
{
	q->num = 0;
	q->front = 0;
	q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL)
	{
		q->max = 0;
		return (1);
	}
	q->max = max;
	return (0);
}

int enque(intque *q, int x)
{
	if (q->num >= q->max)
		return 1;
	else {
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max)
			q->rear = 0;
		return (0);
	}
}

int deque(intque *q, int *x)
{
	if (q->num <= 0)
		return (1);
	else {
		q->num--;
		*x = q->que[q->front++]; //++q->front
		if (q->front == q->max)
			q->front = 0;
		return 0;
	}
}

int peek(intque *q, int *x)
{
	if (q->num <= 0)
		return 1;
	*x = q->que[q->front];
	return (0);
}

void clear(intque *q)
{
	q->num = 0;
	q->front = 0;
	q->rear = 0;
}

int capacity(intque *q)
{
	return (q->max);
}

int size(intque *q)
{
	return (q->num);
}

int isempty(intque *q)
{
	return (q->num <= 0);
}

int isfull(intque *q)
{
	return (q->num >= q->max);
}

int search(intque *q, int x)
{
	int i, idx;
	for (i = 0; i < q->num; i++)
	{
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;
	}
	return -1;
}

int search2(intque *q, int x)
{
	int i, idx;
	for (i = 0; i < q->num; i++)
	{
		if (q->que[idx = (i + q->front) % q->max] == x)
		{
			if (idx - q->front >= 0)
				return idx - q->front;
			else
				return q->max + (idx - q->front);
		}
	}
	return -1;
}

void printq(intque *q)
{
	int i;
	
	for (i = 0; i < q->num; i++)
		printf("%d ", q->que[(i + q->front) % q->max]); // front 가 0이 아닐 수 있기 때문에, i + front 를 큐의 max값으로 나눈 나머지 = idx
	printf("\n");
}

void terminate(intque *q)
{
	if (q->que != NULL)
		free(q->que);
	q->max = 0;
	q->rear = 0;
	q->front = 0;
	q->num = 0;
}