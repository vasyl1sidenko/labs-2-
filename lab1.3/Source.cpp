#include <iostream>
#include "VectorN.h"

using namespace std;

int main()
{
	VectorN v1, v2, v3;
	double k;

	cout << "Vector v1:" << endl;
	v1.Read();
	v1.Display();

	cout << endl << "Vector v2:" << endl;
	v2.Read();
	v2.Display();

	cout << endl << "Input scalar k = ";
	cin >> k;

	v3.Multiply(v1, k);
	cout << endl << "Vector v3 = v1 * k:" << endl;
	v3.Display();

	cout << endl << "Length of v1 = " << v1.Length() << endl;
	cout << "Length of v2 = " << v2.Length() << endl;

	if (v1.Equal(v2))
		cout << "Vectors are equal" << endl;
	else
		cout << "Vectors are not equal" << endl;

	int result = v1.CompareLength(v2);

	if (result == 1)
		cout << "Length of v1 is greater than length of v2" << endl;
	else if (result == -1)
		cout << "Length of v1 is less than length of v2" << endl;
	else
		cout << "Lengths of vectors are equal" << endl;

	return 0;
}