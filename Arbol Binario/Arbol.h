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
	static stack<T> InOrden(Nodo<T> *nodo, stack<T>& entrada);
	static stack<T> PreOrden(Nodo<T>* nodo, stack<T>& entrada);
	static stack<T> PostOrden(Nodo<T>* nodo, stack<T>& entrada);
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
	stack<T> entrada;
	if (this->raiz != nullptr) {
		return Arbol<T>::PreOrden(this->raiz, entrada).reverse();
	}
	return stack<T>();
}

template<class T>
inline stack<T> Arbol<T>::recorrerInOrden()
{
	if (this->raiz != nullptr) 
	{
		stack<T> entrada;
		return Arbol<T>::InOrden(this->raiz, entrada).reverse();
	}
	else {
		return stack<T>();
	}
	
}

template<class T>
inline stack<T> Arbol<T>::recorrerPostOrden()
{
	stack<T> retorno;
	if (this->raiz != nullptr)
		return Arbol<T>::PostOrden(this->raiz, retorno).reverse();
	return retorno;
}

template<class T>
inline void Arbol<T>::eliminar()
{
	
}

template<class T>
inline stack<T> Arbol<T>::InOrden(Nodo<T>* nodo, stack<T> &entrada)
{
	if (nodo != nullptr) {
		Arbol<T>::InOrden(nodo->getIzq(), entrada);
		entrada.push(*nodo->getDato());
		Arbol<T>::InOrden(nodo->getDer(), entrada);
	}
	return entrada;
}

template<class T>
inline stack<T> Arbol<T>::PreOrden(Nodo<T>* nodo, stack<T>& entrada)
{
	if (nodo != nullptr) {
		entrada .push(*nodo->getDato());
		Arbol<T>::PreOrden(nodo->getIzq(), entrada);
		Arbol<T>::PreOrden(nodo->getDer(), entrada);
	}
	return entrada;
}

template<class T>
inline stack<T> Arbol<T>::PostOrden(Nodo<T>* nodo, stack<T>& entrada)
{
	if (nodo != nullptr) {
		Arbol<T>::PostOrden(nodo->getIzq(), entrada);
		Arbol<T>::PostOrden(nodo->getDer(), entrada);
		entrada.push(*nodo->getDato());
	}

	return entrada;
}


