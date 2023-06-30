#include <stdio.h>
#include <stdlib.h>

struct student
{
    int weight;
    int height;
    int rank;
};

int main()
{
    struct student *STUDENT, *p;
    int N;
    scanf("%d", &N);

    STUDENT = (struct student *)malloc(sizeof(struct student) * N);

    for (p = STUDENT; p < STUDENT + N; p++)
    {
        scanf("%d %d", &p->weight, &p->height);
        p->rank = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (p = STUDENT; p < STUDENT + N; p++)
        {
            if (STUDENT[i].height < p->height && STUDENT[i].weight < p->weight)
            {
                STUDENT[i].rank++;
            }
        }
    }

    for (p = STUDENT; p < STUDENT + N; p++)
    {
        printf("%d ", p->rank);
    }

    free(STUDENT);

    return 0;
}