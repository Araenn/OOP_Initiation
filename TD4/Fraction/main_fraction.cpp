#include "fraction.h"

int main() {
	Fraction A;
	cout << A << endl;
	Fraction B(1, 2);
	cout << B << endl;
	Fraction C = 3;
	cout << C << endl;
	A = B + C;
	cout << A << endl;
	return 0;
}