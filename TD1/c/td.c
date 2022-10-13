#include <stdio.h>
#include <math.h>
#include "divisible.h"

int main() {
	struct Divisible a, b, c, d, e;
	a = creer(7, 13);
	afficher(a);
	b = creer(3, 5);
	afficher(b);
	
	c = multiplier(a, b);
	afficher(c);

	printf("Avec la deuxieme multiplication : \n");
	d = multiplier(5, a);
	afficher(d);
	
	printf("derniere fonction multiplier : \n");
	e = multiplier(a, 5);
	afficher(e);
	return 0;
}