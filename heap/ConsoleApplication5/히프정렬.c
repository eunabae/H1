#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

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

typedef struct {
	long long heap[MAX];
	long long heap_size;
} HeapType;

HeapType *createheap() {
	HeapType *n;
	n = (HeapType *)malloc(sizeof(HeapType));
	n->heap_size = 0;
	return n;
}

void insertheap(HeapType *h, long long item)
{
	long long i;
	i = ++(h->heap_size);
	
	while ((i != 1) && (item > h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

long long deleteheap(HeapType *h) {
	long long deli = h->heap[1];
	long long lasti = h->heap[h->heap_size];
	long long parent = 1;
	long long child = 2;
	h->heap_size--;
	while (child <= h->heap_size) {
		if (h->heap[child] < h->heap[child + 1]) {
			child++;
		}
		if (lasti > h->heap[child]) break;
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}
	}
	h->heap[parent] = lasti;
	return deli;
}

int main()
{
	HeapType *heap;
	clock_t start, end;

	long long arr[MAX];
	long long size = MAX-1;
	long long i;
	
	rnum(arr);
	/*
	for ( i = 0;i < MAX;i++)
	{
		printf("arr[%lld]= %lld\n", i, arr[i]);
	}
	*/
	start = clock();

	heap = createheap();

	for (i = 0;i < size; i++){
		insertheap(heap, arr[i]);
		}

	for (i = size-1;i >= 0;i--) {
		arr[i] = deleteheap(heap);
	}
	
	end = clock();
	/*
	/for (i = 0;i < size; i++) 
		printf("%lld ", arr[i]);
	printf("\n");
	*/
	printf("걸린 시간: %f초 \n", (double)(end - start) / 1000);

	check(arr);
	return 0;
}