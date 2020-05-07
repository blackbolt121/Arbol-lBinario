#pragma once
#include <iostream>
#include <algorithm>
template <class T>
class Nodo {
private:
	T* dato;
	Nodo<T>* izq;
	Nodo<T>* der;
	Nodo<T>* padre;
public:
	Nodo<T>(const T& i, Nodo<T>* padre = nullptr);
	Nodo<T>(Nodo<T>* padre = nullptr);
	~Nodo<T>();
	T* buscar(const T& i);
	void insertIzq(Nodo<T>* izq, Nodo<T>* padre = nullptr);
	void insertDer(Nodo<T>* der, Nodo<T>* padre = nullptr);
	void insert(const T& dato, Nodo<T>* padre = nullptr);
	void setPadre(Nodo<T>* padre = nullptr);
	Nodo<T>* getPadre();
	Nodo<T>*& getIzq();
	Nodo<T>*& getDer();
	Nodo<T>* minimo(Nodo<T>* n);
	T* getDato();
};

template<class T>
inline Nodo<T>::Nodo(const T& i, Nodo<T>* padre)
{
	this->dato = new T;
	*this->dato = i;
	this->padre = padre;
	this->izq = nullptr;
	this->der = nullptr;
}

template<class T>
inline Nodo<T>::Nodo(Nodo<T>* padre)
{
	this->dato = nullptr;
	this->izq = nullptr;
	this->der = nullptr;
	this->padre = padre;
}

template<class T>
inline Nodo<T>::~Nodo()
{
}

template<class T>
inline void Nodo<T>::insertIzq(Nodo<T>* izq, Nodo<T>* padre)
{
	this->izq = izq;
	if (padre != nullptr) {
		this->izq->setPadre(padre);
	}
}

template<class T>
inline void Nodo<T>::insertDer(Nodo<T>* der, Nodo<T>* padre)
{
	this->der = der;
	if (padre != nullptr) {
		this->der->setPadre(padre);
	}
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
inline void Nodo<T>::insert(const T& dato, Nodo<T>* padre)
{
	if (this->dato != nullptr) {
		if (*this->dato == dato) {

		}
		else if (*this->dato > dato) {
			if (this->izq == nullptr) {
				this->izq = new Nodo<T>(dato, this);
			}
			else {
				this->izq->insert(dato, this);
			}
		}
		else {
			if (this->der == nullptr) {
				this->der = new Nodo<T>(dato, this);
			}
			else {
				this->der->insert(dato, this);
			}
		}
	}
	else {
		this->dato = new T;
		*this->dato = dato;
	}
}

template<class T>
inline void Nodo<T>::setPadre(Nodo<T>* padre)
{
	this->padre = padre;
}

template<class T>
inline Nodo<T>* Nodo<T>::getPadre()
{
	return this->padre;
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
inline Nodo<T>* Nodo<T>::minimo(Nodo<T>* n)
{
	Nodo<T> *retorno = n;
	if (n == nullptr) {
		retorno = nullptr;
	}
	else
	{
		if (retorno->getDer() == nullptr and retorno->getIzq() == nullptr) {
			return retorno;
		}
		else if (retorno->getIzq() != nullptr) {
			retorno = retorno->getIzq();
			retorno = this->minimo(retorno);
		}
		else {
			if (retorno->getDer() != nullptr) {
				retorno = retorno->getDer();
				retorno = this->minimo(retorno);
			}
		}
	}
	return retorno;
	// TODO: Insertar una instrucción "return" aquí
}

template<class T>
inline T* Nodo<T>::getDato()
{
	return this->dato;
}


