#pragma once
#include <iostream>
#include <iomanip>
#include "Nodo.h"
#include "stack.h"
#include <queue>
template <class T>
class Arbol
{
public:
	Arbol();
	void insertar(const T &dato);
	Nodo<T>*& buscar(const T& dato);
	stack<T> recorrerPreOrden();
	stack<T> recorrerInOrden();
	stack<T> recorrerPostOrden();
	static void Eliminar(Nodo<T>* aux, const T& i);
	void imprimirArbol();
private:
	Nodo<T>* raiz;
	static stack<T> InOrden(Nodo<T> *nodo, stack<T>& entrada);
	static stack<T> PreOrden(Nodo<T>* nodo, stack<T>& entrada);
	static stack<T> PostOrden(Nodo<T>* nodo, stack<T>& entrada);
	static Nodo<T>*& Buscar(Nodo<T>*& nodo, const T& dato);
	static void Imprimir(Nodo<T>* a, int n = 0);
	static int tamanyo(Nodo<T>* nodo);
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
inline Nodo<T>*& Arbol<T>::buscar(const T& dato)
{
	return Arbol<T>::Buscar(this->raiz, dato);
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
inline void Arbol<T>::Eliminar(Nodo<T>* aux, const T &i)
{
	Nodo<T> *padre = aux;
	if (padre->getDer() != nullptr) {
		if (*padre->getDer()->getDato() == i) { //Verifica si el nodo derecho del nodo es igual al dato que se quiere eliminar
			if (padre->getDer()->getIzq() == nullptr or padre->getDer()->getIzq() == nullptr) { //Verifica si el nodo que buscamos tiene un solo hijo o ninguno
				if (padre->getDer()->getIzq() == nullptr and padre->getDer()->getIzq() == nullptr) { //Verifica si ambos estan vacios
					//Caso 1. El nodo que contiene el dato que queremos eliminar no tiene hijos, es decir es una hoja
					delete padre->getDer();
					padre->insertDer(nullptr);
				}
				else if (padre->getDer()->getIzq() == nullptr) { //Ve si el nodo de la derecha
					//Caso 2. El nodo que contiene un solo hijo
					Nodo<T>* aux = padre->getDer()->getDer();
					delete padre->getDer();
					padre->insertDer(aux);
				}
				else { //En caso de que el nodo izquierdo no sea nulo entonces el derecho lo es
					//Caso 2. El nodo que contiene un solo hijo
					Nodo<T>* aux = padre->getDer()->getIzq();
					delete padre->getDer(); //Elimina el nodo
					padre->insertDer(aux);
				}
			}
			else { //Caso 3: El arbol tiene dos hijos
				
			}
		}
		else {//De lo contrario pasa el nodo derecho
			Arbol<T>::Eliminar(padre->getDer(), i);
		}
	}
	if (padre->getIzq() != nullptr) {
		if (*padre->getIzq()->getDato() == i) { //Verifica si el nodo izquierdo del nodo es igual al dato que queremos eliminar
			if (padre->getIzq()->getIzq() == nullptr or padre->getIzq()->getDer() == nullptr) { //Verifica si el nodo que buscamos tiene un solo hijo o ninguno
				if (padre->getDer()->getIzq() == nullptr and padre->getDer()->getIzq() == nullptr) { //Verifica si ambos estan vacios
					//Caso 1. El nodo que contiene el dato que queremos eliminar no tiene hijos, es decir es una hoja
					delete padre->getIzq();
					padre->insertIzq(nullptr);
				}
				else if (padre->getIzq()->getIzq() == nullptr) { //Ve si el nodo de la derecha
					//Caso 2. El nodo que contiene un solo hijo
					Nodo<T>* aux = padre->getIzq()->getDer();
					delete padre->getIzq();
					padre->insertIzq(aux);
				}
				else { //En caso de que el nodo izquierdo no sea nulo entonces el derecho lo es
					//Caso 2. El nodo que contiene un solo hijo
					Nodo<T>* aux = padre->getIzq()->getIzq();
					delete padre->getIzq(); //Elimina el nodo
					padre->insertIzq(aux);
				}
			}
			else { //Caso 3: El arbol tiene dos hijos

			}
		}
		else {
			Arbol<T>::Eliminar(padre->getIzq(), i); //De lo contrario pasa el izquierdo
		}
	}
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

template<class T>
inline Nodo<T>*& Arbol<T>::Buscar(Nodo<T>*& nodo, const T& dato)
{
	Nodo<T>* aux;
	if (nodo == nullptr) {

	}
	else {
		if (*nodo->getDato() == dato) {
			aux = nodo;
		}
		else {
			if (*nodo->getDato() < dato) {
				aux = Arbol<T>::Buscar(nodo->getIzq(), dato);
			}
			else {
				aux = Arbol<T>::Buscar(nodo->getDer(), dato);
			}
		}
	}
	return aux;
}
template <class T>
int Arbol<T>::tamanyo(Nodo<T>* nodo) { //Esta función nos ayuda a saber cuantos nodos hay en un arbol, solo que es estatica(metodo de clase) y privada
	return (nodo == NULL) ? 0 : tamanyo(nodo->getIzq()) + tamanyo(nodo->getDer()) + 1;
}
template<class T>
void Arbol<T>::imprimirArbol() { //Función de instancia que implementa el metodo de clase Imprimir
	Arbol<T>::Imprimir(this->raiz, Arbol<T>::tamanyo(this->raiz)+1);
}
template <class T>
void Arbol<T>::Imprimir(Nodo<T>* raiz, int n) { //Función que imprime el arbol
	if (raiz != nullptr) {
		for (int i = 0; i <= n; i++) {
			cout << "-";
		}
		cout << "> " << *raiz->getDato() << endl;
		int x = n;
		Arbol<T>::Imprimir(raiz->getIzq(), x-1);
		Arbol<T>::Imprimir(raiz->getDer(), x-1);
		
	}

}

