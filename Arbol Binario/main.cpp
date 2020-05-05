// Arbol Binario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include "Nodo.h"
#include "Arbol.h"
#include "stack.h"

int main()
{
    Arbol<int> arbol;
    arbol.insertar(2);
    arbol.insertar(3);
    arbol.insertar(1);
    arbol.insertar(5);
    arbol.insertar(4);
    arbol.insertar(8);
    stack<int> imprimir = arbol.recorrerInOrden();
    if (imprimir.isEmpty()) {
        std::cout << "La pila esta vacia";
    }
    else {
        while (!imprimir.isEmpty()) {
            std::cout << *imprimir.pop()->getItem() << std::endl;
        }
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