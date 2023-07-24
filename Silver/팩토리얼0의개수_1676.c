#include <stdio.h>


int main()
{
    int n;
    scanf("%d", &n);

    int two = 0, five = 0;//2의 개수, 5의 개수

    for(int i = 2; i <= n; i++)
    {
        int g = i;
        while(g%2 == 0)
        {
            g/=2;
            two++;
        }
        while(g%5 == 0)
        {
            g/=5;
            five++;
        }
    }

    int count = 0;

    count = (two > five) ? five : two;

    printf("%d", count);

    return 0;
}

