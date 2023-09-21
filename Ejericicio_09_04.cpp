// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 19/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 9

// Problema planteado:A un trabajador se le paga según las horas que trabaja en la semana, una tarifa de pago por hora. Si la cantidad de horas trabajadas es mayor a 40, la tarifa se incrementa en un 50%. Calcular el salario total del trabajador, además considere que si existe un anticipo se debe restar este valor al salario total. Al total debe descontar un 10% para el pago de impuestos. Se debe obtener:
//- Total ganado
//- Total descuentos
//- Pago neto
#include <iostream>
using namespace std;

// Función para calcular el salario total
double calcularSalarioTotal(double horasTrabajadas, double tarifaPorHora, double anticipo) {
    double salarioTotal;

    // Verificar si las horas trabajadas son mayores a 40 para aplicar el incremento del 50%
    if (horasTrabajadas > 40) {
        double horasExtras = horasTrabajadas - 40;
        salarioTotal = (40 * tarifaPorHora) + (horasExtras * tarifaPorHora * 1.5);
    } else {
        salarioTotal = horasTrabajadas * tarifaPorHora;
    }

    // Restar el anticipo
    salarioTotal -= anticipo;

    return salarioTotal;
}

int main() {
    double horasTrabajadas, tarifaPorHora, anticipo;

    cout << "Ingrese las horas trabajadas en la semana: ";
    cin >> horasTrabajadas;

    cout << "Ingrese la tarifa por hora: ";
    cin >> tarifaPorHora;

    cout << "Ingrese el anticipo (si no hay anticipo, ingrese 0): ";
    cin >> anticipo;

    double salarioTotal = calcularSalarioTotal(horasTrabajadas, tarifaPorHora, anticipo);
    double impuestos = salarioTotal * 0.10; // 10% de impuestos
    double totalDescuentos = anticipo + impuestos;
    double pagoNeto = salarioTotal - totalDescuentos;

    cout << "Total ganado: $" << salarioTotal << endl;
    cout << "Total descuentos: $" << totalDescuentos << endl;
    cout << "Pago neto: $" << pagoNeto << endl;

    return 0;
}
