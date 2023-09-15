// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 14/09/2023

// Fecha modificación: 14/09/2023

// Número de ejericio: 1

// Problema planteado:Construir las funciones para ordenar un vector de N elementos aleatorios y los ordene por.
//• Por selección
//• Por inserción
//• Por el método burbuja

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para imprimir un vector
void imprimirVector(const vector<int>& vec) {
    for (int elemento : vec) {
        cout << elemento << " ";
    }
    cout << endl;
}

// Función para ordenar un vector por selección
void ordenarPorSeleccion(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(vec[i], vec[minIndex]);
        }
    }
}

// Función para ordenar un vector por inserción
void ordenarPorInsercion(vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int clave = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > clave) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = clave;
    }
}

// Función para ordenar un vector por el método burbuja
void ordenarPorBurbuja(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    // Semilla para números aleatorios
    srand(time(nullptr));

    int N;
    cout << "Ingrese el tamaño del vector: ";
    cin >> N;

    vector<int> vec(N);

    // Generar valores aleatorios para el vector
    for (int i = 0; i < N; i++) {
        vec[i] = rand() % 100; // Valores aleatorios entre 0 y 99
    }

    cout << "Vector original: ";
    imprimirVector(vec);

    // Ordenar el vector por selección
    vector<int> vecSeleccion = vec;
    ordenarPorSeleccion(vecSeleccion);
    cout << "Ordenado por selección: ";
    imprimirVector(vecSeleccion);

    // Ordenar el vector por inserción
    vector<int> vecInsercion = vec;
    ordenarPorInsercion(vecInsercion);
    cout << "Ordenado por inserción: ";
    imprimirVector(vecInsercion);

    // Ordenar el vector por burbuja
    vector<int> vecBurbuja = vec;
    ordenarPorBurbuja(vecBurbuja);
    cout << "Ordenado por el método burbuja: ";
    imprimirVector(vecBurbuja);

    return 0;
}
