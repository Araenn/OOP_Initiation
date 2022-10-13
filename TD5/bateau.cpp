#include "bateau.h"
#define __DEBUG

Bateau::Bateau() :
Bateau(0, 60, 1, 50)
{
	#ifdef __DEBUG
	cout <<	"construction par defaut de Bateau " << endl;
	#endif
}

Bateau::Bateau(int v) :
Bateau(v, 60, 1, 50)
{
	#ifdef __DEBUG
	cout <<	"cstror parametre de Bateau (1)" << endl;
	#endif
}

Bateau::Bateau(int v, int vmax) :
Bateau(v, vmax, 1, 50)
{
	#ifdef __DEBUG
	cerr << "cstror parametre de Bateau (2)" << endl;
	#endif
}

Bateau::Bateau(int v, int vmax, double p) : 
Bateau(v, vmax, p, 50)
{
	#ifdef __DEBUG
	cerr << "cstror parametre de Bateau (3)" << endl;
	#endif
}

Bateau::Bateau(int v, int vmax, double p, int t)
{
	#ifdef __DEBUG
	cerr << "cstror parametre de Bateau (4)" << endl;
	#endif
	set_vitesseMax(vmax);
	set_vitesse(v);
	set_poids(p);
	set_tirant(t);
}


Bateau::Bateau(const Bateau& b) {
	#ifdef __DEBUG		
	cerr << "cstror recopie de Bateau" << endl;
	#endif
	vitesse = b.vitesse;
	vitesse_max = b.vitesse_max;
	poids = b.poids;
}


Bateau::~Bateau() {
	#ifdef __DEBUG		
	cout << "objet Bateau detruit" << endl;
	#endif
}

int Bateau::get_tirant() {
	return tirant;
}

void Bateau::set_tirant(int t) {
	#ifdef __DEBUG
	cout << "utilisation set tirant" << endl;
	#endif	
	if (t > 0)
		tirant = t;
}

bool Bateau::tester_surete_profondeur(int p) {
	#ifdef __DEBUG
	cout << "test surete" << endl;
	#endif
	if (tirant < p) {
		cout << "tirant inferieur profondeur" << endl;
		return true;
	}
}

void Bateau::accelerer() {
	#ifdef __DEBUG
	cout << "bateau accelere" << endl;
	#endif
	if ((get_vitesse() + 10) <= get_vitesseMax()) {
		set_vitesse(get_vitesse() + 10);
	} else {
		set_vitesse(get_vitesseMax());
	}
}
