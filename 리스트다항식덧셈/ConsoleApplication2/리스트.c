#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode *link;
} ListNode;

typedef struct ListHeader {
	int length;
	ListNode *head;
	ListNode *tail;
} ListHeader;

// 초기화 함수
void init(ListHeader *plist)
{
	plist->length = 0;
	plist->head = plist->tail = NULL;
}

// plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, expon는 지수
void insert_node_last(ListHeader *plist, int coef, int expon)
{
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당 에러\n");
		exit(1);
	}
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->length++;
}
//
void poly_add(ListHeader *plist1, ListHeader *plist2, ListHeader *plist3)
{
	ListNode *a = plist1->head;
	ListNode *b = plist2->head;
	int sum;
	while (a && b) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0) insert_node_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {
			insert_node_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_node_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}
	// a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 
	// 결과 다항식으로 복사
	for (; a != NULL; a = a->link)
		insert_node_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_node_last(plist3, b->coef, b->expon);
}
//
void poly_print(ListHeader *plist)
{
	ListNode *p = plist->head;
	for (; p; p = p->link) {
		printf("%dx^%d", p->coef, p->expon);
		if (p->link == NULL) break;
		else printf(" + ");
	}
}
//
int main()
{
	ListHeader list1, list2, list3;

	init(&list1);
	init(&list2);
	init(&list3);


	printf("다항식 1:");
	// 다항식 1을 생성 
	insert_node_last(&list1, 3, 6);
	insert_node_last(&list1, 7, 3);
	insert_node_last(&list1, -2, 2);
	insert_node_last(&list1, -9, 0);
	poly_print(&list1);
	printf("\n");

	printf("다항식 2:");
	// 다항식 2를 생성 
	insert_node_last(&list2, -2, 6);
	insert_node_last(&list2, -4, 4);
	insert_node_last(&list2, 6, 1);
	insert_node_last(&list2, 1, 0);
	poly_print(&list2);
	printf("\n");

	// 다항식 3 = 다항식 1 + 다항식 2
	printf("다항식 3:");
	poly_add(&list1, &list2, &list3);
	poly_print(&list3);
	printf("\n");
}