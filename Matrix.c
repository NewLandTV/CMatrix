#include <stdio.h>

void Show(const int* m);

void Add(int m1[], int m2[])
{
	int result[4] = { m1[0] + m2[0], m1[1] + m2[1],
			   	      m1[2] + m2[2], m1[3] + m2[3] };

	Show(result);
}

void Sub(int m1[], int m2[])
{
	int result[4] = { m1[0] - m2[0], m1[1] - m2[1],
			   	      m1[2] - m2[2], m1[3] - m2[3] };

	Show(result);
}

void Mul(int m1[], int m2[])
{
	int result[4] = { m1[0] * m2[0], m1[1] * m2[1],
			   	      m1[2] * m2[2], m1[3] * m2[3] };

	Show(result);
}

void Div(int m1[], int m2[])
{
	int result[4] = { m1[0] / m2[0], m1[1] / m2[1],
			   	      m1[2] / m2[2], m1[3] / m2[3] };

	Show(result);
}

void Show(const int* m)
{
	unsigned short i;
	
	for (i = 0; i < 4; i++)
	{
		if (i == 2)
		{
			printf("\n");
		}
		
		printf("%d ", m[i]);
	}
	
	printf("\n");
}

int main(void)
{
	int m1[] = { 5, 6,
				 2, 4 };
				 
	int m2[] = { 5, 3,
				 1, 2 };
				 
	Add(m1, m2);
	Sub(m1, m2);
	Mul(m1, m2);
	Div(m1, m2);

	return 0;
}
