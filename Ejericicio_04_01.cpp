// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 19/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 1

// Problema planteado:Lee por teclado un año y calcula y muestra si es bisiesto

#include <iostream>

// Función para verificar si un año es bisiesto
bool esBisiesto(int año) {
    if ((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int año;

    // Lee el año por teclado
    cout << "Ingrese un año: ";
    cin >> año;

    // Llama a la función esBisiesto y muestra el resultado
    if (esBisiesto(año)) {
        cout << año << " es un año bisiesto." << endl;
    } else {
        cout << año << " no es un año bisiesto." << endl;
    }

    return 0;
}
