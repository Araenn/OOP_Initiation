#ifndef __VOITURE
#define __VOITURE

#include "vehicule.h"

class Voiture : public Vehicule {

public:
    Voiture();
    Voiture(int);
    Voiture(int, int);
    Voiture(int, int, double);
    Voiture(const Voiture& v);
    virtual ~Voiture();
    void accelerer();
};

#endif