// Derek Roman Rodriguez
// 1 abril de 2025
/* Este programa permite al usuario calcular el volumen o el area de la superficie de tres figuras tridimensionales: cilindro, esfera o prisma rectangular. */

#include <iostream>
#include <iomanip>
using namespace std;

// volumen
double volumen(double r) { return (4.0/3.0) * 3.1416 * r * r * r; }
double volumen(double r, double h) { return 3.1416 * r * r * h; }
double volumen(double l, double a, double h) { return l * a * h; }

// area
double area(double r) { return 4 * 3.1416 * r * r; }
double area(double r, double h) { return 2 * 3.1416 * r * (r + h); }
double area(double l, double a, double h) { return 2 * (l*a + l*h + a*h); }

// Validar que el valor sea positivo
double pedirDato(string mensaje) {
    double valor;
    do {
        cout << mensaje;
        cin >> valor;
        if (valor <= 0) cout << "Por favor, ingrese un número positivo.\n";
    } while (valor <= 0);
    return valor;
}

int main() {
    char figura, opcion;
    cout << fixed << setprecision(2); // Redondear a 2 decimales

    cout << "a. Cilindro\nb. Esfera\nc. Prisma rectangular\nSeleccion: ";
    cin >> figura;
    if (figura != 'a' && figura != 'b' && figura != 'c') return 1;

    cout << "a. Volumen\nb. Área de la superficie\nSeleccion: ";
    cin >> opcion;
    if (opcion != 'a' && opcion != 'b') return 1;

    switch (figura) {
        case 'a': {
            double r = pedirDato("Radio: "), h = pedirDato("Altura: ");
            cout << "Resultado: " << (opcion == 'a' ? volumen(r, h) : area(r, h)) << endl;
            break;
        }
        case 'b': {
            double r = pedirDato("Radio: ");
            cout << "Resultado: " << (opcion == 'a' ? volumen(r) : area(r)) << endl;
            break;
        }
        case 'c': {
            double l = pedirDato("Largo: "), a = pedirDato("Ancho: "), h = pedirDato("Alto: ");
            cout << "Resultado: " << (opcion == 'a' ? volumen(l, a, h) : area(l, a, h)) << endl;
            break;
        }
    }

    return 0;
}