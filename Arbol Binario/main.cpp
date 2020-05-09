// Arbol Binario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include "Nodo.h"
#include "Arbol.h"
#include "stack.h"
using std::cout;
using std::endl;
int main()
{
    Arbol<char> c;
    for (int i = 65; i <= 90; i++) {
        c.insertar(i);
    }
    for (int i = 97; i <= 122; i++) {
        c.insertar(i);
    }
    if (c.buscar('A') != nullptr) cout << "El dato esta en el arbol" << endl;
    
}