main_vehicule: main_vehicule.cpp vehicule.o bateau.o voiture.o
	g++ -Wall -o main_vehicule main_vehicule.cpp vehicule.o bateau.o voiture.o

vehicule.o: vehicule.cpp vehicule.h
	g++ -Wall -c vehicule.cpp

bateau.o: bateau.cpp bateau.h
	g++ -Wall -c bateau.cpp

voiture.o: voiture.cpp voiture.h
	g++ -Wall -c voiture.cpp