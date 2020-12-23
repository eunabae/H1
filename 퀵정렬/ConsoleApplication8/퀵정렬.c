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
	pivot = arr[left]; 	/* �ǹ� ���� */
	do {
		do
			low++;
		/* ���� ����Ʈ���� �ǹ����� ū ���ڵ� ���� */
		while (low <= right && arr[low]<pivot);
		do
			high--;
		/* ������ ����Ʈ���� �ǹ����� ���� ���ڵ� ���� */
		while (high >= left && arr[high]>pivot);
		if (low < high) {
			SWAP(arr[low], arr[high], temp); /* ���õ� �� ���ڵ� ��ȯ */
		}
	} while (low<high);	  /* �ε��� i,j�� �������� �ʴ� �� �ݺ� */
	SWAP(arr[left], arr[high], temp); /* ���ؽ� j�� ����Ű�� ���ڵ�� �ǹ� ��ȯ */
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

	printf("�ɸ� �ð�: %f�� \n", (double)(end - start) / 1000);
	check(arr);
}