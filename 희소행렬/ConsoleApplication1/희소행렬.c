#include <stdio.h> 
#define ROWS 6
#define COLS 6 
#define MAX_TERMS 10


typedef struct {
	int row;
	int col;
	int value;
} element;


typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;   // ���� ���� 
	int cols;   // ���� ���� 
	int terms;  // 0�� �ƴ� ���� ���� 
} SparseMatrix;


// ���

void Print(SparseMatrix a)
{
	printf("row %d\t col %d \t term %d\n\n", a.rows, a.cols, a.terms);
	
	int arr[ROWS][COLS] = { 0 };
	int i=0;
	for (int r = 0;r<a.rows;r++)
	{
		for (int c = 0;c<a.cols;c++)
		{
				if (r == a.data[i].row && c == a.data[i].col)
					arr[r][c] = a.data[i++].value;
			printf("%3d", arr[r][c]);
		}
		printf("\n\n");
	}
}


// ��� ��� ���� �Լ� 
SparseMatrix sparse_matrix_add2(SparseMatrix a, SparseMatrix b)  // C=A+B 
{
	SparseMatrix c;
	int ca = 0, cb = 0, cc = 0;
	// ũ�Ⱑ �������� Ȯ�� 
	if (a.rows != b.rows || a.cols != b.cols) {
		fprintf(stderr, "������ ũ�⿡��\n");
		exit(1);
	}
	c.rows = a.rows;
	c.cols = a.cols;
	c.terms = 0;
	while (ca < a.terms && cb < b.terms) {
		int inda = a.data[ca].row * a.cols + a.data[ca].col;
		int indb = b.data[cb].row * b.cols + b.data[cb].col;
		if (inda < indb) {
			// b �׸��� �� ���߿� �;� �� 
			c.data[cc++] = a.data[ca++];
		}
		else if (inda == indb) {
			// a�� b�� ���� ��ġ
			if ((a.data[ca].value + b.data[cb].value) != 0) {
				c.data[cc].row = a.data[ca].row;
				c.data[cc].col = a.data[ca].col;
				c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
			}
			else {
				ca++; cb++;
			}
		}
		else
			c.data[cc++] = b.data[cb++];
	}
	// �������׵��� �ű��. 
	for (; ca < a.terms;)
		c.data[cc++] = a.data[ca++];
	for (; cb < b.terms;)
		c.data[cc++] = b.data[cb++];
	c.terms = cc;
	return c;
}


// ���Լ� 
main()
{
	SparseMatrix m1 = { { { 0,0,1 },{ 1,1,1 },{ 2,1,1 },{ 3,2,1 },{ 4,3,1 },{ 5,1,2 },{ 5,3,-1 } },6,6,7 };
	SparseMatrix m2 = { { { 0,0,1 },{ 1,0,1 },{ 2,1,1 },{ 3,2,1 },{ 4,0,1 },{ 5,0,1 } }, 6,6,6 };
	SparseMatrix m3;

	m3 = sparse_matrix_add2(m1, m2);

	Print(m3);
}

