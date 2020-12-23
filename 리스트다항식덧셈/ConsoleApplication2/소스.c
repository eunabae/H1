#include <stdio.h>
#define ROWS 3
#define COLS 3

void sparse_matrix_add1(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]) {
	int r, c;
	for (r = 0;r < ROWS;r++) {
		for (c = 0;c < COLS;c++) {
			C[r][c] = A[r][c] + B[r][c];
		}
	}
}

main() {
	int arr1[ROWS][COLS] = { {1,2,3} ,
							 {4,5,6},
							 {7,8,9} };
	int arr2[ROWS][COLS] = { { 1,2,3 } ,
							 { 4,5,6 },
							 { 7,8,9 } };
	int arr3[ROWS][COLS];
	sparse_matrix_add1(arr1, arr2, arr3);
}