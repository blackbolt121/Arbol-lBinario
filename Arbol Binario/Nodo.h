#pragma once
#include <iostream>
#include <algorithm>
template <class T>
class Nodo {
private:
	T* dato;
	Nodo<T>* izq;
	Nodo<T>* der;
public:
	Nodo<T>(const T& i);
	Nodo<T>();
	~Nodo<T>();
	T* buscar(const T& i);
	void insertIzq(Nodo<T>* izq);
	void insertDer(Nodo<T>* der);
	void insert(const T& dato);
	Nodo<T>*& getIzq();
	Nodo<T>*& getDer();
	T* getDato();
};

template<class T>
inline Nodo<T>::Nodo(const T& i)
{
	this->dato = new T;
	*this->dato = i;
	this->izq = nullptr;
	this->der = nullptr;
}

template<class T>
inline Nodo<T>::Nodo()
{
	this->dato = nullptr;
	this->izq = nullptr;
	this->der = nullptr;
}

template<class T>
inline Nodo<T>::~Nodo()
{
}

template<class T>
inline void Nodo<T>::insertIzq(Nodo<T>* izq)
{
	this->izq = izq;
}

template<class T>
inline void Nodo<T>::insertDer(Nodo<T>* der)
{
	this->der = der;
}
template <class T>
inline T* Nodo<T>::buscar(const T& i) {

	if (*this->dato == i) {
		return this->dato;
	}
	else{

		if (this->izq != nullptr or this->der != nullptr) {

			if (this->der != nullptr and *this->dato < i) {
				return this->der->buscar(i);
			}
			else {
				if (this->izq != nullptr and *this->dato > i) {
					return this->izq->buscar(i);
				}
			}
		}
	}
	return nullptr;
}
template<class T>
inline void Nodo<T>::insert(const T& dato)
{
	if (this->dato != nullptr) {
		if (*this->dato == dato) {

		}
		else if (*this->dato > dato) {
			if (this->izq == nullptr) {
				this->izq = new Nodo<T>(dato);
			}
			else {
				this->izq->insert(dato);
			}
		}
		else {
			if (this->der == nullptr) {
				this->der = new Nodo<T>(dato);
			}
			else {
				this->der->insert(dato);
			}
		}
	}
	else {
		this->dato = new T;
		*this->dato = dato;
	}
	
}

template<class T>
inline Nodo<T>*& Nodo<T>::getIzq()
{
	return this->izq;
}

template<class T>
inline Nodo<T>*& Nodo<T>::getDer()
{
	return this->der;
}

template<class T>
inline T* Nodo<T>::getDato()
{
	return this->dato;
}


