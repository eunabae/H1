#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void rnum(long long arr[]) {
	srand((unsigned int)time(NULL));
	for (long long i = 0; i < MAX;i++) {
		arr[i] = rand() % 100000;
	}
}

void check(long long arr[]) {
	for (long long i = 0; i < MAX; i++) {
		if (arr[i] <= arr[i + 1]) continue;
		else if (i = MAX - 1) {
			printf("finish\n");
			break;
		}
		else {
			printf("false\n"); break;
		}
	}
}

long long partition(long long arr[], long long left, long long right)
{
	long long pivot,temp;
	long long low, high;

	low = left;
	high = right + 1;
	pivot = arr[left]; 	/* 피벗 설정 */
	do {
		do
			low++;
		/* 왼쪽 리스트에서 피벗보다 큰 레코드 선택 */
		while (low <= right && arr[low]<pivot);
		do
			high--;
		/* 오른쪽 리스트에서 피벗보다 작은 레코드 선택 */
		while (high >= left && arr[high]>pivot);
		if (low < high) {
			SWAP(arr[low], arr[high], temp); /* 선택된 두 레코드 교환 */
		}
	} while (low<high);	  /* 인덱스 i,j가 엇갈리지 않는 한 반복 */
	SWAP(arr[left], arr[high], temp); /* 인텍스 j가 가리키는 레코드와 피벗 교환 */
	return high;
}


void quick_sort(long long arr[], long long left, long long right) {
	if (left <= right) {
		long long q = partition(arr, left, right);
		quick_sort(arr, left, q - 1);
		quick_sort(arr, q + 1, right);
	}
}

int main(void) {
	long long i;
	long long arr[MAX];
	long long left = 0;
	long long right = MAX-1;
	clock_t start, end;
	
	for (long long i = 0; i < MAX; i++) {
		arr[i] = 0;
	}
	rnum(arr);
/*	
	printf("before: ");
	for (i = 0; i < MAX; i++) {
		printf("%lld, ", arr[i]);
	}

	printf("\n\nafter: ");
	for (i = 0; i < MAX; i++) {
		printf("%lld, ", arr[i]);
	}
	*/
	start = clock();
	quick_sort(arr, left, right);
	end = clock();

	printf("걸린 시간: %f초 \n", (double)(end - start) / 1000);
	check(arr);
}