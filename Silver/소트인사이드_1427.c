#include <stdio.h>
#pragma warning(disable:4996)
#include<string.h>
#include <stdlib.h>
#include <time.h>


int inPlacePartiotion(int* L, int l, int r, int k);
void inPlaceQuickSort(int* L, int l, int r);
int findPivot(int min, int max);

void swap(int* a, int* b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}


int main()
{
    int arr[10] = {0}, N, i = 0;

    scanf("%d", &N);

    while(1)
    {
        arr[i++] = N % 10;

        if(N>=10)
        {
            N /= 10;
        }
        else
        {
            break;
        }
    }

    inPlaceQuickSort(arr, 0, i-1);

    for(int j = 0; j < i; j++)
    {
        printf("%d",arr[j]);
    }



    return 0;
}

int findPivot(int min, int max)
{
	srand(time(NULL));
	int k = 0;
	k = rand() % (max - min) + min;

	return k;
}
int inPlacePartiotion(int* L, int l, int r, int k)
{
	int temp;

	int p, i, j;
	p = L[k];//기준의 값 넣어줌

	//맨 오른쪽 값과 피벗의 값을 바꿔줌
	swap(&L[r], &L[k]);


	i = l;//맨 왼쪽 값
	j = r - 1;//맨 오른쪽 값(피벗 제외)


	while (i <= j) {//두개가 크로스 하기 전까지 실행
		while (i <= j && L[i] >= p)//왼쪽 값들이 피벗 값 이하라면 오른쪽으로 이동
			i = i + 1;
		while (j >= i && L[j] <= p)//오른쪽 값들이 피벗 값 이상이라면 왼쪽 이동
			j = j - 1;
		if (i < j) {//위에서 각각 걸리는 값들을 교환
			swap(&L[i], &L[j]);
		}

	}//크로스 되어 교환이 멈추면 피벗값과 i번째 원소를 교환

	swap(&L[i], &L[r]);


	return i;

}
void inPlaceQuickSort(int* L, int l, int r)
{
	if (l >= r) return;
	int k = findPivot(l, r);

	int a, b;

	a = b = inPlacePartiotion(L, l, r, k);

	//b = inPlacePartiotion(L, l, r, k);

	inPlaceQuickSort(L, l, a - 1);//각각 분할된 거에서 재귀실행
	inPlaceQuickSort(L, b + 1, r);//위와 동일

}
