#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

typedef struct dequeNode
{
    Node *head;
    Node *tail;
} DequeNode;

typedef DequeNode *DequeNodePtr;
typedef Node *NodePtr;

int empty(DequeNodePtr deq)
{
    return (deq == NULL);
}

int size(DequeNodePtr deq)
{
    if (empty(deq))
        return 0;
    else
    {
        int cnt = 1;
        while (deq->head != NULL)
        {
            deq->head = deq->head->next;
            cnt++;
        }
        return cnt;
    }
}

void pushFront(DequeNodePtr *deq, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->prev = NULL;

        if (empty(*deq) == 1)
        {
            (*deq) -> tail = newNode;
            newNode->next = NULL;
        }
        else
            newNode->next = (*deq)->head;

        (*deq)->head = newNode;
    }
}

void pushBack(DequeNodePtr *deq, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
        if (empty(*deq) == 1)
        {
            (*deq)->head = newNode;
            newNode->prev = NULL;
        }
        else
            newNode->prev = (*deq)->tail;

        (*deq)->tail = newNode;
    }
}

int popFront(DequeNodePtr *deq)
{
    int value;
    if (empty(*deq))
        value = -1;
    else
    {
        NodePtr tmp = (*deq)->head;
        value = tmp->data;
        if(tmp->next != NULL)
            (*deq)->head = tmp->next;
        free(tmp);
    }
    return value;
}

int popBack(DequeNodePtr *deq)
{
    return 0;
}
int front(DequeNodePtr deq)
{
    return 0;
}
int back(DequeNodePtr deq)
{
    return 0;
}


int main(void)
{
    DequeNodePtr deq = NULL;
    deq->head = NULL;
    deq->tail = NULL;

    int n, i;
    int x;
    scanf("%d", &n);
    char menu[10];

    for (i = 0; i < n; i++)
    {
        scanf("%s", menu);
        if (strcmp(menu, "push_front") == 0)
        {
            scanf("%d", &x);
            pushFront(&deq, x);
        }
        else if (strcmp(menu, "push_back") == 0)
        {
            scanf("%d", &x);
            pushBack(&deq, x);
        }
        else if (strcmp(menu, "pop_front") == 0)
        {
            printf("%d\n", popFront(&deq));
        }
        else if (strcmp(menu, "pop_back") == 0)
        {
            printf("%d\n", popBack(&deq));
        }
        else if (strcmp(menu, "size") == 0)
        {
            printf("%d\n", size(deq));
        }
        else if (strcmp(menu, "empty") == 0)
        {
            printf("%d\n", empty(deq));
        }
        else if (strcmp(menu, "front") == 0)
        {
            printf("%d\n", front(deq));
        }
        else if (strcmp(menu, "back") == 0)
        {
            printf("%d\n", back(deq));
        }
    }

    return 0;
}
