// Práctica: Ticket de compra
// main() solo coordina: pide los datos, llama a los módulos y muestra el ticket.
// Deja el comentario "// Paso N" sobre cada bloque, con la numeración de TU receta.
//
// Compilar (desde la carpeta del proyecto):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
// Ejecutar:
//   macOS:   ./ticket
//   Windows: .\ticket.exe

// ¿Recuerdas qué hace iostream?
#include <iostream>
#include <string>
#include <iomanip>

#include "utilerias.h"
#include "ticket.h"
using namespace std; 
string nombre;
double precio;
int cantidad;
double porcentaje;
int subtotal;
double calculototal;
double vasolo;
double ivatotal;
double descuento;

inline double ivasolo(double calculototal){
    return calculototal* .16; 

    
}


int main() {
    // Variables (siempre inicializadas)
    // TODO: ¿cuántas necesitas? ¿De qué tipo es cada una?

    // Paso 1: mensaje de bienvenida
    // TODO
    std:: cout << "======= la tiendita ======= " << endl ;
    std:: cout << "======ingresa los datos=====" << endl;
      

    // Paso 2: pedir y validar los datos
    // TODO: ¿qué función de utilerias.h usas para cada dato?
    nombre = leerCadena("nombre: ");
   
 while(true) {precio = leerDecimal("precio$: ");
    if(precio > 0) { break; } std:: cout << "error"<<endl;
     }
        
     while(true) {cantidad = leerEntero("cantidad: ");
    if(cantidad > 0) { break; } std:: cout << "error"<<endl;
     }
    while(true) {porcentaje = leerDecimal("descuento%: ");
    if(porcentaje > 0) { break; } std:: cout << "error"<<endl;
     }
    
    //       ¿Cómo vuelves a pedir un dato que está fuera de rango?

    // Paso 3: calcular los importes llamando a los módulos de ticket.h
subtotal = calcularSubtotal(precio, cantidad);
descuento = calcularDescuento(subtotal, porcentaje);
calculototal = calcularTotal(subtotal, porcentaje);
vasolo = ivasolo(calculototal);

ivatotal = vasolo + calculototal;

std:: cout << "=========================================" << endl;
std:: cout << "                    ticket               " << endl;
std:: cout << "=========================================" << endl;
std::cout << std::setw(15) << "nombre:";
std:: cout  << nombre << endl; 
std:: cout << "=========================================" << endl;
std::cout << std::setw(15) << "subtotal:";
std:: cout << subtotal << endl;
std:: cout << "=========================================" << endl;
std::cout << std::setw(15) << "descuento:";
std:: cout  << descuento << endl;
std:: cout << "=========================================" << endl;
std::cout << std::setw(15) << "calculo total:";
std:: cout  << calculototal << endl;
std:: cout << "=========================================" << endl;
std::cout << std::setw(15) << "iva:";
std:: cout  << vasolo << endl; 
std:: cout << "=========================================" << endl;
std::cout << std::setw(15) << "total:";
std:: cout << ivatotal << endl;
std:: cout << "=========================================" << endl;
std:: cout << "=========================================" << endl; 
    // TODO

    // Paso 4: imprimir el ticket
    // TODO

    // ¿Qué significa return 0;?
    return 0;
}
