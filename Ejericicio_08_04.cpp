// Materia: Programaci�n I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creaci�n: 19/09/2023

// Fecha modificaci�n: 20/09/2023

// N�mero de ejericio: 8

// Problema planteado:En una f�brica de computadoras se planea ofrecer a los clientes un descuento que depender� del n�mero de computadoras que compre. Si las computadoras son menos de cinco se les dar� un 10% de descuento sobre el total de la compra; si el n�mero de computadoras es mayor o igual a cinco pero menos de diez se le otorga un 20% de descuento; y si son 10 o m�s se les da un 40% de descuento. El precio de cada computadora es un valor que el usuario ingrese desde el teclado. Se debe obtener el precio total que el cliente debe pagar y el valor del descuento.
#include <iostream>

int main()
{
    int cantidadComputadoras;
    float precioPorComputadora, precioTotal, descuento;

    // Solicitar al usuario la cantidad de computadoras
    cout << "Ingrese la cantidad de computadoras que desea comprar: ";
    cin >> cantidadComputadoras;

    // Solicitar al usuario el precio por computadora
    cout << "Ingrese el precio por computadora en Bs.: ";
    cin >> precioPorComputadora;

    // Calcular el precio total antes del descuento
    precioTotal = cantidadComputadoras * precioPorComputadora;

    // Calcular el descuento
    if (cantidadComputadoras < 5) {
        descuento = precioTotal * 0.10;
    } else if (cantidadComputadoras < 10) {
        descuento = precioTotal * 0.20;
    } else {
        descuento = precioTotal * 0.40;
    }

    // Calcular el precio total despu�s del descuento
    precioTotal -= descuento;

    // Mostrar los resultados
    cout << "Precio total antes del descuento: " << precioTotal + descuento << " Bs." << endl;
    cout << "Descuento aplicado: " << descuento << " Bs." << endl;
    cout << "Precio total a pagar: " << precioTotal << " Bs." << endl;

    return 0;
}
