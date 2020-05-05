#pragma once
#include <iostream>
#include "Nodo.h"
#include "stack.h"
template <class T>
class Arbol
{
public:
	Arbol();
	void insertar(const T &dato);
	T* buscar(const T& dato);
	stack<T> recorrerPreOrden();
	stack<T> recorrerInOrden();
	stack<T> recorrerPostOrden();
	void eliminar();
private:
	Nodo<T>* raiz;
	static stack<T> InOrden(Nodo<T> *nodo);
};

template<class T>
inline Arbol<T>::Arbol()
{
	this->raiz = nullptr;
}

template<class T>
inline void Arbol<T>::insertar(const T& dato)
{
	if (this->raiz == nullptr)
		this->raiz = new Nodo<T>();
	this->raiz->insert(dato);
}

template<class T>
inline T* Arbol<T>::buscar(const T& dato)
{
	if (this->raiz != nullptr) {
		return this->raiz->buscar(dato);
	}
	else
		return NULL;
}

template<class T>
inline stack<T> Arbol<T>::recorrerPreOrden()
{
	stack<T> pila;
	return pila;
}

template<class T>
inline stack<T> Arbol<T>::recorrerInOrden()
{
	stack<T> retorno;
	if (this->raiz != nullptr) 
	{
		retorno = Arbol<T>::InOrden(this->raiz);
	}
	else {
		return retorno;
	}
	return retorno;
	
}

template<class T>
inline stack<T> Arbol<T>::recorrerPostOrden()
{
	return stack<T>();
}

template<class T>
inline void Arbol<T>::eliminar()
{

}

template<class T>
inline stack<T> Arbol<T>::InOrden(Nodo<T>* nodo)
{
	stack<T> devolver;
	if (nodo != nullptr) {
		devolver = Arbol<T>::InOrden(nodo->getIzq()) + devolver;
		devolver.push(*nodo->getDato());
		devolver = Arbol<T>::InOrden(nodo->getDer())+devolver;
	}
	return devolver;
}


