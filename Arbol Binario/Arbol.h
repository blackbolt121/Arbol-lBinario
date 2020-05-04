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
	stack<T>* recorrerPreOrden();
	stack<T>* recorrerInOrden();
	stack<T>* recorrerPostOrden();
	void eliminar();
private:
	Nodo<T>* raiz;
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
inline stack<T>* Arbol<T>::recorrerPreOrden()
{
	stack<T>* pila = new stack<T>();
	
	return NULL;
}

template<class T>
inline stack<T>* Arbol<T>::recorrerInOrden()
{
	return NULL;
}

template<class T>
inline stack<T>* Arbol<T>::recorrerPostOrden()
{
	return NULL;
}

template<class T>
inline void Arbol<T>::eliminar()
{
}
