/********
* Fichier: monInterface.cpp
* Auteurs: C.-A. Brunet
* Date: 21 décembre 2021 (création)
* Description: Voir fichier d'entête pour informations.
*
* Copyright 2022 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#include <random>
#include <sstream>
#include <queue>
#include "monInterface.h"
#include "canevas.h"

#include <iostream>

using namespace std;

MonInterface::MonInterface(const char* theName) : GraphicusGUI(theName)
{
	
	//reinitialiserCanevas();
	clearInformations();
	updateUI();
}

void MonInterface::reinitialiserCanevas()
{
	canevas.reinitialiser();
	clearInformations();
	updateUI();
}

bool MonInterface::ouvrirFichier(const char* fichier)
{
	

	ifstream myFile;
	myFile.open(fichier, ios_base::in);

	if (myFile.is_open())
	{
		queue<int> etatcouche; // sauvegard l'état de chaques couches
		int coucheActiveID = 0; // sauvegard l'index de la couche active

		while(myFile.good()){ // ---------- reading file: START ---------
			
			string fBuffer; // file reading buffer
			myFile >> fBuffer; // read first char of the line

			switch (fBuffer[0])
			{
			case 'L':
				canevas.coucheAjouter();
				myFile >> fBuffer;
				switch (fBuffer[0]) {
				case 'a':
					etatcouche.push(ACTIVE);
					coucheActiveID = etatcouche.size();
					break;
				case 'x':
					etatcouche.push(INACTIVE);
					break;
				case 'c':
					etatcouche.push(CACHE);
					break;
				case 'i':
					etatcouche.push(INITIALISER);
					break;
				default:
					cout << "ERROR: file is not formated properly\n(erreur possible dans l'etat d'une des couches)\n";
					return false;
				}
				break;
			case 'R':
				int shapeInfo[4];
				for (int i = 0; i < 4; i++) {
					myFile >> shapeInfo[i];
				}
				canevas.ajouterForme(new Rectangle(shapeInfo[0], shapeInfo[1], shapeInfo[2], shapeInfo[3]));
				break;
			case 'K':
				for (int i = 0; i < 3; i++) {
					myFile >> shapeInfo[i];
				}
				canevas.ajouterForme(new Carre(shapeInfo[0], shapeInfo[1], shapeInfo[2]));
				break;
			case 'C':
				for (int i = 0; i < 3; i++) {
					myFile >> shapeInfo[i];
				}
				canevas.ajouterForme(new Cercle(shapeInfo[0], shapeInfo[1], shapeInfo[2]));
				break;
			case ' ':
			case '\n':
			case '\0':
				cout << "WARNING: empty line in file\n";
				break;
			default:
				cout << "ERROR: file is not formated properly\n(erreur possible dans le type de forme ou la ligne n'est pas une couche)";
				return false;
			}

		} // ---------- reading file: END ---------

		std::cout << "Finished reading file, will close now" << endl;
		myFile.close();

		couchePremiere();
		coucheRetirer(); // enlève la première couche qui est là par défault

		for (int i = 0; i < (coucheActiveID - 1); i++) { // move to the active layer
			coucheSuivante();
		}
		
		int tempNbCouches = etatcouche.size();
		for (int i = 0; i < tempNbCouches; i++) // set layers to their proper state
		{
			canevas.couches[i].ChangerEtat((const int)etatcouche.front());
			etatcouche.pop();
		}
		
	}
	else {
		std::cout << "open() failed: check if file is in right folder" << endl;
	}

	updateUI();
	return true;
}

bool MonInterface::sauvegarderFichier(const char* c_fileName) {
	ofstream outFile;
	outFile.open(c_fileName);
	if (outFile.is_open()) {
		outFile << canevas;
		outFile.close();
		return true;
	}
	else return false;
	
}

void MonInterface::coucheTranslater(int deltaX, int deltaY) {
	canevas.translater(deltaX, deltaY);
	updateUI();
}

void MonInterface::ajouterCercle(int x, int y, int rayon) {
	canevas.ajouterForme(new Cercle(x, y, rayon));
	updateUI();
}
void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur) {
	canevas.ajouterForme(new Rectangle(x, y, longueur, largeur));
	updateUI();
}
void MonInterface::ajouterCarre(int x, int y, int cote) {
	canevas.ajouterForme(new Carre(x, y, cote));
	updateUI();
}

void MonInterface::coucheAjouter() {
	canevas.coucheAjouter();
	updateUI();
}
void MonInterface::coucheRetirer() {
	canevas.coucheRetirer();
	updateUI();
}
void MonInterface::coucheCacher() {
	canevas.coucheCacher();
	updateUI();
}

void MonInterface::retirerForme() {
	delete canevas.retirerForme();
	updateUI();
}

void MonInterface::couchePremiere() {
	canevas.changerCouche(PREMIERE);
	updateUI();
}
void MonInterface::couchePrecedente() {
	canevas.changerCouche(PRECEDANTE);
	updateUI();
}
void MonInterface::coucheSuivante() {
	canevas.changerCouche(SUIVANTE);
	updateUI();
}
void MonInterface::coucheDerniere() {
	canevas.changerCouche(DERNIERE);
	updateUI();
}

void MonInterface::formePremiere() {
	canevas.changerFormeActive(PREMIERE);
	updateUI();
}
void MonInterface::formePrecedente() {
	canevas.changerFormeActive(PRECEDANTE);
	updateUI();
}
void MonInterface::formeSuivante() {
	canevas.changerFormeActive(SUIVANTE);
	updateUI();
}
void MonInterface::formeDerniere() {
	canevas.changerFormeActive(DERNIERE);
	updateUI();
}

void MonInterface::modePileChange(bool mode) {
	canevas.inversePile(mode);
	updateUI();
}

void MonInterface::updateUI() {
	
	// send shapes to UI
	stringstream ss;
	ss << canevas; // convert canvas to text
	dessiner(ss.str().c_str()); // send text to UI

	// send shapes to the info bar
	clearInformations();
	canevas.updateInfo(info); // update the info struct
	setInformations(info); /// send the info struct to the UI

	
	//cout << canevas << endl; // for debugging
}