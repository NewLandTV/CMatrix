#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "Matrix.h"

// r x c ũ���� ������� ��ȯ�մϴ�.
PMatrix ZeroMat(size_t numberColumn, size_t numberRow)
{
	PMatrix matrix = (PMatrix)malloc(sizeof(Matrix));

	// �޸� �Ҵ� ���� �� �׳� NULL ��ȯ�մϴ�. (������� �����)
	if (matrix == NULL)
	{
		return NULL;
	}

	memset(matrix->elements, 0, sizeof(int) * MAX_MATRIX_SIZE * MAX_MATRIX_SIZE);

	for (size_t c = 0; c < numberColumn; c++)
	{
		for (size_t r = 0; r < numberRow; r++)
		{
			matrix->elements[c][r] = 0;
		}
	}

	matrix->numberRow = numberRow;
	matrix->numberColumn = numberColumn;

	return matrix;
}

PMatrix GetMat(int(*elements)[MAX_MATRIX_SIZE], size_t numberColumn, size_t numberRow)
{
	PMatrix matrix = ZeroMat(numberColumn, numberRow);

	// �޸� �Ҵ� ���� �� �׳� NULL ��ȯ�մϴ�. (������� �����)
	if (matrix == NULL)
	{
		return NULL;
	}

	for (size_t c = 0; c < numberColumn; c++)
	{
		for (size_t r = 0; r < numberRow; r++)
		{
			matrix->elements[c][r] = elements[c][r];
		}
	}

	return matrix;
}

PMatrix MatAdd(PMatrix a, PMatrix b)
{
	size_t columnA = a->numberColumn;
	size_t rowA = a->numberRow;
	size_t columnB = b->numberColumn;
	size_t rowB = b->numberRow;

	// ���� �Ұ� (�԰��� ���� ����)
	if (columnA != columnB || rowA != rowB)
	{
		return NULL;
	}

	PMatrix result = GetMat(a->elements, a->numberColumn, a->numberRow);

	for (size_t c = 0; c < columnA; c++)
	{
		for (size_t r = 0; r < rowA; r++)
		{
			result->elements[c][r] += b->elements[c][r];
		}
	}

	return result;
}

PMatrix MatSub(PMatrix a, PMatrix b)
{
	size_t columnA = a->numberColumn;
	size_t rowA = a->numberRow;
	size_t columnB = b->numberColumn;
	size_t rowB = b->numberRow;

	// ���� �Ұ� (�԰��� ���� ����)
	if (columnA != columnB || rowA != rowB)
	{
		return NULL;
	}

	PMatrix result = GetMat(a->elements, a->numberColumn, a->numberRow);

	for (size_t c = 0; c < columnA; c++)
	{
		for (size_t r = 0; r < rowA; r++)
		{
			result->elements[c][r] -= b->elements[c][r];
		}
	}

	return result;
}

PMatrix MatScalarMul(int k, PMatrix a)
{
	PMatrix result = GetMat(a->elements, a->numberColumn, a->numberRow);
	size_t column = a->numberColumn;
	size_t row = a->numberRow;

	for (size_t c = 0; c < column; c++)
	{
		for (size_t r = 0; r < row; r++)
		{
			result->elements[c][r] *= k;
		}
	}

	return result;
}

PMatrix MatMul(PMatrix a, PMatrix b)
{
	// TODO : ����� ���� ���� (l x n) (n x k) ��ĸ� ������.

	return NULL;
}

void PrintMat(PMatrix matrix)
{
	size_t numberColumn = matrix->numberColumn;
	size_t numberRow = matrix->numberRow;

	for (size_t c = 0; c < numberColumn; c++)
	{
		printf("( ");

		for (size_t r = 0; r < numberRow; r++)
		{
			printf("%d", matrix->elements[c][r]);

			if (r != numberRow - 1)
			{
				printf("\t");
			}
			else
			{
				printf(" ");
			}
		}

		printf(")\n");
	}
}