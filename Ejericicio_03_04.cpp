#include <iostream>
#include <string>

// Definición de la estructura para almacenar datos de una persona
struct Persona {
    string nombre;
    int edad;
    float estatura;
    float peso;
};

int main() {
    const int numPersonas = 12; // Número de personas
    Persona personas[numPersonas]; // Arreglo de estructuras para almacenar los datos

    // Leer los datos de las doce personas
    for (int i = 0; i < numPersonas; ++i) {
        cout << "Persona " << i + 1 << endl;
        cout << "Nombre: ";
        cin >> personas[i].nombre;
        cout << "Edad: ";
        cin >> personas[i].edad;
        cout << "Estatura (en metros): ";
        cin >> personas[i].estatura;
        cout << "Peso (en kilogramos): ";
        cin >> personas[i].peso;
        cout << endl;
    }

    // Inicializar variables para encontrar la persona de menor edad
    int edadMinima = personas[0].edad;
    string nombreMenorEdad = personas[0].nombre;

    // Inicializar variables para calcular el promedio de estaturas y pesos
    float sumaEstaturas = 0.0;
    float sumaPesos = 0.0;

    // Calcular la persona de menor edad, promedio de estaturas y promedio de pesos
    for (int i = 0; i < numPersonas; ++i) {
        // Encontrar la persona de menor edad
        if (personas[i].edad < edadMinima) {
            edadMinima = personas[i].edad;
            nombreMenorEdad = personas[i].nombre;
        }

        // Sumar las estaturas y los pesos
        sumaEstaturas += personas[i].estatura;
        sumaPesos += personas[i].peso;
    }

    // Calcular el promedio de estaturas y pesos
    float promedioEstaturas = sumaEstaturas / numPersonas;
    float promedioPesos = sumaPesos / numPersonas;

    // Mostrar los resultados
    cout << "Persona de menor edad: " << nombreMenorEdad << endl;
    cout << "Promedio de estaturas: " << promedioEstaturas << " metros" << endl;
    cout << "Promedio de pesos: " << promedioPesos << " kilogramos" << endl;

    return 0;
}
