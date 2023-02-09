/********
 * Fichier: couche.cpp
#  Auteurs: Roxanne Cote et Philippe Durette
#  Date: 10 janvier 2023 (creation)
 * Description:Implementation des methodes des classes decrites dans Couche.h.
 * Ce fichier fait partie de la distribution de Graphicus.
 *
********/

#include "couche.h"

Couche::Couche()
{
    Etat = INITIALISER;

}
Couche::~Couche()
{
    
}
bool Couche::Ajout(Forme *newForme)
{
    return vecteur.add(newForme);
}

Forme* Couche::RetraitForme()
{
    return vecteur.removeItem(vecteur.getActiveIndex());
}
Forme* Couche::ObtenirForme(int i)
{
    return vecteur[i];
}
double Couche::AireTotaleCouche()
{
    int aireTot = 0;
    for (int i =0; i< vecteur.getSize(); i++)
    {
       aireTot += vecteur[i]->aire();    
    }
    return aireTot; 
}
bool Couche::Translater(int h, int v)
{
    for (int i=0; i< vecteur.getSize(); i++)
    {
        vecteur.getItem(i)->translater(h, v);
    }
    return true;
}
bool Couche::ReinitialiserCouche()
{

    for (int i = 0; i < vecteur.getSize(); i++) {
        delete vecteur[i];
    }
    vecteur.clear();
    return true;
}
bool Couche::ChangerEtat(int etat)
{   
    if(etat <= 4  && etat > 1)
    {
        Etat = etat;
        return true;
    }
    else 
    {
        return false;
    }
    
}
int Couche::getEtat() {
    return Etat;
}

void Couche::changerFormeActive(int deplacement) {
    switch (deplacement) {
    case PREMIERE:
        vecteur.setActiveIndex(0);
        break;
    case PRECEDANTE:
        if (vecteur.getActiveIndex() > 0) {
            vecteur--;
        }
        break;
    case SUIVANTE:
        if (vecteur.getActiveIndex() < (vecteur.getSize() - 1)) {
            vecteur++;
        }
        break;
    case DERNIERE:
        vecteur.setActiveIndex(vecteur.getSize());
        break;
    default:
        break;
    }

}
void Couche::AfficherCouche(ostream& s)
{
    if ((Etat == 1) || vecteur.isEmpty())
    {
        cout << "Couche initialisee" << endl;
    }
    else
        s << vecteur;
}

void Couche::updateInfo(Informations& info, bool activeLayer) {
    info.nbFormesCouche += vecteur.getSize();
    if (activeLayer) {
        switch (Etat) {
        case INITIALISER:
            info.etatCouche[0] = 'i';
            break;
        case ACTIVE:
            info.etatCouche[0] = 'a';
            break;
        case INACTIVE:
            info.etatCouche[0] = 'x';
            break;
        case CACHE:
            info.etatCouche[0] = 'c';
            break;
        }
        info.aireCouche = AireTotaleCouche();
        if (vecteur.getSize() == 0) info.formeActive = -1;
        else {
            info.formeActive = vecteur.getActiveIndex();
            info.coordX = vecteur[vecteur.getActiveIndex()]->getAncrage().x;
            info.coordY = vecteur[vecteur.getActiveIndex()]->getAncrage().y;
            info.aireForme = vecteur[vecteur.getActiveIndex()]->aire();
        }
    }
}









