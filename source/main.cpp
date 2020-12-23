#include<iostream>
#include<conio.h>
#include"utmatr.h"
#include"matrix.h"
using namespace std;
int main()
{
	TMatrix<int> a(7), b(7), c(7);
	int i, j;
	for (i = 0; i < 7; i++)
		for (j = 0; j < 7; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = (i * 10 + j) * 10;
		}
	c = a + b;
	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b = " << endl << b << endl;
	cout << "Matrix c = " << endl << c << endl;
	return 0;
}