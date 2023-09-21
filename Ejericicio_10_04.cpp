// Materia: Programaci�n I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creaci�n: 19/09/2023

// Fecha modificaci�n: 20/09/2023

// N�mero de ejericio: 10

// Problema planteado:. Construir las funciones para ordenar un vector de N elementos aleatorios y los ordene por.
//� Por selecci�n
//� Por inserci�n
//� Por el m�todo burbuja
//� Por el m�todo Shell
//� Por QuickSort

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funci�n para generar un vector de n�meros aleatorios
vector<int> generarVectorAleatorio(int N) {
    vector<int> numeros;
    srand(time(0)); // Inicializar la semilla del generador de n�meros aleatorios

    for (int i = 0; i < N; i++) {
        numeros.push_back(rand() % 100); // Genera n�meros aleatorios entre 0 y 99
    }

    return numeros;
}

// Funci�n para imprimir un vector
void imprimirVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Ordenaci�n por Selecci�n
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

// Ordenaci�n por Inserci�n
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

// Ordenaci�n por el M�todo de la Burbuja
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

// Ordenaci�n por el M�todo Shell
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

// Funci�n QuickSort
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
    cout << "Ingrese el tama�o del vector: ";
    cin >> N;

    vector<int> vec = generarVectorAleatorio(N);

    cout << "Vector generado aleatoriamente:" << endl;
    imprimirVector(vec);

    // Ordenar el vector utilizando diferentes algoritmos de ordenaci�n
    vector<int> copiaVec = vec; // Hacemos una copia para preservar el original

    // Ordenaci�n por Selecci�n
    selectionSort(copiaVec);
    cout << "Ordenado por Selecci�n:" << endl;
    imprimirVector(copiaVec);

    // Ordenaci�n por Inserci�n
    copiaVec = vec; // Restauramos la copia
    insertionSort(copiaVec);
    cout << "Ordenado por Inserci�n:" << endl;
    imprimirVector(copiaVec);

    // Ordenaci�n por el M�todo de la Burbuja
    copiaVec = vec; // Restauramos la copia
    bubbleSort(copiaVec);
    cout << "Ordenado por el M�todo de la Burbuja:" << endl;
    imprimirVector(copiaVec);

    // Ordenaci�n por el M�todo Shell
    copiaVec = vec; // Restauramos la copia
    shellSort(copiaVec);
    cout << "Ordenado por el M�todo Shell:" << endl;
    imprimirVector(copiaVec);

    // Ordenaci�n por QuickSort
    copiaVec = vec; // Restauramos la copia
    quickSort(copiaVec, 0, N - 1);
    cout << "Ordenado por QuickSort:" << endl;
    imprimirVector(copiaVec);

    return 0;
}
