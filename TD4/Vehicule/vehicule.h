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
	double energie_cinetique(Vehicule);