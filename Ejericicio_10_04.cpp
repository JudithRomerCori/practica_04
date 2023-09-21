// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 19/09/2023

// Fecha modificación: 20/09/2023

// Número de ejericio: 10

// Problema planteado:. Construir las funciones para ordenar un vector de N elementos aleatorios y los ordene por.
//• Por selección
//• Por inserción
//• Por el método burbuja
//• Por el método Shell
//• Por QuickSort

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para generar un vector de números aleatorios
vector<int> generarVectorAleatorio(int N) {
    vector<int> numeros;
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios

    for (int i = 0; i < N; i++) {
        numeros.push_back(rand() % 100); // Genera números aleatorios entre 0 y 99
    }

    return numeros;
}

// Función para imprimir un vector
void imprimirVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Ordenación por Selección
void selectionSort(vector<int>& vec) {
    int N = vec.size();

    for (int i = 0; i < N - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < N; j++) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        swap(vec[i], vec[minIndex]);
    }
}

// Ordenación por Inserción
void insertionSort(vector<int>& vec) {
    int N = vec.size();

    for (int i = 1; i < N; i++) {
        int key = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }

        vec[j + 1] = key;
    }
}

// Ordenación por el Método de la Burbuja
void bubbleSort(vector<int>& vec) {
    int N = vec.size();

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// Ordenación por el Método Shell
void shellSort(vector<int>& vec) {
    int N = vec.size();

    for (int gap = N / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; i++) {
            int temp = vec[i];
            int j;
            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap) {
                vec[j] = vec[j - gap];
            }
            vec[j] = temp;
        }
    }
}

// Función QuickSort
int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);

        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main() {
    int N;
    cout << "Ingrese el tamaño del vector: ";
    cin >> N;

    vector<int> vec = generarVectorAleatorio(N);

    cout << "Vector generado aleatoriamente:" << endl;
    imprimirVector(vec);

    // Ordenar el vector utilizando diferentes algoritmos de ordenación
    vector<int> copiaVec = vec; // Hacemos una copia para preservar el original

    // Ordenación por Selección
    selectionSort(copiaVec);
    cout << "Ordenado por Selección:" << endl;
    imprimirVector(copiaVec);

    // Ordenación por Inserción
    copiaVec = vec; // Restauramos la copia
    insertionSort(copiaVec);
    cout << "Ordenado por Inserción:" << endl;
    imprimirVector(copiaVec);

    // Ordenación por el Método de la Burbuja
    copiaVec = vec; // Restauramos la copia
    bubbleSort(copiaVec);
    cout << "Ordenado por el Método de la Burbuja:" << endl;
    imprimirVector(copiaVec);

    // Ordenación por el Método Shell
    copiaVec = vec; // Restauramos la copia
    shellSort(copiaVec);
    cout << "Ordenado por el Método Shell:" << endl;
    imprimirVector(copiaVec);

    // Ordenación por QuickSort
    copiaVec = vec; // Restauramos la copia
    quickSort(copiaVec, 0, N - 1);
    cout << "Ordenado por QuickSort:" << endl;
    imprimirVector(copiaVec);

    return 0;
}
