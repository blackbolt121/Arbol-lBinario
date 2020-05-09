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
	Nodo<T>* buscar(const T& dato);
	stack<T> recorrerPreOrden();
	stack<T> recorrerInOrden();
	stack<T> recorrerPostOrden();
	void eliminar(const T& i);
	
	void imprimirArbol();
private:
	Nodo<T>* raiz;
	static stack<T> InOrden(Nodo<T> *nodo, stack<T>& entrada);
	static stack<T> PreOrden(Nodo<T>* nodo, stack<T>& entrada);
	static stack<T> PostOrden(Nodo<T>* nodo, stack<T>& entrada);
	static Nodo<T>*& Buscar(Nodo<T>*& nodo, const T& dato);
	static void Imprimir(Nodo<T>* a, int n = 0);
	static void Eliminar(Nodo<T>*& aux, const T& i, bool val);
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
	if (this->raiz == nullptr) {
		this->raiz = new Nodo<T>(dato, nullptr);
	}
	else
		this->raiz->insert(dato);
}

template<class T>
inline Nodo<T>* Arbol<T>::buscar(const T& dato)
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
inline void Arbol<T>::eliminar(const T& i)
{
	Arbol<T>::Eliminar(this->raiz, i, false);
}

template<class T>
inline void Arbol<T>::Eliminar(Nodo<T>*& aux, const T& i, bool val)
{
	if (aux->buscar(i) == nullptr) {

	}
	else {
		if (aux != nullptr) {
			Nodo<T>* aux2;
			if (*aux->getDato() == i) {
				if (aux->getDer() == nullptr and aux->getIzq() == nullptr) {
					if (aux->getPadre()->getIzq() == aux) {
						aux->getPadre()->insertIzq(nullptr);
					}
					else {
						if (aux->getPadre()->getDer() == aux) {
							aux->getPadre()->insertDer(nullptr);
						}
					}
					delete aux;
					aux = nullptr;
				}
				else if (aux->getDer() == nullptr) {
					aux2 = aux->getIzq();
					delete aux;
					aux = aux2;
				}
				else if (aux->getIzq() == nullptr) {
					aux2 = aux->getDer();
					delete aux;
					aux = aux2;
				}
				else { //Caso 3 Tiene más de dos hijos
					Nodo<T>* minimo;
						if (val == true)
							minimo = aux->minimo(aux->getIzq(), val);
						else
							minimo = aux->minimo(aux->getDer(), val);
					if (minimo != nullptr) {
						if (minimo->getPadre() != nullptr) {
							if (minimo->getPadre()->getIzq() == minimo)
								minimo->getPadre()->insertIzq(nullptr);
							else {
								if (minimo->getPadre()->getDer() == minimo)
									minimo->getPadre()->insertDer(nullptr);
							}
						}
						aux2 = new Nodo<T>(*minimo->getDato(), aux->getPadre());
						aux2->insertDer(aux->getDer(), aux2);
						aux2->insertIzq(aux->getIzq(), aux2);
						aux = aux2;
					}
				}
			}
			else {
				if (aux->getPadre() == nullptr) {
					if (*aux->getDato() < i) {
						if (aux->getDer() != nullptr)
							Arbol<T>::Eliminar(aux->getDer(), i, false);
						else
							if (aux->getIzq() != nullptr)
								Arbol<T>::Eliminar(aux->getIzq(), i, true);
					}
					else
					{
						if(aux->getIzq() != nullptr)
							Arbol<T>::Eliminar(aux->getIzq(), i, true);
						else
							Arbol<T>::Eliminar(aux->getDer(), i, false);
					}
				}
				else {
					if (*aux->getDato() < i)
						Arbol<T>::Eliminar(aux->getDer(), i, val);
					else
						Arbol<T>::Eliminar(aux->getIzq(), i, val);
				}

			}
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

