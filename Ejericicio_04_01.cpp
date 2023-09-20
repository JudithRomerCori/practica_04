// Materia: Programaci�n I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creaci�n: 19/09/2023

// Fecha modificaci�n: 20/09/2023

// N�mero de ejericio: 1

// Problema planteado:Lee por teclado un a�o y calcula y muestra si es bisiesto

#include <iostream>

// Funci�n para verificar si un a�o es bisiesto
bool esBisiesto(int a�o) {
    if ((a�o % 4 == 0 && a�o % 100 != 0) || (a�o % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int a�o;

    // Lee el a�o por teclado
    cout << "Ingrese un a�o: ";
    cin >> a�o;

    // Llama a la funci�n esBisiesto y muestra el resultado
    if (esBisiesto(a�o)) {
        cout << a�o << " es un a�o bisiesto." << endl;
    } else {
        cout << a�o << " no es un a�o bisiesto." << endl;
    }

    return 0;
}
