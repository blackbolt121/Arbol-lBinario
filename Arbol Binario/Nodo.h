#pragma once
#include <iostream>
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
	void setDato(const T& i);
	void insertIzq(Nodo<T>* izq, Nodo<T>* padre = nullptr);
	void insertDer(Nodo<T>* der, Nodo<T>* padre = nullptr);
	void insert(const T& dato, Nodo<T>* padre = nullptr);
	void setPadre(Nodo<T>* padre = nullptr);
	bool isHoja();
	Nodo<T>* getPadre();
	Nodo<T>*& getIzq();
	Nodo<T>*& getDer();
	Nodo<T>* minimo(Nodo<T>* n, bool val);
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
	if (padre != nullptr and this->izq != nullptr) {
		this->izq->setPadre(padre);
	}
}

template<class T>
inline void Nodo<T>::insertDer(Nodo<T>* der, Nodo<T>* padre)
{
	this->der = der;
	if (padre != nullptr and this->der != nullptr) {
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
inline void Nodo<T>::setDato(const T& i)
{
	if(this->dato != nullptr)
		*this->dato = i;
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
inline bool Nodo<T>::isHoja()
{
	return (this->der == nullptr and this->izq == nullptr)? true : false;
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
inline Nodo<T>* Nodo<T>::minimo(Nodo<T>* n, bool val)
{
	Nodo<T>* retorno=nullptr;
	if (n != nullptr) {
		if (n->isHoja() == true)
			return n;
		{
			if (val == true) {
				retorno = n->getDer();
				if (retorno == nullptr)
					retorno = n->getIzq();
				retorno = this->minimo(retorno, val);
			}
			else {
				retorno = n->getIzq();
				if(retorno == nullptr)
					retorno = n->getDer();
				retorno = this->minimo(retorno, val);
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


