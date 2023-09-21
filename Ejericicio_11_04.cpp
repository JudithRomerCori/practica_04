// Materia: Programaci�n I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creaci�n: 19/09/2023

// Fecha modificaci�n: 20/09/2023

// N�mero de ejericio: 11

// Problema planteado:Realice una funci�n que envi�ndole dos numero calcule el m�ximo com�n divisor con el algoritmo de Euclides.

#include <iostream>

// Funci�n para calcular el m�ximo com�n divisor (MCD) usando el algoritmo de Euclides
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

    cout << "Ingrese el primer n�mero: ";
    cin >> num1;

    cout << "Ingrese el segundo n�mero: ";
    cin >> num2;

    int mcd = calcularMCD(num1, num2);

    cout << "El MCD de " << num1 << " y " << num2 << " es " << mcd << endl;

    return 0;
}
