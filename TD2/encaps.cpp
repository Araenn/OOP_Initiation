#include <iostream>
using namespace std;

class Vehicule {

protected : 
	int vitesse[2];
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
};

int Vehicule::get_vitesse() {
	return vitesse[0];
}

void Vehicule::set_vitesse(int v) {
	vitesse[0] = v;
}

int Vehicule::get_vitesseMax() {
	return vitesse[1];
}

void Vehicule::set_vitesseMax(int v) {
	vitesse[1] = v;
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

int main() {
	Vehicule v;
	v.initialiser();
	v.afficher();
	for (int i = 0; i <= 5; i++) {
		v.accelerer();
		v.afficher();
	}
	return 0;
}