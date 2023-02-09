/********
 * Fichier: tests.cpp
 * Auteurs: Roxanne Cote et Philippe Durette
 * Date: 10 janvier 2023 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
 ********/

#include "tests.h"

void Tests::tests_unitaires_formes()
{
    cout << " --------------------------" << endl
         << endl;

    cout << "Teste creer forme divers" << endl
         << endl;
    Forme *ptrfrm = new Cercle();
    cout << "Tests----Forme Cercle initiale" << endl;
    ptrfrm->afficher(cout);
    cout << endl;

    Forme *ptrCarre = new Carre(4, 5);
    cout << "Tests----Forme carre 4X5 " << endl;
    ptrCarre->afficher(cout);
    cout << endl;

    Forme *ptrRectangle = new Rectangle(3, 3, 2, 2);
    cout << "Tests----Forme Rectangle 2, 2, 3, 3" << endl;
    ptrRectangle->afficher(cout);
    cout << endl;
}

void Tests::tests_unitaires_vecteur()
{
    /*
    cout << "--------------------------" << endl
         << endl;
    Vecteur<Forme*> V;

    V.add(new Cercle(1, 1, 1));
    V.add(new Rectangle(3, 3, 3, 3));
    V.add(new Carre(2, 2));
    V.add(new Rectangle());
    V.add(new Carre());

    cout << "Tests----Vecteur AVANT remove item 3" << endl
         << endl;
    V.afficher(cout);

    cout << "Tests---- Vecteur APRES Remove Item 3 " << endl
         << endl;
    V.removeItem(3);
    V.afficher(cout);
    cout << endl;

    cout << "Série de 4 Tests----(Get et Remove) Item IMPOSSIBLE " << endl
         << endl;

    cout << "Tests----Remove Item 25 donc impossible " << endl;
    if (V.removeItem(25) == NULL)
    {
        cout << "removeItem impossible : erreur index" << endl;
    }

    cout << "Tests----Remove Item -3 donc impossible " << endl;
    if (V.removeItem(-3) == NULL)
    {
        cout << "removeItem impossible : erreur index" << endl;
    }

    cout << "Tests----get Item 50 donc impossible " << endl;
    if (V.getItem(50) == NULL)
    {
        cout << "removeItem impossible : erreur index" << endl;
    }

    cout << "Tests----get Item -2 donc impossible " << endl;
    if (V.getItem(-2) == NULL)
    {
        cout << "removeItem impossible : erreur index" << endl;
    }

    cout << endl
         << endl;
    */
    string a = "Allo";
    string b = "salu";
    string c = "cava";
    string d = "yeah";
    string e = "bye";
    Vecteur <string> V(5);
    V.add(a);
    V.add(b);
    V.add(c);
    V.add(d);
    V.add(e);

    Vecteur <Couche> couches(5);

    V.afficher(cout);

}

void Tests::tests_unitaires_couche()
{
    cout << " --------------------------" << endl
         << endl;
    Couche C;

    C.Ajout(new Cercle());
    C.Ajout(new Carre());
    C.Ajout(new Rectangle());


    C.AireTotaleCouche();
    cout << "Aire totale arrondit de la couche qui contient 3 forme initialiser est:" << C.AireTotaleCouche() << endl;
    cout << endl
         << endl;

    cout << "Test Retirer Forme -1:" << endl;
    if (C.RetraitForme(-1) == NULL)
    {
        cout << "Retirer Forme impossible car index inexistant" << endl
             << endl;
    }

    cout << "Test Obtenir Forme -2:" << endl;
    if (C.ObtenirForme(-2) == NULL)
    {
        cout << "Obtenir Forme impossible car index inexistant" << endl
             << endl;
    }
}

void Tests::tests_unitaires_canevas()
{
    cout << " --------------" << endl
         << endl;
    Canevas C;
    C.ajouterForme(new Cercle());
    C.ajouterForme(new Carre());
    C.ajouterForme(new Rectangle());

    cout << "Demonstration que la Couche est Initialiser:" << endl
         << endl;
    C.afficher(cout);
    cout << endl;

    C.activerCouche(4);
    C.ajouterForme(new Cercle());
    C.ajouterForme(new Carre());
    C.ajouterForme(new Rectangle());

    cout << "Test Translater de -1,0 preuve-----AVANT" << endl
         << endl;
    C.afficher(cout);
    cout << endl
         << endl;

    C.translater(-1, 0);
    cout << "Test Translater de -1,0 preuve-----APRES" << endl
         << endl;
    C.afficher(cout);
    cout << endl
         << endl;

    cout << "Test Activer couche 6 donc devrait etre impossible:" << endl;
    if (C.activerCouche(6) == false)
    {
        cout << "Activation impossible du numéro de couche inexistant" << endl
             << endl;
    }

    cout << "Cacher couche -1 donc devrait etre impossible:" << endl;
    if (C.cacherCouche(-1) == false)
    {
        cout << "CacherCouche impossible du numéro de couche inexistant" << endl
             << endl;
    }

    cout << "Aire totale arrondie du canevas:" << C.aire() << endl;
    cout << endl;
}

void Tests::tests_unitaires()
{
    tests_unitaires_formes();
    //tests_unitaires_vecteur();
    tests_unitaires_couche();
    tests_unitaires_canevas();
}

void Tests::tests_application()
{
    // Fait tous les tests applicatifs
    tests_application_cas_01();
    tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
    cout << "TESTS APPLICATION (CAS 01)" << endl;
    Canevas canevasTest = Canevas();

    cout << "----------------------------------------\n"
         << "Etape 1 a 6\n"
         << "----------------------------------------\n"; // Étape 1 à 6
    cout << "Test 1: activer couche 1\n";
    canevasTest.activerCouche(1);

    cout << "Test 2: ajouter les formes rectangle(0, 0, 2, 3), carre(2, 3, 4), cercle(7, 8, 6)\n";
    canevasTest.ajouterForme(new Rectangle(2, 3, 0, 0));
    canevasTest.ajouterForme(new Carre(2, 3, 4));
    canevasTest.ajouterForme(new Cercle(6, 7, 8));
    cout << endl;

    cout << "Test 3: Activer couche 2\n";
    canevasTest.activerCouche(2);

    cout << "Test 4: ajouter rectangle(0, 0, 4, 5)\n";
    canevasTest.ajouterForme(new Rectangle(4, 5, 0, 0));

    cout << "Test 5: afficher le canvas\n";
    canevasTest.afficher(cout);

    cout << "Test 6: afficher l'aire totale\n";
    cout << canevasTest.aire() << endl;

    cout << "----------------------------------------\n"
         << "Etape 7 à 13\n"
         << "----------------------------------------\n"; // Étape 7 à 13
    canevasTest.reinitialiser();

    cout << "Test 7: ajouter les formes rectangle, carre et cercle a la couche 0\n";
    canevasTest.activerCouche(0);
    canevasTest.ajouterForme(new Rectangle());
    canevasTest.ajouterForme(new Carre());
    canevasTest.ajouterForme(new Cercle());

    cout << "Test 8: translater de (5;5)\n";
    canevasTest.activerCouche(1);
    canevasTest.ajouterForme(new Rectangle(2, 3, 0, 0));
    canevasTest.ajouterForme(new Carre(2, 3, 4));
    canevasTest.ajouterForme(new Cercle(6, 7, 8));
    canevasTest.translater(5, 5);

    cout << "Test 9, 10, 11: initialise couche 2, 3 et 4\n";

    cout << "Test 12: afficher le canvas\n";
    canevasTest.afficher(cout);

    cout << "Test 13: afficher l'aire totale\n";
    cout << canevasTest.aire() << endl;

    cout << "----------------------------------------\n"
         << "Etape 14 à 16\n"
         << "----------------------------------------\n";
    ; // Étape 14 à 16
    cout << "Test 14: retirer 1ere forme de la couche 1\n";
    canevasTest.activerCouche(1);
    canevasTest.retirerForme(0);

    cout << "Test 15: afficher le canvas\n";
    canevasTest.afficher(cout);
    cout << endl << endl;

    cout << "Test 16: afficher l'aire totale\n";
    cout << canevasTest.aire() << endl <<endl;


    cout << "----------------------------------------\n"
         << "Etape 17 à 19\n"
         << "----------------------------------------\n"; // Étape 17 à 19

    cout << "Test 17: reinitialiser le canvas\n";
    canevasTest.reinitialiser();
    canevasTest.activerCouche(0);

    cout << "Test 18: afficher le canvas\n";
    canevasTest.afficher(cout);
    cout << endl << endl;

    cout << "Test 19: afficher l'aire totale\n";
    cout << canevasTest.aire() << endl;
}

void Tests::tests_application_cas_02()
{
    cout << "TESTS APPLICATION (CAS 02)" << endl;
}
