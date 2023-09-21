// Materia: Programaci�n I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creaci�n: 19/09/2023

// Fecha modificaci�n: 20/09/2023

// N�mero de ejericio: 5

// Problema planteado:Elabore un programa para registro acad�mico de la UCB, que solicite el nombre de una materia, el paralelo, el docente y sus correspondientes notas de periodo. Al final, se muestra la nota final y si aprob� o reprobo el curso. (realizar con estructuras)

#include <iostream>
#include <string>

// Definici�n de la estructura para almacenar informaci�n acad�mica
struct RegistroAcademico {
    string materia;
    string paralelo;
    string docente;
    float nota1;
    float nota2;
    float nota3;
};

// Funci�n para calcular la nota final y determinar si aprob� o reprob�
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

    // Solicitar informaci�n acad�mica al usuario
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

    // Calcular la nota final y determinar si aprob� o reprob�
    calcularNotaFinal(registro);

    // Mostrar los resultados
    cout << "Nota final en " << registro.materia << ": " << registro.notaFinal << endl;

    if (registro.aprobado) {
        cout << "�Aprobado!" << endl;
    } else {
        cout << "Reprobado" << endl;
    }

    return 0;
}
