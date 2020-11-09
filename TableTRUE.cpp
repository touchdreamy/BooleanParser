#include "TableTRUE.h"
#include <iostream>

using namespace std;

void Table::ReturnLine(const int num, int *arr)
{
	for (int i = 0; i < width; ++i)
	{
		arr[i] = T[num][i];
	}
}

int**Table::Transpose()
{
	T = new int*[height];
	for (int i = 0; i < height; i++)
	{
		T[i] = new int[width];
	}

	for (int i = 1; i <= width; i++)
	{
		for (int j = 1; j <= height; j++)
		{
			T[j-1][i-1] = matrix[i][j];
		}
	}

	return T;
}

void Table::CreateTable()
{
	matrix = new int *[width + 1];
	for (int i = 1; i <= width; i++)
	{
		matrix[i] = new int[height + 1];
	}


	for (int i = 1; i <= width; i++)
	{
		for (int j = 1; j <= height; j++)
		{
			matrix[i][j] = 0;
		}
	}

	int q, p, c;
	for (int j = 1; j <= width; j++)
	{
		q = height / (pow(2, j));
		p = 0;
		c = 0;
		for (int i = q + 1; i <= height; i++)
		{
			if (p < q)
			{
				matrix[j][i] = 1;
				p++;
			}
			else if (c < q - 1)
			{
				matrix[j][i] = 0;
				c++;
			}
			else
			{
				p = 0;
				c = 0;
			}
		}
	}
}

void Table::Print()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << T[i][j] << ' ';
		}
		cout << endl;
	}
}