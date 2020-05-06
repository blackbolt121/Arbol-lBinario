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
    Arbol<std::string> arbol;
    arbol.insertar("mi");
    arbol.insertar("primer");
    arbol.insertar("hola");
    arbol.insertar("mundo");
    stack<std::string> a = arbol.recorrerPostOrden();
    while (!a.isEmpty()) {
        cout << *a.getPeek()->getItem();
        a.pop();
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

/*
Nodo<int> dato = Nodo<int>();
    dato.insert(2);
    dato.insert(1);
    dato.insert(9);
    int* resultado = dato.buscar(2);
    if (resultado != nullptr) {
        std::cout << "El dato se encuentra en el arbol..." << std::endl;
    }
    else {
        std::cout << "El dato no se encuentra en el arbol..." << std::endl;
    }
    std::cout << *dato.getDato();




*/