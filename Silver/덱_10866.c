#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEDUE_SIZE 10000;

typedef struct DEQUE
{
    int data;
    struct DEQUE *next;
    struct DEQUE *prev;
}DEQUE;

int s = 0;

void push_front(DEQUE *Q, int X);
void push_back(DEQUE *Q, int X);
void pop_front(DEQUE *Q);
void pop_back(DEQUE *Q);
void size(DEQUE *Q);
void empty(DEQUE *Q);
void front(DEQUE *Q);
void back(DEQUE *Q);
void getNode(DEQUE**p);

int main()
{
    int N;

    scanf("%d", &N);
    char order[20];

    DEQUE *Q = NULL;

    getNode(&Q);
    
    for (int i = 0; i < N; i++)
    {
        scanf("%s", order);

        if (strcmp(order, "push_front") == 0)
        {
            int X;
            scanf("%d", &X);
            push_front(Q, X);
            
        }
        else if (strcmp(order, "push_back") == 0)
        {
            int X;
            scanf("%d", &X);
            push_back(Q, X);
            
        }
        else if (strcmp(order, "pop_front") == 0)
        {
            pop_front(Q);
        }
        else if (strcmp(order, "pop_back") == 0)
        {
            pop_back(Q);
        }
        else if (strcmp(order, "size") == 0)
        {
            size(Q);
        }
        else if (strcmp(order, "empty") == 0)
        {
            empty(Q);
        }
        else if (strcmp(order, "front") == 0)
        {
            front(Q);
        }
        else if (strcmp(order, "back") == 0)
        {
            back(Q);
        }
    }

    return 0;
}

void getNode(DEQUE**p)
{  
    (*p) = (DEQUE*)malloc(sizeof(DEQUE));
    (*p)->next = NULL;
    (*p)->prev = NULL;
}

/* front가 뒤이다. */
void push_front(DEQUE *Q, int X)
{
    DEQUE *p = NULL;

    /* p라는 새로운 노드를 만들어서 데이터를 거기에 넣는다. */
    getNode(&p);
    s++;
    p->data = X;

    DEQUE *q = Q;
    /* q는 비어있는 노드까지 이동하기 위한 장치 */
    while (q->next != NULL)
    {
        q = q->next;
    }

    /* 각각의 노드를 연결시켜준다. */
    q->next = p;
    p->prev = q;
}
void push_back(DEQUE *Q, int X)
{
    DEQUE *p = NULL;

    /* p라는 새로운 노드를 만들어서 데이터를 거기에 넣는다. */
    getNode(&p);
    s++;
    p->data = X;

    /* Q의 첫번째 공간은 항상 비어있으므로 */
    p->next = Q->next;
    p->prev = Q;

    if (Q->next != NULL)
    {
        Q->next->prev = p;
    }
    Q->next = p;

}
void pop_front(DEQUE *Q)
{
    if(Q->next == NULL){
        printf("-1\n");
        return;
    }

    /* p는 삭제할 데이터의 위치 */
    DEQUE*p = Q;
    s--;

    while(p->next != NULL)
    {
        p = p->next;
    }
    int tmp = p->data;

    p = p->prev;

    /* 해제 해주고 NULL포인터를 할당 해줘야 빈 것이 된다. */
    free(p->next);
    p->next = NULL;

    printf("%d\n", tmp);
}
void pop_back(DEQUE *Q)
{
    if(Q->next == NULL)
    {
        printf("-1\n");
        return;
    }

    /* p는 삭제할 데이터의 위치 */
    DEQUE *p = Q->next;
    s--;
    int tmp = p->data;

    Q->next = p->next;
    
    if(p->next != NULL)
    {
        p->next->prev = Q;
    }
    free(p);

    printf("%d\n", tmp);
}

void size(DEQUE *Q)
{
    printf("%d\n", s);
}
void empty(DEQUE *Q)
{
    if(s == 0)
    {
        printf("1\n");
    }
    else{
        printf("0\n");
    }
}
void front(DEQUE *Q)
{
    if(s == 0)
    {
        printf("-1\n");
    }

    else
    {
        DEQUE *p = Q;
        while(p->next != NULL)
        {
            p = p->next;
        }
        printf("%d\n", p->data); 
    }
}

void back(DEQUE *Q)
{
    if(s == 0)
    {
        printf("-1\n");
    }

    else
    {
        int tmp = Q->next->data;
        printf("%d\n", tmp);
    }
}