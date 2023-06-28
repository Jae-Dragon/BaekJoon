#include <stdio.h>

int main()
{
    int x, S = 64, cnt = 0;
    scanf("%d", &x);

    while(x > 0)//x가 0이 되어야 원하는 막대 길이를 충족시키는 것
    {
        if(S > x){
            S /= 2;
        }
        else{
            cnt++;
            x -= S;
        }
    }
    printf("%d",cnt);

    return 0;
}