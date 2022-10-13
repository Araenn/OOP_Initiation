#include "divisible.h"

int min(int a, int b) {
	return a < b ? a : b;
}

void updatePosition(int &min, int &max) {
	if (min > max) {
		int cached = min;
		min = max;
		max = cached;
	} 
}

int max(int a, int b) {	
	if (a > b) {
		return a;
	} else {
		return b;
	}	
}

void afficher(struct Divisible t) {
	std::cout << "val = " << t.val << ", ppd = " << t.plus_petit_diviseur << ", pgd = " << t.plus_grand_diviseur << std::endl;
}

struct Divisible init(int val, int ppd, int pgd) {
	/**
	 * @brief 
	 * @arg ppd et pgd doivent être correctes
	 * 
	 */
	struct Divisible t;
	t.val = val;
	t.plus_petit_diviseur = ppd;
	t.plus_grand_diviseur = pgd;
	return t;
}

struct Divisible creer(int a, int b) {	
	updatePosition(a, b);
	return init(a * b, a, b);
}

struct Divisible multiplier(struct Divisible a, struct Divisible b) {
	return init(a.val * b.val, min(a.plus_petit_diviseur, b.plus_petit_diviseur), max(a.plus_grand_diviseur, b.plus_grand_diviseur));
}

struct Divisible multiplier(int a, struct Divisible b) {
	return init(a * b.val, min(a, b.plus_petit_diviseur), max(a, b.plus_grand_diviseur));
}

struct Divisible multiplier(struct Divisible b, int a) {
	return multiplier(a, b);
}

void initialiser(struct Divisible &a) {
	a.val = 6;
	a.plus_grand_diviseur = 3;
	a.plus_petit_diviseur = 2;
}
