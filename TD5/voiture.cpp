#include "voiture.h"

Voiture::Voiture() :
Voiture(0, 130, 1)
{
	#ifdef __DEBUG
	cout <<	"construction par defaut de Voiture " << endl;
	#endif
}

Voiture::Voiture(int v) :
Voiture(v, 130, 1)
{
	#ifdef __DEBUG
	cout <<	"cstror parametre de Voiture (1)" << endl;
	#endif
}

Voiture::Voiture(int v, int vmax) :
Voiture(v, vmax, 1)
{
	#ifdef __DEBUG
	cerr << "cstror parametre de Voiture (2)" << endl;
	#endif
}

Voiture::Voiture(int v, int vmax, double p)
{
	#ifdef __DEBUG
	cerr << "cstror parametre de Voiture (3)" << endl;
	#endif
    set_vitesseMax(vmax);
    set_vitesse(v);
    set_poids(p);
}


Voiture::Voiture(const Voiture& b) {
	#ifdef __DEBUG		
	cerr << "cstror recopie de Voiture" << endl;
	#endif
	vitesse = b.vitesse;
	vitesse_max = b.vitesse_max;
	poids = b.poids;
}


Voiture::~Voiture() {
	#ifdef __DEBUG		
	cout << "objet Voiture detruit" << endl;
	#endif
}

void Voiture::accelerer() {
	if ((get_vitesse() + 50) <= get_vitesseMax()) {
		set_vitesse(get_vitesse() + 50);
	} else {
		set_vitesse(get_vitesseMax());
	}
}