#include <iostream>
using namespace std;

struct Vehicule {
	int vitesse;
	int vitesse_max;
	double poids;
};

void initialiser(struct Vehicule &v);
void afficher(struct Vehicule &v);
void accelerer (struct Vehicule &v);
void ralentir(struct Vehicule &v);

int main () {
	struct Vehicule V;
	initialiser(V);
	afficher(V);
	accelerer(V);
	afficher(V);
	accelerer(V);
	afficher(V);
	ralentir(V);
	afficher(V);
	return 0;
}

int max(int a, int b) {
	return a > b ? a : b;
}

void initialiser(struct Vehicule &v) {
	v = {.vitesse = 0, .vitesse_max = 130, .poids = 1};
}

void afficher(struct Vehicule &v) {
	cout << v.vitesse << "/" << v.vitesse_max << ", " << v.poids << " t." << endl;
}

void accelerer (struct Vehicule &v) {
	if ((v.vitesse + 50) < v.vitesse_max) {
		v.vitesse += 50;
	} else {
		v.vitesse = v.vitesse_max;
	}
}

void ralentir(struct Vehicule &v) {
	if (v.vitesse > 50) {
		v.vitesse -= 50;
	} else {
		v.vitesse = 0;
	}
}