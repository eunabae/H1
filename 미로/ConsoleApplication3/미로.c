#include <stdio.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 10
//

typedef struct  StackObjectRec {
	short r;
	short c;
} StackObject; //스택에 들어갈 값 (r=row, c=col 값)

//typedef int element;  // element 타입 정의

typedef struct {
	StackObject stack[MAX_STACK_SIZE];
	int top;
}StackType;  // Stack타입 정의(stack 배열이 r, c항목을 갖는 구조체 배열)// 값이 하나씩 저장 될때는 int element 타입
// 배열의 타입은 배열에 저장되는 값의 타입으로 선언

StackObject  stack[MAX_STACK_SIZE];
int  top = -1;
StackObject here = { 1,0 }, entry = { 1,0 };
// 스택에 들어갈 값을 정의하기 위해 1차원 배열 stack선언
// here 과 entry 배열은 1,0을 가짐
// top은 -1로 정의 - 빈 스택

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
// 메이즈 2차원 배열 미로 형태


void initialize(StackType *s) // 스택 초기화, 인자로 스택의 주소 받음
{
	s -> top = -1;
} // 스택 타입의 top를 -1로 초기화

int isEmpty(StackType *s)
{
	return (s->top == -1);
}
// 스택이 비었는지 s는 검사할 스택 

int isFull(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 스택이 가득 찼는지

void push(StackType *s, StackObject item)
{
	if (isFull(s)) {
		printf("stack is full\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
//스택에 항목 삽입(정수) -> 우리가 삽입 할 건 배열

StackObject pop(StackType *s)
{
	if (isEmpty(s)) {
		printf("stack is empty\n");
		exit(-1);
	}
	else return s->stack[(s->top)--];
}
// 스택에 항목 삭제
void pushLoc(StackType *s, int r, int c)
{
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		StackObject tmp;
		tmp.r = r;
		tmp.c = c;
		push(s,tmp);  // 저장 스택, 저장 값(값의 타입 = 스택 배열의 타입)
	}
}

void main()
{
	int r, c;
	int i = 0, j=0;
	StackType s; // 스택선언, 저장위치
	here = entry;
	initialize(&s);
	
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		pushLoc(&s,r - 1, c);  //&s 값을 저장하려는 위치, 사용하는 스택 
		pushLoc(&s,r + 1, c);
		pushLoc(&s,r, c - 1);
		pushLoc(&s,r, c + 1);
		if (isEmpty(&s)) {
			printf("실패\n");
			return;
		}
		else
			here = pop(&s);
	}
	printf("성공\n");
	return 0;
}