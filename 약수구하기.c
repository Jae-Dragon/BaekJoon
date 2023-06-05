#include <stdio.h>

int main()
{
    int N, k;
    scanf("%d %d", &N, &k);//약수의 개수를 구할 자연수 N과 k번째 작은 수를 구하기 위한 k

    int count = 0;//약수의 개수
    int T[10000] = {0};

    for(int i = 1; i <= N; i++)
    {
        if(N % i == 0){
            T[count++] = i;
        }
    }
    
    if(count < k) printf("0");
    else{
        printf("%d",T[k-1]);
    }





    return 0;
}