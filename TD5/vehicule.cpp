#include "vehicule.h"
#define __DEBUG

Vehicule::Vehicule() {
	#ifdef __DEBUG
	cerr << "construction par defaut de vehicule" << endl;
	#endif
	set_vitesse(0);
	set_vitesseMax(130);
	set_poids(1);
}

Vehicule::Vehicule(int v) {
	#ifdef __DEBUG
	cerr << "cstror parametre de Vehicule (1)" << endl;
	#endif
	set_vitesseMax(130);
	set_vitesse(v);
	set_poids(1);
}

Vehicule::Vehicule(int v, int vmax) {
	#ifdef __DEBUG
	cerr << "cstror parametre de Vehicule (2)" << endl;
	#endif
	set_vitesseMax(vmax);
	set_vitesse(v);	
	set_poids(1);
}

Vehicule::Vehicule(int v, int vmax, double p) {
	#ifdef __DEBUG
	cerr << "cstror parametre de Vehicule (3)" << endl;
	#endif
	set_vitesseMax(vmax);
	set_vitesse(v);
	set_poids(p);
}

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

void Vehicule::afficher(void) {
	cout << get_vitesse() << "/" << get_vitesseMax() << ", " << get_poids() << " t." << endl;
}

void Vehicule::accelerer() {
	if ((get_vitesse() + 50) <= get_vitesseMax()) {
		set_vitesse(get_vitesse() + 50);
	} else {
		set_vitesse(get_vitesseMax());
	}
}

/*Vehicule Vehicule::attacher(Vehicule remorque) {
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
	#ifdef __DEBUG	
	cout << "test de operator=" << endl;
	#endif
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

double energie_cinetique(Vehicule V) {
	return V.get_poids() * V.get_vitesse() * V.get_vitesse();
}
*/

Vehicule::Vehicule(const Vehicule& v) {
	#ifdef __DEBUG		
	cerr << "cstror recopie de Vehicule" << endl;
	#endif
	vitesse = v.vitesse;
	vitesse_max = v.vitesse_max;
	poids = v.poids;
}


Vehicule::~Vehicule() {
	#ifdef __DEBUG		
	cout << "objet Vehicule detruit" << endl;
	#endif
}