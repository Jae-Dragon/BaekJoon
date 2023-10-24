#include <stdio.h>
#include <stdlib.h>

int arr[9] = {0,};
int print_arr[9] = {0,};
int N, M;

int compare(const void *a, const void *b)
{
    int A = *(int*)a;
    int B = *(int*)b;

    if(A > B)
    {
        return 1;
    }    
    else
    {
        return -1;
    }
}

void search(int count)
{
    if(count == M)
    {
        for(int i = 0 ; i < M; i++)
        {
            printf("%d ", print_arr[i]);
        }
        printf("\n");
    }

    else 
    {
        for(int i = 0; i < N; i++)
        {
            int check = 1;            

            for(int j = 0; j < count; j++)
            {
                if(print_arr[j] == arr[i])
                {
                    check = 0;
                }
            }
            //search(2)
            if(check)
            {
                print_arr[count] = arr[i];
                search(count+1);
             
            }
        }
    }

}


int main()
{  
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    search(0);

    return 0;
}