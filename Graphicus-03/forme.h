/********
 * Fichier: forme.h
 * Auteurs: Philippe Durette, Youlian Houehounou
 *		base sur forme.h par: Philippe Durette, Roxanne Cote
 * Date: 10 janvier 2023 (creation)
 * Description: Declaration des classes de formes geometriques. 
********/

#ifndef FORME_H
#define FORME_H

#include <iostream>
#include "coordonnee.h"

using namespace std;

class Forme
{
public:
    Forme(int x = 0, int y = 0);
    virtual ~Forme();
    void translater(int deltaX, int deltaY);
    Coordonnee getAncrage();
    void setAncrage(Coordonnee c);
    virtual double aire() = 0;
    virtual void afficher(ostream & s) = 0;

    friend ostream& operator << (ostream& stream, Forme& forme) {
        forme.afficher(stream);
        return stream;
    }
    friend ostream& operator << (ostream& stream, Forme* forme) {
        forme->afficher(stream);
        return stream;
    }

protected:
	Coordonnee ancrage;
};


#endif
