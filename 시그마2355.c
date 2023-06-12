#include <stdio.h>

int main()
{
    /* 이 문제는 시간제한이 있기에 */
    long long a, b;
    scanf("%lld %lld", &a, &b);

    long long max = 0, min = 0;
    max = a > b ? a : b;
    min = a < b ? a : b;


    long long total = 0, count = 0;
    count = max - min + 1;

    total = (a+b)*count/2;
  
    printf("%lld", total);

    return 0;
}

