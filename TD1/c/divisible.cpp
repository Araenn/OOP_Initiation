#include "divisible.h"

int min(int a, int b) {
	int m;
	if (a < b) {
		m = a;
	} else {
		m = b;
	}	
	return m;
}

int max(int a, int b) {
	int m;	
	if (a > b) {
		m = a;
	} else {
		m = b;
	}	
	return m;
}

void afficher(struct Divisible t) {
	printf("val = %d, ppd = %d, pgd = %d\n", t.val, t.plus_petit_diviseur, t.plus_grand_diviseur);
}

struct Divisible creer(int a, int b) {	
	struct Divisible t;
	t.val = a*b;
	if (a < b) {
		t.plus_petit_diviseur = a;
		t.plus_grand_diviseur = b;	
	} else {
		t.plus_petit_diviseur = b;
		t.plus_grand_diviseur = a;
	}
	return t;
}

struct Divisible multiplier(struct Divisible a, struct Divisible b) {
	struct Divisible c;
	c.val = a.val*b.val;
	c.plus_petit_diviseur = min(a.plus_petit_diviseur, b.plus_petit_diviseur);
	c.plus_grand_diviseur = max(a.plus_grand_diviseur, b.plus_grand_diviseur);
	return c;
}

struct Divisible multiplier(int a, struct Divisible b) {
	struct Divisible c;
	c.val = a*b.val;
	c.plus_petit_diviseur = min(a, b.plus_petit_diviseur);
	c.plus_grand_diviseur = max(a, b.plus_grand_diviseur);
	return c;
}

struct Divisible multiplier(struct Divisible b, int a) {
	struct Divisible c;
	c.val = a*b.val;
	c.plus_petit_diviseur = min(a, b.plus_petit_diviseur);
	c.plus_grand_diviseur = max(a, b.plus_grand_diviseur);
	return c;
}
