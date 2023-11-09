#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* 절단기의 최대 높이 */

long long M, max = 0, N;

int compare(const void *a, const void *b)
{
    long long A = *(long long *)a;
    long long B = *(long long *)b;

    if (A > B)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void BinarySearchTree(long long Tree[], long long left, long long right)
{
    if (left > right)
    {
        return;
    }
    /* 절단기의 높이 */
    long long mid = (left + right) / 2, total = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        if (Tree[i] <= mid)
        {
            break;
        }
        else
        {
            total += Tree[i] - mid;
            //printf("Tree[i]: %lld, mid: %lld\n", Tree[i], mid);
        }
    }

    if (total == M)
    {
        max = mid;
        return;
    }
    /* 절단기의 높이를 낮춰야함 */
    else if (total < M)
    {
        BinarySearchTree(Tree, left, mid - 1);
    }
    else
    {
        max = mid;
        // printf("max: %lld, right: %lld\n", max, right);
        BinarySearchTree(Tree, mid + 1, right);
    }
}

int main()
{
    long long i, *Tree;

    scanf("%lld %lld", &N, &M);

    Tree = (long long *)malloc(N * sizeof(long long));

    for (i = 0; i < N; i++)
    {
        scanf("%lld", &Tree[i]);
    }

    qsort(Tree, N, sizeof(long long), compare);

    // for(int j = 0; j < N; j++)
    // {
    //     printf("%lld ", Tree[j]);
    // }

    int left = 0, right = Tree[N - 1];

    BinarySearchTree(Tree, left, right);

    printf("%lld\n", max);

    free(Tree);

    return 0;
}