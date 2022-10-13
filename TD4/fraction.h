#include <iostream>
using namespace std;

class Fraction {

protected: 
	int numerateur;
	int denominateur;

public:
	int get_numerateur();
	void set_numerateur(int);
	int get_denominateur();
	void set_denominateur(int);
	Fraction();
	Fraction(int);
	Fraction(int, int);
	Fraction(const Fraction& f);
	~Fraction();
	Fraction operator+(Fraction&);
	friend ostream& operator<<(ostream& c, Fraction);
};