/*
*
* by UnitedTimur
*/

#include <iostream>
#include <fstream>

using namespace std;

void print(int **, int);

void get(int **, int **, int, int, int);

int det(int **, int);

void error();

int main() 
{
	cout << "//The first number in the file is the size of the array." << endl;
	cout << "//The remaining numbers are the determinant values." << endl;

	ifstream file("determinant.txt");

	if (!file.is_open())
	{
		error();
	}

	int size = 0;

	file >> size;

	int **arr = new int*[size] {};

	for (auto i = 0; i < size; i++)
	{
		arr[i] = new int[size] {};

	}

	for (auto i = 0; i < size && !file.eof(); i++)
	{
		for (auto j = 0; j < size; j++)
		{
			file >> arr[i][j];
		}
	}

	print(arr, size);

	int d = det(arr, size);

	cout << "Determinant is " << "[" << d << "]" << endl;

	ofstream _file("answer.txt");

	if (size != 0)
	{
		_file << "Your determinant here: " << endl;

		for (auto i = 0; i < size; i++)
		{
			for (auto j = 0; j < size; j++)
			{
				_file << "[" << arr[i][j] << "] ";
			}
			_file << endl;
		}

		_file << "Determinant is " << "[" << d << "]";
	}
	
	file.close();
	_file.close();

	getchar();
	return 0;
}

void print(int **arr, int size) 
{
	for (auto i = 0; i < size; i++)
	{
		for (auto j = 0; j < size; j++)
		{
			cout << "[" << arr[i][j] << "] ";
		}
		cout << endl;
	}
}

void get(int **arr, int **p, int i, int j, int size) 
{
	int di, dj;

	di = 0;

	for (auto ki = 0; ki < size - 1; ki++)
	{

		if (ki == i) di = 1;

		dj = 0;

		for (auto kj = 0; kj < size - 1; kj++)
		{
			if (kj == j) dj = 1;
			p[ki][kj] = arr[ki + di][kj + dj];
		}
	}
}

int det(int** arr, int size)
{
	int d, k, n;

	int **p;

	p = new int*[size];

	for (auto i = 0; i < size; i++)
	{
		p[i] = new int[size];
	}
	auto j = 0;
	d = 0;
	k = 1;
	n = size - 1;

	if (size < 1)
		error();
	if (size == 1)
	{
		d = arr[0][0];
		return d;
	}
	if (size == 2)
	{
		d = arr[0][0] * arr[1][1] - (arr[1][0] * arr[0][1]);
		return d;
	}
	if (size > 2)
	{
		for (auto i = 0; i < size; i++)
		{
			get(arr, p, i, 0, size);

			cout << arr[i][j] << endl;

			print(p, n);

			d += k * arr[i][0] * det(p, n);
			
			k = -k;
		}
	}
	return d;
}

void error()
{
	cout << "Fatal error. Try again ;(" << endl;
	system("pause");
	exit(-1);
}
