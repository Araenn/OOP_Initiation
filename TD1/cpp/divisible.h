#include <iostream>
#include <vector>

typedef struct Divisible {
	int val;
	int plus_petit_diviseur;
	int plus_grand_diviseur;
}Divisible;

void afficher(struct Divisible t);
Divisible creer(int a, int b);
Divisible multiplier(struct Divisible a, struct Divisible b);
int min(int a, int b);
int max(int a, int b);
struct Divisible multiplier(int a, struct Divisible b);
struct Divisible multiplier(struct Divisible b, int a);
void initialiser(struct Divisible &a);