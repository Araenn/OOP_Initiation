#include "vehicule.h"
#include "voiture.h"
#include "bateau.h"
#include <vector>

int main() {
	vector<Vehicule*> flotte;
	flotte = {new Bateau, new Voiture, new Bateau};

	for (int i = 0; i < 3; i++) {
		cout << flotte[i]->get_vitesse() << endl;
		flotte[i]->accelerer();
		cout << flotte[i]->get_vitesse() << endl;
	}
	return 0;
}