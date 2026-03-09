#include "VectorN.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

VectorN::VectorN()
{
	N = 0;
	a = nullptr;
}

VectorN::VectorN(const VectorN& v)
{
	N = v.N;
	if (N > 0)
	{
		a = new double[N];
		for (int i = 0; i < N; i++)
			a[i] = v.a[i];
	}
	else
		a = nullptr;
}

VectorN::~VectorN()
{
	delete[] a;
}

VectorN& VectorN::operator=(const VectorN& v)
{
	if (this != &v)
	{
		delete[] a;
		N = v.N;

		if (N > 0)
		{
			a = new double[N];
			for (int i = 0; i < N; i++)
				a[i] = v.a[i];
		}
		else
			a = nullptr;
	}
	return *this;
}

bool VectorN::SetN(int value)
{
	if (value > 0)
	{
		N = value;
		a = new double[N];
		return true;
	}
	else
	{
		N = 0;
		a = nullptr;
		return false;
	}
}

void VectorN::SetA(int index, double value)
{
	if (index >= 0 && index < N)
		a[index] = value;
}

bool VectorN::Init(int n, double* values)
{
	delete[] a;
	a = nullptr;

	if (!SetN(n))
		return false;

	for (int i = 0; i < N; i++)
		a[i] = values[i];

	return true;
}

void VectorN::Read()
{
	int n;
	do
	{
		cout << "Input dimension N = ";
		cin >> n;
	} while (n <= 0);

	double* values = new double[n];

	cout << "Input vector coordinates:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> values[i];
	}

	Init(n, values);

	delete[] values;
}

void VectorN::Display() const
{
	cout << ToString() << endl;
}

string VectorN::ToString() const
{
	stringstream sout;
	sout << "(";
	for (int i = 0; i < N; i++)
	{
		sout << a[i];
		if (i < N - 1)
			sout << ", ";
	}
	sout << ")";
	return sout.str();
}

void VectorN::Multiply(const VectorN& v, double k)
{
	delete[] a;
	N = v.N;
	a = new double[N];

	for (int i = 0; i < N; i++)
		a[i] = v.a[i] * k;
}

bool VectorN::Equal(const VectorN& v) const
{
	if (N != v.N)
		return false;

	for (int i = 0; i < N; i++)
	{
		if (a[i] != v.a[i])
			return false;
	}

	return true;
}

double VectorN::Length() const
{
	double sum = 0;

	for (int i = 0; i < N; i++)
		sum += a[i] * a[i];

	return sqrt(sum);
}

int VectorN::CompareLength(const VectorN& v) const
{
	double l1 = Length();
	double l2 = v.Length();

	if (l1 > l2)
		return 1;
	else if (l1 < l2)
		return -1;
	else
		return 0;
}