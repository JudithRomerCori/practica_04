// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 19/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 4

// Problema planteado:Escribir el programa para solicitar al usuario N calificaciones comprendidas en el rango de 1 a 100, calcular y presentar la sumatoria y promedio de estas N calificaciones. La entrada de valores es para las calificaciones, debe hacerlo mediante una función.

#include <iostream>

// Función para leer las calificaciones y calcular la sumatoria y el promedio
void calcularSumaPromedioCalificaciones(int N, float &sumatoria, float &promedio) {
    sumatoria = 0.0;

    for (int i = 0; i < N; ++i) {
        float calificacion;
        do {
            cout << "Ingrese la calificación " << i + 1 << " (entre 1 y 100): ";
            cin >> calificacion;
        } while (calificacion < 1 || calificacion > 100); // Asegura que la calificación esté en el rango

        sumatoria += calificacion;
    }

    promedio = sumatoria / N;
}

int main() {
    int N;
    float sumatoria, promedio;

    cout << "Ingrese la cantidad de calificaciones a ingresar: ";
    cin >> N;

    if (N <= 0) {
        cout << "El número de calificaciones debe ser mayor que cero." << endl;
        return 1; // Salir del programa con código de error
    }

    calcularSumaPromedioCalificaciones(N, sumatoria, promedio);

    cout << "La sumatoria de las calificaciones es: " << sumatoria << endl;
    cout << "El promedio de las calificaciones es: " << promedio << endl;

    return 0;
}
