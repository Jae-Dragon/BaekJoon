/*
#include <stdio.h>

int main()
{
    long long N, Arr[50] = {0};
    scanf("%lld", &N);

    for(int i = 0; i < N; i++)
    {
        long long M;
        scanf("%lld", &M);
        Arr[i] = M;
    }

    for(long long i = 2;; i++)//찾을 약수
    {
        int pass = 0;


        for(int j = 0; j < N;j++){
            if(i % Arr[j] == 0 && Arr[j] != i){
                pass++;
            }
            else continue;
        }
        if(pass == N){
            printf("%lld", i);
            break;
        }

    }
    return 0;
}
*/
#include <stdio.h>
int main(){
    int N, val, max, min;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &val);
        if (!i){
            max = min = val;
            continue;
        }
        val > max && (max = val);
        val < min && (min = val);
    }
    printf("%d", max*min);
}