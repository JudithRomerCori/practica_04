// Materia: Programaci�n I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creaci�n: 19/09/2023

// Fecha modificaci�n: 20/09/2023

// N�mero de ejericio: 2

// Problema planteado:Lee por teclado la fecha actual y la fecha de nacimiento de una persona y calcula su edad.

#include <iostream>
#include <ctime>

// Funci�n para calcular la edad en a�os
int calcularEdad(int a�oNacimiento, int mesNacimiento, int diaNacimiento) {
    // Obtiene la fecha actual
    time_t tiempoActual = time(nullptr);
    tm* fechaActual = localtime(&tiempoActual);

    int a�oActual = fechaActual->tm_year + 1900; // tm_year cuenta los a�os desde 1900
    int mesActual = fechaActual->tm_mon + 1;     // tm_mon comienza desde 0
    int diaActual = fechaActual->tm_mday;

    // Calcula la edad
    int edad = a�oActual - a�oNacimiento;

    // Ajusta la edad si a�n no ha cumplido a�os en este a�o
    if (mesNacimiento > mesActual || (mesNacimiento == mesActual && diaNacimiento > diaActual)) {
        edad--;
    }

    return edad;
}

int main() {
    int a�oNacimiento, mesNacimiento, diaNacimiento;

    // Lee la fecha de nacimiento por teclado
    cout << "Ingrese el a�o de nacimiento: ";
    cin >> a�oNacimiento;
    cout << "Ingrese el mes de nacimiento: ";
    cin >> mesNacimiento;
    cout << "Ingrese el d�a de nacimiento: ";
    cin >> diaNacimiento;

    // Llama a la funci�n calcularEdad y muestra la edad
    int edad = calcularEdad(a�oNacimiento, mesNacimiento, diaNacimiento);
    cout << "La edad es: " << edad << " a�os." << endl;

    return 0;
}
