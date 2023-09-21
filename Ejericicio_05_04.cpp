// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 19/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 5

// Problema planteado:Elabore un programa para registro académico de la UCB, que solicite el nombre de una materia, el paralelo, el docente y sus correspondientes notas de periodo. Al final, se muestra la nota final y si aprobó o reprobo el curso. (realizar con estructuras)

#include <iostream>
#include <string>

// Definición de la estructura para almacenar información académica
struct RegistroAcademico {
    string materia;
    string paralelo;
    string docente;
    float nota1;
    float nota2;
    float nota3;
};

// Función para calcular la nota final y determinar si aprobó o reprobó
void calcularNotaFinal(RegistroAcademico &registro) {
    float notaFinal = (registro.nota1 + registro.nota2 + registro.nota3) / 3;

    registro.notaFinal = notaFinal;

    if (notaFinal >= 60) {
        registro.aprobado = true;
    } else {
        registro.aprobado = false;
    }
}

int main() {
    RegistroAcademico registro;

    // Solicitar información académica al usuario
    cout << "Nombre de la materia: ";
    cin >> registro.materia;
    cout << "Paralelo: ";
    cin >> registro.paralelo;
    cout << "Nombre del docente: ";
    cin >> registro.docente;
    cout << "Nota del primer periodo: ";
    cin >> registro.nota1;
    cout << "Nota del segundo periodo: ";
    cin >> registro.nota2;
    cout << "Nota del tercer periodo: ";
    cin >> registro.nota3;

    // Calcular la nota final y determinar si aprobó o reprobó
    calcularNotaFinal(registro);

    // Mostrar los resultados
    cout << "Nota final en " << registro.materia << ": " << registro.notaFinal << endl;

    if (registro.aprobado) {
        cout << "¡Aprobado!" << endl;
    } else {
        cout << "Reprobado" << endl;
    }

    return 0;
}
