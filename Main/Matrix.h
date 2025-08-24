#ifndef __MATRIX_H__
#define __MATRIX_H__

#define MAX_MATRIX_SIZE 4

#define delete(m) free((m))

// 행렬 구조체(r x c)
typedef struct _Matrix
{
	int elements[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
	size_t numberColumn;
	size_t numberRow;
} Matrix, *PMatrix;

// 행렬의 초기화
PMatrix ZeroMat(size_t numberColumn, size_t numberRow);
PMatrix GetMat(int (*elements)[MAX_MATRIX_SIZE], size_t numberColumn, size_t numberRow);

// 행렬의 연산
PMatrix MatAdd(PMatrix a, PMatrix b);
PMatrix MatSub(PMatrix a, PMatrix b);
PMatrix MatScalarMul(int k, PMatrix a);
PMatrix MatMul(PMatrix a, PMatrix b);	// TODO : 행렬의 곱셈 (Next time...)

// 행렬의 출력
void PrintMat(PMatrix matrix);

#endif