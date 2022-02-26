#ifndef Q_H
# define Q_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int max;
	int num;
	int front;
	int rear;
	int *que;
} intque;

int init(intque *q, int max);
int enque(intque *q, int x);
int deque(intque *q, int *x);
int peek(intque *q, int *x);
void clear(intque *q);
int capacity(intque *q);
int size(intque *q);
int isempty(intque *q);
int isfull(intque *q);
int search(intque *q, int x);
int search2(intque *q, int x);
void printq(intque *q);
void terminate(intque *q);

#endif