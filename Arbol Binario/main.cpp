// Arbol Binario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include "Nodo.h"
#include "Arbol.h"
#include "stack.h"
using std::cout;
using std::endl;
int main()
{
    Nodo<int>* x = new Nodo<int>(2);
    Nodo<int>* z = new Nodo<int>(3);

    Arbol<char> arbol;
    arbol.insertar('d');
    arbol.insertar('b');
    arbol.insertar('f');
    arbol.insertar('a');
    arbol.insertar('c');
    arbol.insertar('f');
    arbol.insertar('e');
    arbol.insertar('g');
    arbol.imprimirArbol();
}