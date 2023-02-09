/********
 * Fichier: vecteur.h
 * Auteurs: Philippe Durette, Youlian Houehounou
 *		base sur vecteur.h par: Philippe Durette, Roxanne Cote
 * Date: 10 janvier 2023 (creation)
 * Description: eclaration de la classe Vecteur. La classe gere un
 *    tableau de figure en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef VECTEUR_H
#define VECTEUR_H

using namespace std;
#include "forme.h"
#include "coordonnee.h"

template <typename T>
class Vecteur
{
public:
	Vecteur()
	{
		maxSize = 1;
		nbObject = 0;
		arr = new T[maxSize]();
		activeIndex = nbObject;
	}
	Vecteur(const int size)
	{
		maxSize = 1;
		while (maxSize < size) maxSize *= 2; // make sure maxSize is a multiple of 2
		nbObject = 0;
		arr = new T[maxSize]();
		activeIndex = nbObject;
	}

	~Vecteur()
	{

	}

	friend ostream& operator << (ostream& stream, Vecteur& v) {
		for (int i = 0; i < v.nbObject; i++) {
			stream << v[i];
		}
		return stream;
	}

	friend istream& operator >> (istream& stream, Vecteur& v) {
		stream >> v[v.activeIndex];
		return stream;
	}

	void operator+=(T addedItem)
	{
		add(addedItem);
	}

	T& operator[] (int index) 
	{
		return arr[index];
	}

	void operator++(int addedItem)
	{
		activeIndex++;
	}

	void operator--(int addedItem)
	{
		activeIndex--;
	}
	
	int getCapacity(T addedItem) 
	{
		return maxSize;
	}
	int getSize() 
	{
		return nbObject;
	}
	int getActiveIndex() {
		return activeIndex;
	}
	void setActiveIndex(int newIndex) {
		activeIndex = newIndex;
	}
	bool add(T addedItem) 
	{
		if (nbObject == maxSize) { // vector is full
			resizeUp();
		}
		arr[nbObject] = addedItem;
		nbObject++;
		activeIndex = nbObject - 1;
		return true;
	}
	void clear()
	{
		nbObject = 0;
		activeIndex = 0;
		resizeDown();
	}
	bool isEmpty() 
	{
		return (nbObject == 0);
	}
	T removeItem(int index) 
	{
		T removedItem = arr[index];
		if (nbObject > 0) nbObject--;
		if (index < nbObject) { //if the cell is not the last
			collapseCell(index);
		}
		
		if (index > 0) activeIndex = index - 1;
		return removedItem;
	}
	T getItem(int index) 
	{
		return arr[index];
	}
private:

	void resizeUp() 
	{
		maxSize = maxSize * 2;
		T *newArr = new T[maxSize]();
		for (int i(0); i < nbObject; i++)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
	}
	void resizeDown() 
	{
		if ((maxSize / 2) > nbObject) {
			while ((maxSize / 2) > nbObject && maxSize > 1) {
				maxSize = maxSize / 2;
			}
			T* newArr = new T[maxSize]();
			delete[] arr;
			arr = newArr;
		}
		if (activeIndex > nbObject) activeIndex = nbObject;
	}
	bool collapseCell(int index) 
	{
		for (index; index < nbObject; index++) {
			arr[index] = arr[index + 1];
		}
		return true;
	}
	int maxSize;
	int nbObject;
	int activeIndex;
	T *arr;
};


#endif