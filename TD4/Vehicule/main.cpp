#include "vehicule.h"

int main(int argc, char *argv[]) {
	Vehicule harley(60);
	std::cout << harley << std::endl;
	Vehicule suzuki(100, 240);
	std::cout << suzuki << std::endl;
	Vehicule ducati(120, 240, 0.5);
	std::cout << ducati << std::endl;
	Vehicule honda = 100; //constructeur parametre
	std::cout << honda << std::endl;
	Vehicule yamaha = 70;
	std::cout << yamaha << std::endl;
	std::cout << "Ec = " << energie_cinetique(yamaha) << std::endl;
	return 0;
}
