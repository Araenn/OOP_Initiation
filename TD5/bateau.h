#ifndef __BATEAU
#define __BATEAU

#include "vehicule.h"

class Bateau : public Vehicule {

protected :
	int tirant;

public : 
	Bateau();
	Bateau(int);
	Bateau(int, int);
	Bateau(int, int, double);
	Bateau(int, int, double, int);
	Bateau(const Bateau& b);
	virtual ~Bateau();
	int get_tirant();
	void set_tirant(int);
	bool tester_surete_profondeur(int);
	void accelerer();
};

#endif