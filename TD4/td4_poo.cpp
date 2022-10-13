#include <iostream>
using namespace std;

class Vehicule {

protected : 
	int vitesse;
	int vitesse_max;
	double poids;

public :
	int get_vitesse();
	void set_vitesse(int);
	int get_vitesseMax();
	void set_vitesseMax(int);
	double get_poids();
	void set_poids(double);
	void ralentir();
	void afficher();
	void accelerer();
	Vehicule();
	~Vehicule();
	Vehicule(int);
	Vehicule(int, int);
	Vehicule(int, int, double);
	Vehicule(const Vehicule& v);
	Vehicule attacher(Vehicule);
	Vehicule operator+(Vehicule);
	Vehicule operator*(double);
	friend Vehicule operator*(double, Vehicule);
	Vehicule& operator=(const Vehicule& v);
	friend ostream& operator<<(ostream&, Vehicule);
	friend istream& operator>>(istream&, Vehicule& v);
};

Vehicule::Vehicule() {
	set_vitesse(0);
	set_vitesseMax(130);
	set_poids(1);
	cerr << "constructeur par defaut de vehicule" << endl;
}

Vehicule::Vehicule(int v) {
	set_vitesseMax(130);
	set_vitesse(v);
	set_poids(1);
	cerr << "cstror parametre de Vehicule (1)" << endl;
}

Vehicule::Vehicule(int v, int vmax) {
	set_vitesseMax(vmax);
	set_vitesse(v);	
	set_poids(1);
	cerr << "cstror parametre de Vehicule (2)" << endl;
}

Vehicule::Vehicule(int v, int vmax, double p) {
	set_vitesseMax(vmax);
	set_vitesse(v);
	set_poids(p);
	cerr << "cstror parametre de Vehicule (3)" << endl;
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
	cout << "test de operator=" << endl;
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


Vehicule::Vehicule(const Vehicule& v) {
	cerr << "cstror recopie de Vehicule" << endl;
	vitesse = v.vitesse;
	vitesse_max = v.vitesse_max;
	poids = v.poids;
}


Vehicule::~Vehicule() {
	cout << "objet detruit" << endl;
}

int main() {
	Vehicule harley(60);
	cout << harley << endl;
	Vehicule suzuki(100, 240);
	cout << suzuki << endl;
	Vehicule ducati(120, 240, 0.5);
	cout << ducati << endl;
	Vehicule honda = 100; //constructeur parametre
	cout << honda << endl;
	Vehicule yamaha = 70;
	cout << yamaha << endl;
	cout << "Ec = " << energie_cinetique(yamaha) << endl;
	return 0;
}
