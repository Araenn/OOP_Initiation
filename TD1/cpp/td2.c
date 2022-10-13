#include <iostream>
#include <vector>
using namespace std;
#include "divisible.h"

int main() {
	struct Divisible a, b, c, d, e, f;
	int n1, n2;
	cout << "Choisir deux entier premiers pour le divisible a : " << endl;
	cin >> n1 >> n2;
	a = creer(n1, n2);
	afficher(a);
	b = creer(3, 5);
	afficher(b);
	
	c = multiplier(a, b);
	afficher(c);

	cout << "Avec la deuxieme multiplication : " << endl;
	d = multiplier(5, a);
	afficher(d);
	
	cout << "derniere fonction multiplier : " << endl;
	e = multiplier(a, 5);
	afficher(e);

	vector<int> Premiers = {2, 3, 5, 7, 11};
	vector<struct Divisible> Tab = {creer(2, 3), creer(2, 5), creer(2, 7), creer(2, 11), creer(3, 5), creer(3, 7), creer(3, 11), creer(5, 7), creer(5, 11), creer(7, 11)};

	for (int i = 0; i < Tab.size(); i++) {
		cout << Tab[i].val << endl;
	}

	initialiser(f);
	afficher(f);
	return 0;
}