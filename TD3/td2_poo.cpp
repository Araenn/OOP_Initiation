#include <iostream>
using namespace std;

class Vehicule {

protected : 
	int vitesse;
	int vitesse_max;
	int poids;

public :
	int get_vitesse();
	void set_vitesse(int);
	int get_vitesseMax();
	void set_vitesseMax(int);
	double get_poids();
	void set_poids(double);
	void ralentir();
	void initialiser();
	void afficher();
	void accelerer();
	Vehicule attacher(Vehicule);
	Vehicule operator+(Vehicule);
	Vehicule operator*(double);
	friend Vehicule operator*(double, Vehicule);
	Vehicule& operator=(const Vehicule& v);
	friend ostream& operator<<(ostream&, Vehicule);
	friend istream& operator>>(istream&, Vehicule& v);
};

int Vehicule::get_vitesse() {
	return vitesse;
}

void Vehicule::set_vitesse(int v) {
	vitesse = v;
	if (vitesse > vitesse_max)
		vitesse = vitesse_max;
}

int Vehicule::get_vitesseMax() {
	return vitesse_max;
}

void Vehicule::set_vitesseMax(int v) {
	vitesse_max = v;
}

double Vehicule::get_poids() {
	return poids;
}

void Vehicule::set_poids(double p) {
	poids = p;
}

void Vehicule::ralentir(void) {
	int vitesse = get_vitesse();
	set_vitesse(vitesse - 50);
	if (vitesse < 0) {
		set_vitesse(0);
	}
}

void Vehicule::initialiser(void) {
	set_vitesse(0);
	set_vitesseMax(130);
	set_poids(1);
}

void Vehicule::afficher(void) {
	cout << get_vitesse() << "/" << get_vitesseMax() << ", " << get_poids() << " t." << endl;
}

void Vehicule::accelerer(void) {
	int vitesse = get_vitesse();
	int vitesse_max = get_vitesseMax();	
	if ((vitesse + 50) < vitesse_max) {
		set_vitesse(vitesse + 50);
	} else {
		set_vitesse(vitesse_max);
	}
}

Vehicule Vehicule::attacher(Vehicule remorque) {
	Vehicule attelage;
	vitesse = get_vitesse();
	vitesse_max = get_vitesseMax();
	attelage.set_vitesse(vitesse);
	attelage.set_vitesseMax(vitesse_max);	
	attelage.set_poids(remorque.get_poids() + get_poids());
	return attelage;
}

Vehicule Vehicule::operator+(Vehicule remorque) {
	Vehicule attelage;
	vitesse = get_vitesse();
	vitesse_max = get_vitesseMax();
	attelage.set_vitesse(vitesse);
	attelage.set_vitesseMax(vitesse_max);	
	attelage.set_poids(remorque.get_poids() + get_poids());
	return attelage;
}

/**
Vehicule Vehicule::operator*(double nVitesse) {
	Vehicule m;	
	m.set_vitesse(vitesse*nVitesse);
	m.set_vitesseMax(vitesse_max);
	if (vitesse*nVitesse > vitesse_max)
		m.set_vitesse(vitesse_max);
	m.set_poids(poids);
	return m;
}
*/

Vehicule Vehicule::operator*(double nVitesse) {
	Vehicule m = *this;
	m.set_vitesse(vitesse*nVitesse);
	return m;
}

Vehicule& Vehicule::operator=(const Vehicule& v) {
	if (&v == this)
		return *this;	
	vitesse = v.vitesse;
	vitesse_max = v.vitesse_max;
	poids = v.poids;
	return *this;
}


Vehicule operator*(double nVitesse, Vehicule r) {
	Vehicule V;
	V = r;
	V.set_vitesse(nVitesse * r.vitesse);
	return V;
}

ostream& operator<<(ostream& c, Vehicule v) {
	c << v.get_vitesse() << "/" << v.get_vitesseMax() << ", " << v.get_poids() << " t.";
	return c;
}

istream& operator>>(istream& c, Vehicule& v) {
	c >> v.vitesse >> v.vitesse_max >> v.poids;
	return c;
}
int main() {
	Vehicule v, r, attelage, moto;
	v.initialiser();
	cout << "Soit la voiture v :" << endl;
	v.afficher();
	for (int i = 0; i <= 5; i++) {
		v.accelerer();
		v.afficher();
	}
	r.initialiser();
	cout << "Soit la remorque de v/vmax et p :" << endl;
	r.afficher();
	cout << "On attache la remorque a la voiture." << endl;
	attelage = v.attacher(r);
	cout << "Voici le nouvel ensemble : " << endl;
	attelage.afficher();

	cout << "test de operator+() : " << endl;
	attelage = v + r;
	attelage.afficher();

	moto.initialiser();
	moto.set_vitesse(60);
	cout << "On augmente la vitesse de moto par 1.5:" << endl;
	moto = moto * 1.5;
	moto.afficher();
	cout << "Encore une fois :" << endl;
	moto = moto * 1.5;
	moto.afficher();

	Vehicule m;
	m.initialiser();
	m.set_vitesse(60);
	cout << "Test surcharge de operator*" << endl;
	m = 1.5 * m;
	m.afficher();
	m = 1.5 * m;
	m.afficher();

	Vehicule voiture_b;
	voiture_b.initialiser();
	cout << "Soit la voiture B" << endl;
	voiture_b.afficher();
	cout << "et la moto precedente" << endl;
	m.afficher();
	m.operator=(voiture_b);
	cout << "Magie : la moto devient voiture !" << endl;
	m.afficher();

	v = r = attelage = moto;
	v.afficher();

	cout << "test de l'affchage :" << endl;
	cout << moto << endl;
	return 0;
}
