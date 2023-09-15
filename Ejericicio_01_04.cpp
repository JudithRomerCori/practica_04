// Materia: Programaci�n I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creaci�n: 14/09/2023

// Fecha modificaci�n: 14/09/2023

// N�mero de ejericio: 1

// Problema planteado:Construir las funciones para ordenar un vector de N elementos aleatorios y los ordene por.
//� Por selecci�n
//� Por inserci�n
//� Por el m�todo burbuja

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funci�n para imprimir un vector
void imprimirVector(const vector<int>& vec) {
    for (int elemento : vec) {
        cout << elemento << " ";
    }
    cout << endl;
}

// Funci�n para ordenar un vector por selecci�n
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

// Funci�n para ordenar un vector por inserci�n
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

// Funci�n para ordenar un vector por el m�todo burbuja
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
    // Semilla para n�meros aleatorios
    srand(time(nullptr));

    int N;
    cout << "Ingrese el tama�o del vector: ";
    cin >> N;

    vector<int> vec(N);

    // Generar valores aleatorios para el vector
    for (int i = 0; i < N; i++) {
        vec[i] = rand() % 100; // Valores aleatorios entre 0 y 99
    }

    cout << "Vector original: ";
    imprimirVector(vec);

    // Ordenar el vector por selecci�n
    vector<int> vecSeleccion = vec;
    ordenarPorSeleccion(vecSeleccion);
    cout << "Ordenado por selecci�n: ";
    imprimirVector(vecSeleccion);

    // Ordenar el vector por inserci�n
    vector<int> vecInsercion = vec;
    ordenarPorInsercion(vecInsercion);
    cout << "Ordenado por inserci�n: ";
    imprimirVector(vecInsercion);

    // Ordenar el vector por burbuja
    vector<int> vecBurbuja = vec;
    ordenarPorBurbuja(vecBurbuja);
    cout << "Ordenado por el m�todo burbuja: ";
    imprimirVector(vecBurbuja);

    return 0;
}
