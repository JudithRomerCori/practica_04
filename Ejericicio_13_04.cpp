// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 19/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 13

// Problema planteado:Una empresa efectúa el control de asistencia de sus empleados mediante un lector
//biométrico, el horario en la entrada es a las 8:00 a.m y la salida es a las 16:00 p.m. El empleado
//tiene una tolerancia de 10 minutos en la entrada, si llega más allá de los 10 minutos de tolerancia
//se penaliza todos los minutos de atraso (es decir si llega a las 8:12 se penalizan los 12 minutos).
//De igual forma no puede salir antes del horario establecido en la salida, (si lo hace se penaliza
//los minutos faltantes), pero si el empleado entra antes o sale después de sus horarios el sistema
//solo toma en cuenta las 8 horas laborales de trabajo.

#include <iostream>
#include <iomanip>
#include <vector>

struct RegistroEmpleado {
    int codigo;
    int horaEntrada;
    int minutoEntrada;
    int horaSalida;
    int minutoSalida;
    int penalizacion;
    string fecha;
};

// Función para calcular la penalización de un empleado
void calcularPenalizacion(RegistroEmpleado& empleado) {
    int horaEntrada = empleado.horaEntrada * 60 + empleado.minutoEntrada;
    int horaSalida = empleado.horaSalida * 60 + empleado.minutoSalida;
    int horaToleranciaEntrada = 8 * 60;
    int horaSalidaPermitida = 16 * 60;

    if (horaEntrada > horaToleranciaEntrada) {
        empleado.penalizacion = horaEntrada - horaToleranciaEntrada;
    } else {
        empleado.penalizacion = 0;
    }

    if (horaSalida < horaSalidaPermitida) {
        empleado.penalizacion += horaSalidaPermitida - horaSalida;
    }

    // Limitar la penalización a un máximo de 60 minutos (una hora)
    if (empleado.penalizacion > 60) {
        empleado.penalizacion = 60;
    }
}

int main() {
    vector<RegistroEmpleado> empleados = {
        {101045, 7, 55, 16, 15, 0, "12/01/2011"},
        {223032, 8, 11, 16, 0, 0, "12/01/2011"},
        {334009, 8, 30, 16, 20, 0, "12/01/2011"},
        {443283, 8, 5, 16, 10, 0, "12/01/2011"}
    };

    cout << "Código Empleado   Hora Entrada   Hora Salida   Penalización   Fecha" << endl;

    for (const auto& empleado : empleados) {
        calcularPenalizacion(const_cast<RegistroEmpleado&>(empleado)); // Llamada a la función para calcular la penalización
        cout << empleado.codigo << "              "
                  << setw(2) << setfill('0') << empleado.horaEntrada << ":"
                  << setw(2) << setfill('0') << empleado.minutoEntrada << "         "
                  << setw(2) << setfill('0') << empleado.horaSalida << ":"
                  << setw(2) << setfill('0') << empleado.minutoSalida << "        "
                  << empleado.penalizacion << "            "
                  << empleado.fecha << endl;
    }

    return 0;
}
