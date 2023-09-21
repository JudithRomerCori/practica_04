// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 19/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 7

// Problema planteado:Escribir un programa que lea el salario de un empleado y mediante una función efectué un incremento salarial en base a la siguiente escala:
//• Si el salario es menor < 1000 Bs. incremente en un 20%
//• Si el salario es mayor o igual a 1000 pero es menor a 3000 Bs. Incremente en un 15%
//• Si el salario es mayor o igual a 3000 pero es menor a 6000 Bs. Incremente en un 10%
//• Si el salario es mayor o igual a 6000 Bs. Incremente en un 5% La función debe obtener el incremento y el nuevo salario.
#include <iostream>

// Función para calcular el incremento y el nuevo salario
void calcularIncrementoSalario(float salario, float& incremento, float& nuevoSalario) {
    if (salario < 1000) {
        incremento = salario * 0.20;
    } else if (salario >= 1000 && salario < 3000) {
        incremento = salario * 0.15;
    } else if (salario >= 3000 && salario < 6000) {
        incremento = salario * 0.10;
    } else {
        incremento = salario * 0.05;
    }

    nuevoSalario = salario + incremento;
}

int main() {
    float salario, incremento, nuevoSalario;

    // Solicitar al usuario el salario del empleado
    cout << "Ingrese el salario del empleado en Bs.: ";
    cin >> salario;

    // Llamar a la función para calcular el incremento y el nuevo salario
    calcularIncrementoSalario(salario, incremento, nuevoSalario);

    // Mostrar los resultados
    cout << "Incremento salarial: " << incremento << " Bs." << endl;
    cout << "Nuevo salario: " << nuevoSalario << " Bs." << endl;

    return 0;
}
