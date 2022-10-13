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
};

int Vehicule::get_vitesse() {
	return vitesse;
}

void Vehicule::set_vitesse(int v) {
	::vitesse = v;
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
	if (get_vitesse() > 50) {
		set_vitesse(get_vitesse() - 50);
	} else {
		set_vitesse(0);
	}
}

void Vehicule::initialiser(void) {
	set_vitesseMax(130);
	set_vitesse(15);
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
	int vitesse = get_vitesse();
	int vitesse_max = get_vitesseMax();
	attelage.set_vitesse(vitesse);
	attelage.set_vitesseMax(vitesse_max);	
	attelage.set_poids(remorque.get_poids() + get_poids());
	return attelage;
}

Vehicule Vehicule::operator+(Vehicule remorque) {
	return attacher(remorque);
}

int main(int argc, char** args) {
	Vehicule v, r, attelage;
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
	return 0;
}