#include "fraction.h"

int Fraction::get_numerateur() {
	return numerateur;
}

void Fraction::set_numerateur(int n) {
	numerateur = n;
}

int Fraction::get_denominateur() {
	return denominateur;
}

void Fraction::set_denominateur(int d) {
	denominateur = d;
}

Fraction::Fraction() {
	set_numerateur(0);
	set_denominateur(1);
	cout << "initialisation" << endl;
}

Fraction::Fraction(int n) {
	set_numerateur(n);
	set_denominateur(1);
	cout << "choix du num" << endl;
}

Fraction::Fraction(int n, int d) {
	set_numerateur(n);
	set_denominateur(d);
	cout << "choix du num et den" << endl;
}

Fraction::Fraction(const Fraction& f) {
	set_numerateur(f.numerateur);
	set_denominateur(f.denominateur);
}

Fraction::~Fraction() {
	cout << "suppression de la fraction" << endl;
}

Fraction Fraction::operator+(Fraction& f) {
	Fraction a;
	a.set_numerateur(get_numerateur() + f.get_numerateur());
	a.set_denominateur(get_denominateur() + f.get_denominateur());
	return a;	
}

ostream& operator<<(ostream& c, Fraction f) {
	c << f.get_numerateur() << "/" << f.get_denominateur() << endl;
	return c;
}