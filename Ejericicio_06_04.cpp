// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 19/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 6

// Problema planteado:Escriba un programa que mediante una función determine el pago por el servicio de estacionamiento de coches en un parqueo, teniendo en cuenta que la primera hora de estadía se paga 8 Bs., y las restantes 3 Bs. c/hora. Si el uso del servicio es menor a una hora se cobra por la hora y de igual manera si excede la hora se cobra por la hora siguiente.

#include <iostream>

// Función para calcular el tiempo de estacionamiento en horas
int calcularTiempoEstacionamiento(int horaEntrada, int minutoEntrada, int horaSalida, int minutoSalida) {
    int tiempoTotal = 0;

    // Convertir horas y minutos a minutos
    int minutosEntrada = horaEntrada * 60 + minutoEntrada;
    int minutosSalida = horaSalida * 60 + minutoSalida;

    // Calcular la diferencia en minutos
    int diferenciaMinutos = minutosSalida - minutosEntrada;

    // Redondear hacia arriba al número entero más cercano de horas
    tiempoTotal = (diferenciaMinutos + 59) / 60;

    return tiempoTotal;
}

// Función para calcular el costo del estacionamiento
float calcularCostoEstacionamiento(int tiempoEstacionamiento) {
    if (tiempoEstacionamiento <= 0) {
        return 0.0; // Si el uso es menor o igual a 0 horas, no se cobra.
    } else if (tiempoEstacionamiento == 1) {
        return 8.0; // Si el uso es de 1 hora, se cobra 8 Bs.
    } else {
        // Si el uso es mayor a 1 hora, se cobra 8 Bs. por la primera hora y 3 Bs. por cada hora adicional.
        return 8.0 + (tiempoEstacionamiento - 1) * 3.0;
    }
}

int main() {
    int horaEntrada, minutoEntrada, horaSalida, minutoSalida;

    // Solicitar al usuario los datos de entrada y salida
    cout << "Hora de entrada (en formato 24 horas): ";
    cin >> horaEntrada;
    cout << "Minuto de entrada: ";
    cin >> minutoEntrada;
    cout << "Hora de salida (en formato 24 horas): ";
    cin >> horaSalida;
    cout << "Minuto de salida: ";
    cin >> minutoSalida;

    // Calcular el tiempo de estacionamiento
    int tiempoEstacionamiento = calcularTiempoEstacionamiento(horaEntrada, minutoEntrada, horaSalida, minutoSalida);

    // Calcular el costo del estacionamiento
    float costo = calcularCostoEstacionamiento(tiempoEstacionamiento);

    // Mostrar el resultado
    cout << "El tiempo de estacionamiento fue de " << tiempoEstacionamiento << " horas." << endl;
    cout << "El costo del estacionamiento es de " << costo << " Bs." << endl;

    return 0;
}
