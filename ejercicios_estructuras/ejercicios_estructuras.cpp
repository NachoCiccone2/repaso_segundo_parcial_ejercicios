#include <iostream>

using namespace std;

/*  Ejercicio 1: Registro de estudiantes:
    Crear un struct Estudiante con nombre, edad y promedio.
    Carga 3 estudiantes en un array y encuentra cuál tiene el mejor promedio.
*/

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

const int CANT_ESTUDIANTES = 3;

void ejercicio1(){
    Estudiante estudiantes[CANT_ESTUDIANTES];
    int indice_mejor_promedio = 0;
    for(int i=0; i<CANT_ESTUDIANTES; i++){
        cout << "\nEscribe el nombre completo del estudiante numero " << i+1 << " : ";
        getline(cin, estudiantes[i].nombre);
        cout << "Escribe su edad: ";
        cin >> estudiantes[i].edad;
        cout << "Escribe su promedio: ";
        cin >> estudiantes[i].promedio;
        cin.ignore();
    }

    for(int i=0; i<CANT_ESTUDIANTES; i++){
        cout << "\nEstudiante numero " << i+1 << ":" << endl;
        cout << "   nombre: " << estudiantes[i].nombre << endl;
        cout << "   edad: " << estudiantes[i].edad << endl;
        cout << "   promedio: " << estudiantes[i].promedio << endl;
        
        if(i<2){
            if(estudiantes[i].promedio < estudiantes[i+1].promedio){
                indice_mejor_promedio = i+1;
            }
        }
    }

    cout << "\nEstudiante con mejor promedio: " << endl;
    cout << "   nombre: " << estudiantes[indice_mejor_promedio].nombre << endl;
    cout << "   edad: " << estudiantes[indice_mejor_promedio].edad << endl;
    cout << "   promedio: " << estudiantes[indice_mejor_promedio].promedio << endl;

    return;
}

/*  Ejercicio 2: Clasificar personas por edad y género:
    Crear un struct Persona con nombre, edad y género.
    Cargar un array con varias personas y determinar cuántas son menores de edad (menos de 18 años) y cuántas están jubiladas (hombres ≥65 años, mujeres ≥60 años).
*/

struct Persona {
    string nombre;
    int edad;
    char genero;
};

const int CANT_PERSONAS = 30;
const char MASCULINO = 'M';
const char FEMENINO = 'F';

void ejercicio2(){
    Persona personas[CANT_PERSONAS];
    int cant_menores = 0, cant_jubilados = 0;
    for(int i=0; i<CANT_PERSONAS; i++){
        cout << "\nEscribe el nombre completo la persona numero " << i+1 << " : ";
        getline(cin, personas[i].nombre);
        cout << "Escribe su edad: ";
        cin >> personas[i].edad;
        cout << "Indica el género de la persona (M|F): ";
        cin >> personas[i].genero;
        cin.ignore();

        if(personas[i].edad < 18){
            cant_menores++;
        } else if ( (personas[i].genero == MASCULINO && personas[i].edad > 65) || ( personas[i].genero == FEMENINO && personas[i].edad > 60 )){
            cant_jubilados++;
        }
    }
    cout << "\n\n" << endl;
    for(int i=0; i<CANT_PERSONAS; i++){
        cout << i+1 << ". " << personas[i].nombre << " - " << personas[i].edad << " - " << personas[i].genero << endl;
    }

    cout << "\n\nDel grupo de personas, hay " << cant_menores << " menores de edad y " << cant_jubilados << " jubulados." << endl;
}

/*  Ejercicio 3: Inventario:
    Crear un struct Producto con nombre, precio y cantidad.
    Cargar 3 productos y mostrar cuál tiene mayor valor total en stock (precio × cantidad).
*/

struct Producto {
    string nombre;
    int precio;
    int cantidad;
};

const int CANT_PRODUCTOS = 3;

void ejercicio3(){
    Producto stock[CANT_PRODUCTOS];
    int mayor_valor_en_stock = 0;
    int indice_mayor_valor_en_stock = 0;
    for(int i=0; i<CANT_PRODUCTOS; i++){
        cout << "\nEscribe el nombre del producto numero " << i+1 << " : ";
        getline(cin, stock[i].nombre);
        cout << "Escribe su precio: ";
        cin >> stock[i].precio;
        cout << "Indica la cantidad de " << stock[i].nombre << " en stock: ";
        cin >> stock[i].cantidad;
        cin.ignore();

        int valor_en_stock = (stock[i].precio * stock[i].cantidad);
        if( valor_en_stock >  mayor_valor_en_stock){
            mayor_valor_en_stock = valor_en_stock;
            indice_mayor_valor_en_stock = i; 
        }
    }
    
    for(int i=0; i<3; i++){
        cout << "\nProducto numero " << i+1 << ":" << endl;
        cout << "   nombre: " << stock[i].nombre << endl;
        cout << "   precio: " << stock[i].precio << endl;
        cout << "   cantidad: " << stock[i].cantidad << endl;
    }

    cout << "\nProducto con mayior valor en stock: " << endl;
    cout << "   nombre: " << stock[indice_mayor_valor_en_stock].nombre << endl;
    cout << "   precio: " << stock[indice_mayor_valor_en_stock].precio << endl;
    cout << "   cantidad: " << stock[indice_mayor_valor_en_stock].cantidad << endl;
    cout << "   Valor en stock del producto: " << mayor_valor_en_stock << endl;

    return;
}

int main (){
    //ejercicio1();
    //ejercicio2();
    ejercicio3();
    return 0;
}