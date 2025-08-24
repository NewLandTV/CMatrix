#ifndef __MATRIX_H__
#define __MATRIX_H__

#define MAX_MATRIX_SIZE 4

#define delete(m) free((m))

// ��� ����ü(r x c)
typedef struct _Matrix
{
	int elements[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
	size_t numberColumn;
	size_t numberRow;
} Matrix, *PMatrix;

// ����� �ʱ�ȭ
PMatrix ZeroMat(size_t numberColumn, size_t numberRow);
PMatrix GetMat(int (*elements)[MAX_MATRIX_SIZE], size_t numberColumn, size_t numberRow);

// ����� ����
PMatrix MatAdd(PMatrix a, PMatrix b);
PMatrix MatSub(PMatrix a, PMatrix b);
PMatrix MatScalarMul(int k, PMatrix a);
PMatrix MatMul(PMatrix a, PMatrix b);	// TODO : ����� ���� (Next time...)

// ����� ���
void PrintMat(PMatrix matrix);

#endif