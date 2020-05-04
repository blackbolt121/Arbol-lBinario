#pragma once
#include <iostream>
#include "Nodo.h"
template <class T>
class Arbol
{
public:
	Arbol();

private:
	Nodo<T>* raiz;
};
template <class T>
Arbol<T>::Arbol() {
	this->raiz = new Nodo<T>();
}

