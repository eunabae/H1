#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define MAX_QUEUE_SIZE 100


typedef int element;

typedef struct 
{
	element item;
	int rear;
	int front;
	int queue[MAX_QUEUE_SIZE];
}QueueType;


typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;

}TreeNode;


int is_full(QueueType *q) {
	return ((q->rear +1)%MAX_QUEUE_SIZE  == q->front);
}

int is_empty(QueueType *q) {
	return (q->front == q->rear);
}

void enqueue(QueueType *q, element item) {
	if (is_full(q))	perror("포화");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType *q) {
	if (is_empty(q))	perror("포화");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

void init(QueueType *q) 
{
	int i;
	for (i = 0; i<q->queue[MAX_QUEUE_SIZE]; i++)
		q->queue[i] = 0;
	q->front = q->rear = 0; 
}

level_order(TreeNode *root) {
	QueueType *q;
	TreeNode *x;
	q = (QueueType *)malloc(sizeof(QueueType));

	init(q);
	enqueue(q, root);

	while (!is_empty(q)) {
		x = dequeue(q);
		if (x->data != NULL)
			printf("%d\n", x->data);
		enqueue(q, x->left);
		enqueue(q, x->right);
		
	}
}

int maxnode(TreeNode *node) {
	int node_vlaue = node->data;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL) return node_vlaue = node->data;
		else {
			node_vlaue = max(maxnode(node->left), maxnode(node->right));
		}
	}
	return node_vlaue;
}


int minnode(TreeNode *node) {
	int node_vlaue = node->data;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL) return node_vlaue = node->data;
		else {
			node_vlaue = min(maxnode(node->left), maxnode(node->right));
		}
	}
	return node_vlaue;
}

void main() {
	TreeNode *n1, *n2, *n3;
	n1 = (TreeNode *)malloc(sizeof(TreeNode));
	n2 = (TreeNode *)malloc(sizeof(TreeNode));
	n3 = (TreeNode *)malloc(sizeof(TreeNode));

	n1->data = 15;
	n1->left = n2;
	n1->right = n3;
	
	n2->data = 30;
	n2->left = NULL;
	n2->right = NULL;

	n3->data = 10;
	n3->left = NULL;
	n3->right = NULL;
	if (maxnode(n1) < n1->data) {
		printf("max: %d\n", n1->data);
	}
	else printf("max: %d\n", maxnode(n1));

	if (minnode(n1) > n1->data) {
		printf("min: %d\n", n1->data);
	}
	else printf("min: %d\n", minnode(n1));

	level_order(n1);

}
