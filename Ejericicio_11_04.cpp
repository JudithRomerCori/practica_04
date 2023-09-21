// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 19/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 11

// Problema planteado:Realice una función que enviándole dos numero calcule el máximo común divisor con el algoritmo de Euclides.

#include <iostream>

// Función para calcular el máximo común divisor (MCD) usando el algoritmo de Euclides
int calcularMCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    cout << "Ingrese el primer número: ";
    cin >> num1;

    cout << "Ingrese el segundo número: ";
    cin >> num2;

    int mcd = calcularMCD(num1, num2);

    cout << "El MCD de " << num1 << " y " << num2 << " es " << mcd << endl;

    return 0;
}
