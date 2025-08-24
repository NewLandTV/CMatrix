#include <stdio.h>
#include "Matrix.h"

int main(void)
{
	int a[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = { { 9, -2 },
												{ 3, -3 } };
	int b[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE] = { { 1, 2 },
												{ 3, 4 } };
	PMatrix A = GetMat(a, 2, 2);
	PMatrix B = GetMat(b, 2, 2);

	printf("---[µ¡¼À]---\n\n");

	PMatrix C = MatAdd(A, B);

	PrintMat(A);
	printf("+\n");
	PrintMat(B);
	printf("=\n");
	PrintMat(C);

	delete(C);

	printf("\n\n---[»¬¼À]---\n\n");
	C = MatSub(A, B);

	PrintMat(A);
	printf("-\n");
	PrintMat(B);
	printf("=\n");
	PrintMat(C);

	delete(C);

	printf("\n\n---[½Ç¼ö¹è]---\n\n");
	C = MatScalarMul(3, A);

	printf("3 *\n");
	PrintMat(A);
	printf("=\n");
	PrintMat(C);

	delete(A);
	delete(B);
	delete(C);

	return 0;
}