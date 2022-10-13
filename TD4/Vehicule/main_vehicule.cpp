#include "vehicule.h"

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