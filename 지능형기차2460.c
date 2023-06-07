#include <stdio.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))


typedef struct train
{
    int get_on;//그 역에서 탄 인원
    int get_off;//그 역에서 내린 인원
    int num_of_passengers;//그 역에서의 인원
}TRAIN;

int main()
{   
    TRAIN T[10];

    int max = 0;//최대 인원 저장 위해 필요

    for(int i = 0; i < 10; i++)
    {
        scanf("%d %d", &T[i].get_off, &T[i].get_on);
        if(i == 0){//출발역이므로 타는 사람밖에 없음
            T[i].num_of_passengers = T[i].get_on;
        } else{//전 역에서의 인원 수 + 탄 인원 - 내린인원
            T[i].num_of_passengers = T[i-1].num_of_passengers + T[i].get_on - T[i].get_off;
        }
        max = MAX(max, T[i].num_of_passengers);//최댓값을 구해줌
    }
 
    printf("%d", max);

    return 0;
}