#include <stdio.h>
#define SIZE 500001

typedef struct 
{
    int QQQ[SIZE];
    int front;
    int rear;
}QueueType;

void initQueue(QueueType *Q)
{
    Q->front = Q->rear = 0;
}

int isFull(QueueType *Q);
void enqueue(QueueType *Q, int n);
int isEmpty(QueueType *Q);
int dequeue(QueueType *Q);

int main()
{
    int N;
    scanf("%d", &N);
    QueueType Queue;

    initQueue(&Queue);

    for(int i = 0; i < N; i++)
    {
        enqueue(&Queue, i+1);
    }

    int g = 0;

    while(!isEmpty(&Queue))
    {
        g = dequeue(&Queue);
        if(isEmpty(&Queue))
        {
            break;
        }
        g = dequeue(&Queue);
        enqueue(&Queue, g);
    }
    printf("%d", g);

    return 0;
}

int isFull(QueueType *Q)
{
    if(Q->front == (Q->rear+1) % SIZE)
    {
        return 1;
    }
    else return 0;
}
void enqueue(QueueType *Q, int n)
{
    if(isFull(Q) == 1)
    {
        return;
    }
    /* 다음칸으로 이동해서 추가한다고 생각하자 */
    Q->rear = (Q->rear + 1) % SIZE;
    Q->QQQ[Q->rear] = n;

}
int isEmpty(QueueType *Q)
{
    if(Q->front == Q->rear)
    {
        return 1;
    }
    else return 0;
}
int dequeue(QueueType *Q)
{
    if(isEmpty(Q) == 1)
    {
        return -1;
    }
    /* 다음칸으로 옮겨서 지운다고 생각하자 */
    Q->front = (Q->front+1) % SIZE;

    return Q->QQQ[Q->front];

}
