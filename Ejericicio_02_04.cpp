// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 19/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 2

// Problema planteado:Lee por teclado la fecha actual y la fecha de nacimiento de una persona y calcula su edad.

#include <iostream>
#include <ctime>

// Función para calcular la edad en años
int calcularEdad(int añoNacimiento, int mesNacimiento, int diaNacimiento) {
    // Obtiene la fecha actual
    time_t tiempoActual = time(nullptr);
    tm* fechaActual = localtime(&tiempoActual);

    int añoActual = fechaActual->tm_year + 1900; // tm_year cuenta los años desde 1900
    int mesActual = fechaActual->tm_mon + 1;     // tm_mon comienza desde 0
    int diaActual = fechaActual->tm_mday;

    // Calcula la edad
    int edad = añoActual - añoNacimiento;

    // Ajusta la edad si aún no ha cumplido años en este año
    if (mesNacimiento > mesActual || (mesNacimiento == mesActual && diaNacimiento > diaActual)) {
        edad--;
    }

    return edad;
}

int main() {
    int añoNacimiento, mesNacimiento, diaNacimiento;

    // Lee la fecha de nacimiento por teclado
    cout << "Ingrese el año de nacimiento: ";
    cin >> añoNacimiento;
    cout << "Ingrese el mes de nacimiento: ";
    cin >> mesNacimiento;
    cout << "Ingrese el día de nacimiento: ";
    cin >> diaNacimiento;

    // Llama a la función calcularEdad y muestra la edad
    int edad = calcularEdad(añoNacimiento, mesNacimiento, diaNacimiento);
    cout << "La edad es: " << edad << " años." << endl;

    return 0;
}
