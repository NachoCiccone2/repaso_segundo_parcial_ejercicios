#include <iostream>
using namespace std;

/*  Ejercicio 1: Búsqueda Secuencial
    Crear un programa que:
    Permita al usuario ingresar 8 números enteros en un vector
    Permita buscar un número específico
    Informe si el número está presente y en qué posición
    Si no está, mostrar "Número no encontrado"
*/

void ingresar_ocho_numeros(int arr[]){
    for(int i=0;i<8;i++){
        cout << "\nIngrese el numero para la posicion " << i+1 << " :";
        cin >> arr[i];
    }
    cout << "\nCarga finalizada" << endl;
    return;
}

int busqueda_secuencial (int arr[], int len, int num){
    for(int i=0;i<len;i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}

void ejercicio1(){
    int arr[8];
    ingresar_ocho_numeros(arr);
    int num;
    cout<< "Ingrese numero a buscar: ";
    cin >> num;
    int pos = busqueda_secuencial(arr,8,num);

    if( pos == (-1)){
        cout << "\nEl numero no se encuentra en el array" << endl;
    } else {
        cout << "\nEl numero se encuentra en la posicion: " << pos << endl;
    }
    return;
}

/*  Ejercicio 2: Insertion Sort Básico
    Crear un programa que:
    Permita ingresar 6 notas de estudiantes (enteros del 1 al 10)
    Ordene las notas de menor a mayor usando Insertion Sort
    Muestre las notas antes y después del ordenamiento
*/

void mostrar_notas(int arr[], int len){
    cout << "Notas: [";
    for(int i=0;i<len;i++){
        if(i == len-1){
            cout << arr[i];
        } else {
            cout << arr[i] << ", ";
        }
    }
    cout << "]" << endl;
    /*for(int i=0;i<len;i++){
        cout << "Nota numero " << i+1 << " :" << arr[i] << endl;
    }*/
    return;
}

void ingresar_seis_notas(int arr[]){
    for(int i=0;i<6;i++){
        cout << "\nIngrese la nota del estudiante numero numero " << i+1 << " :";
        cin >> arr[i];
    }
    cout << "\nCarga finalizada" << endl;
    return;
}

void insertion_sort(int arr[], int len){
    for(int i=1;i<len;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && ( key < arr[j] )){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void ejercicio2(){
    int arr[6];
    ingresar_seis_notas(arr);
    cout << "\nNotas antes de ser ordenadas:" << endl;
    mostrar_notas(arr,6);
    insertion_sort(arr,6);
    cout << "\nNotas despues de ser ordenadas:" << endl;
    mostrar_notas(arr,6);
    return;
}

/*  Ejercicio 3: Burbujeo Simple
    Crear un programa que:
    Permita ingresar 7 temperaturas diarias (números decimales)
    Ordene las temperaturas de menor a mayor usando Burbujeo
    Muestre el resultado final
*/

/* Ejercicio 4: Sistema de Calificaciones
    Crear un programa que maneje un vector de 10 calificaciones:
    Usar Insertion Sort para ordenar las calificaciones
    Usar Búsqueda Binaria para verificar si una calificación específica existe
    Mostrar la calificación más alta y más baja
*/

/*  Ejercicio 5: Ventas Diarias (PUP)
    Crear un programa para registrar ventas diarias de una semana:
    Usar un vector de 7 posiciones (lunes=0, martes=1, etc.)
    Permitir cargar ventas por día de la semana
    Usar PUP para consultar la venta de un día específico
    Mostrar el total de ventas de la semana
*/

/*  Ejercicio 6: Inventario de Productos
    Crear un programa que maneje un inventario de 12 productos (stock):
    Usar Burbujeo Mejorado para ordenar por cantidad de stock
    Usar Búsqueda Secuencial para buscar productos con stock específico
    Identificar productos con stock bajo (menos de 10 unidades)
*/

int main (){
    //ejercicio1();
    ejercicio2();
    return 0;
}