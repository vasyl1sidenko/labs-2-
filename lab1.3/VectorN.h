#pragma once
#include <string>

class VectorN
{
private:
	int N;
	double* a;

public:
	VectorN();
	VectorN(const VectorN& v);
	~VectorN();

	VectorN& operator=(const VectorN& v);

	int GetN() const { return N; }
	double GetA(int index) const { return a[index]; }

	bool SetN(int value);
	void SetA(int index, double value);

	bool Init(int n, double* values);
	void Read();
	void Display() const;
	std::string ToString() const;

	void Multiply(const VectorN& v, double k);
	bool Equal(const VectorN& v) const;
	double Length() const;
	int CompareLength(const VectorN& v) const;
};