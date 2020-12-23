#include <stdio.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 10
//

typedef struct  StackObjectRec {
	short r;
	short c;
} StackObject; //���ÿ� �� �� (r=row, c=col ��)

//typedef int element;  // element Ÿ�� ����

typedef struct {
	StackObject stack[MAX_STACK_SIZE];
	int top;
}StackType;  // StackŸ�� ����(stack �迭�� r, c�׸��� ���� ����ü �迭)// ���� �ϳ��� ���� �ɶ��� int element Ÿ��
// �迭�� Ÿ���� �迭�� ����Ǵ� ���� Ÿ������ ����

StackObject  stack[MAX_STACK_SIZE];
int  top = -1;
StackObject here = { 1,0 }, entry = { 1,0 };
// ���ÿ� �� ���� �����ϱ� ���� 1���� �迭 stack����
// here �� entry �迭�� 1,0�� ����
// top�� -1�� ���� - �� ����

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1','1','1','1','1','1','1','1','1','1' },
	{ 'e','0','0','0','1','0','0','0','0','1' },
	{ '1','0','0','0','1','0','0','0','0','1' },
	{ '1','0','1','1','1','0','0','1','0','1' },
	{ '1','0','0','0','1','0','0','1','0','1' },
	{ '1','0','1','0','1','0','0','1','0','1' },
	{ '1','0','1','0','1','0','0','1','0','1' },
	{ '1','0','1','0','1','0','0','1','0','1' },
	{ '1','0','1','0','0','0','0','1','0','x' },
	{ '1','1','1','1','1','1','1','1','1','1' },
};
// ������ 2���� �迭 �̷� ����


void initialize(StackType *s) // ���� �ʱ�ȭ, ���ڷ� ������ �ּ� ����
{
	s -> top = -1;
} // ���� Ÿ���� top�� -1�� �ʱ�ȭ

int isEmpty(StackType *s)
{
	return (s->top == -1);
}
// ������ ������� s�� �˻��� ���� 

int isFull(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// ������ ���� á����

void push(StackType *s, StackObject item)
{
	if (isFull(s)) {
		printf("stack is full\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
//���ÿ� �׸� ����(����) -> �츮�� ���� �� �� �迭

StackObject pop(StackType *s)
{
	if (isEmpty(s)) {
		printf("stack is empty\n");
		exit(-1);
	}
	else return s->stack[(s->top)--];
}
// ���ÿ� �׸� ����
void pushLoc(StackType *s, int r, int c)
{
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		StackObject tmp;
		tmp.r = r;
		tmp.c = c;
		push(s,tmp);  // ���� ����, ���� ��(���� Ÿ�� = ���� �迭�� Ÿ��)
	}
}

void main()
{
	int r, c;
	int i = 0, j=0;
	StackType s; // ���ü���, ������ġ
	here = entry;
	initialize(&s);
	
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		pushLoc(&s,r - 1, c);  //&s ���� �����Ϸ��� ��ġ, ����ϴ� ���� 
		pushLoc(&s,r + 1, c);
		pushLoc(&s,r, c - 1);
		pushLoc(&s,r, c + 1);
		if (isEmpty(&s)) {
			printf("����\n");
			return;
		}
		else
			here = pop(&s);
	}
	printf("����\n");
	return 0;
}