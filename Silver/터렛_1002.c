#include <stdio.h>
#include <math.h>

double distance(int x1, int y1, int x2, int y2);

int main()
{
    int x1, x2, y1, y2, r1, r2, N;
    scanf("%d", &N);

    /* 좌표와 거리를 원이라고 생각하고 교점의 개수를 구해야 함 */
    /* -1인 경우: 완벽히 겹쳐야함 */
    /* 0인 경우: 교점 x */
    /* 1인경우: 접함 */
    /* 2인경우: 교점이 2개 */


    /* 케이스 별로 분류하여 교점의 개수를 알아내야 함 */
    for(int i = 0; i < N; i++)
    {
        int meet = 0, sum = 0, sub = 0;
       
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        double dis = distance(x1, y1, x2, y2);
        sum = r1 + r2;
        sub = r1 > r2 ? r1 - r2 : r2 - r1;

        /* -1이 출려되는 경우: 둘의 좌표가 같고 거리도 같을 때 */
        if(dis == 0 && r1 == r2){
            printf("-1\n");
        }
        /* 2가 출력되는 경우: 완전히 겹쳐지지 않고 교점이 2개 */
        else if(dis < sum && dis > sub)
        {
            printf("2\n");
        }
        /* 1이 출력되는 경우: 완전히 접할 때 */
        else if(dis == sum || dis == sub)
        {
            printf("1\n");
        }
        /* 0이 출력되는 경우 */
        else
        {
            printf("0\n");
        }

    }


    return 0;
}


double distance(int x1, int y1, int x2, int y2)
{
    double dis = 0;
    
    dis = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    return dis;
}