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

void mostrar_temps(float arr[], int len){
    cout << "Temperaturas: [";
    for(int i=0;i<len;i++){
        if(i == len-1){
            cout << arr[i];
        } else {
            cout << arr[i] << ", ";
        }
    }
    cout << "]" << endl;
    return;
}

void ingresar_siete_temperaturas(float arr[]){
    for(int i=0;i<7;i++){
        cout << "\nIngrese la nota del temperatura del dia " << i+1 << " :";
        cin >> arr[i];
    }
    cout << "\nCarga finalizada" << endl;
    return;
}

void burbujeo_simple (float arr[], int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j] > arr[j+1]){
                float aux = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void ejercicio3(){
    float arr[7];
    ingresar_siete_temperaturas(arr);
    cout << "\nTemperaturas antes de ser ordenadas:" << endl;
    mostrar_temps(arr,7);
    burbujeo_simple(arr,7);
    cout << "\nTemperaturas despues de ser ordenadas:" << endl;
    mostrar_temps(arr,7);
    return;
}

/* Ejercicio 4: Sistema de Calificaciones
    Crear un programa que maneje un vector de 10 calificaciones:
    Usar Insertion Sort para ordenar las calificaciones
    Usar Búsqueda Binaria para verificar si una calificación específica existe
    Mostrar la calificación más alta y más baja
*/

void mostrar_calificaciones(int arr[], int len){
    cout << "Calificaciones: [";
    for(int i=0;i<len;i++){
        if(i == len-1){
            cout << arr[i];
        } else {
            cout << arr[i] << ", ";
        }
    }
    cout << "]" << endl;
    return;
}

void ingresar_diez_calificaciones(int arr[]){
    for(int i=0;i<10;i++){
        cout << "\nIngrese la nota del alumno numero " << i+1 << " :";
        cin >> arr[i];
    }
    cout << "\nCarga finalizada" << endl;
    return;
}

int busqueda_binaria (int arr[], int len, int num){
    int inicio = 0, fin = len-1;
    int ret = -1;
    while(fin >= inicio && ret == -1){
        int medio = inicio + (fin-inicio)/2;

        if(num == arr[medio]){
            ret = medio;
        } else if(num > arr[medio]){
            inicio = medio+1;
        } else {
            fin = medio-1;
        }
    }

    return ret;
}

void ejercicio4(){
    int arr[10];
    ingresar_diez_calificaciones(arr);
    cout << "\nCalificaciones antes de ser ordenadas:" << endl;
    mostrar_calificaciones(arr,10);
    insertion_sort(arr,10);
    cout << "\nCalificaciones despues de ser ordenadas:" << endl;
    mostrar_calificaciones(arr,10);
    cout << "Ingrese un numero para chequear si esta en el array: ";
    int num;
    cin >> num;

    if(busqueda_binaria(arr,10,num) == -1){
        cout << "\nEl numero no se encuentra en el array" << endl;
    } else {
        cout << "\nEl numero se encuentra en el array" << endl;
    }

    cout << "La calificacion mas alta es " << arr[9] << " y la mas baja es " << arr[0] << "." << endl;
    return;
}

/*  Ejercicio 5: Ventas Diarias (PUP)
    Crear un programa para registrar ventas diarias de una semana:
    Usar un vector de 7 posiciones (lunes=0, martes=1, etc.)
    Permitir cargar ventas por día de la semana
    Usar PUP para consultar la venta de un día específico
    Mostrar el total de ventas de la semana
*/

string num_a_dia (int i){
    string dia;
    switch(i){
        case 0:
            dia = "lunes";
            break; 
        case 1:
            dia = "martes";
            break; 
        case 2:
            dia = "miercoles";
            break;
        case 3:
            dia = "jueves";
            break;
        case 4:
            dia = "viernes";
            break;
        case 5:
            dia = "sabado";
            break;
        case 6:
            dia = "domingo";
            break;
    }
    return dia;
}

void mostrar_ventas(int arr[], int len){
    cout << "Ventas: [";
    for(int i=0;i<len;i++){
        if(i == len-1){
            cout << arr[i];
        } else {
            cout << arr[i] << ", ";
        }
    }
    cout << "]" << endl;
    return;
}

void ingresar_ventas_semanales(int arr[]){
    for(int i=0;i<7;i++){
        cout << "\nIngrese las ventas del dia " << num_a_dia(i) << " :";
        cin >> arr[i];
    }
    cout << "\nCarga finalizada" << endl;
    return;
}

void consultar_venta(int arr[]){
    int dia_consulta;
    cout << "Ingrese el día de la venta que quiere consultar: ";
    cin >> dia_consulta;
    cout << "\nLas ventas del dia " << num_a_dia(dia_consulta) << " es de: " << arr[dia_consulta] << endl;
}

int total_ventas_semana(int arr[]){
    int sum=0;
    for(int i=0;i<7;i++){
        sum+=arr[i];
    }
    return sum;
}

void ejercicio5(){
    int ventas[7];
    ingresar_ventas_semanales(ventas);
    mostrar_ventas(ventas,7);
    consultar_venta(ventas);
    cout << "Total de ventas semanal: " << total_ventas_semana(ventas) << endl;
    return;
}

/*  Ejercicio 6: Inventario de Productos
    Crear un programa que maneje un inventario de 12 productos (stock):
    Usar Burbujeo Mejorado para ordenar por cantidad de stock
    Usar Búsqueda Secuencial para buscar productos con stock específico
    Identificar productos con stock bajo (menos de 10 unidades)
*/

struct Producto{
    string nombre;
    int precio;
    int stock;
};

void mostrar_productos (Producto arr[], int len){
    for(int i=0; i<len; i++){
        cout << "\n\nNombre del producto numero " << i+1 << " : " << arr[i].nombre;
        cout << "\nPrecio : " << arr[i].precio;
        cout << "\nStock :" << arr[i].stock;
    }
}

void burbujeo_mejorado (Producto arr[], int len){
    bool ordenado = false;
    int i = 0;
    while( i<len && !ordenado){
        ordenado = true;
        for(int j=0;j<len-i-1;j++){
            if(arr[j].stock > arr[j+1].stock){
                Producto aux = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void carga_productos(Producto productos[], int len){
    for(int i=0;i<len;i++){
        cout << "\nIngrese el nombre del producto numero " << i+1 << " :";
        cin >> productos[i].nombre;
        cout << "\nIndique su precio :";
        cin >> productos[i].precio;
        cout << "\nIndique el stock del producto :";
        cin >> productos[i].stock;
    }
    cout << "\nCarga finalizada" << endl;
    return;
}

int busqueda_secuencial(Producto productos[], int len, string nombre){
    for(int i=0; i<len;i++){
        if(productos[i].nombre == nombre){
            return i;
        }
    }
    return -1;
}

void busqueda_producto(Producto productos[], int len){
    cout << "\nIngrese el nombre del producto que desea buscar: ";
    string nombre_a_buscar;
    cin >> nombre_a_buscar;
    int index = busqueda_secuencial(productos,len,nombre_a_buscar);
    if(index == -1){
        cout << "\nEl producto no se encuentra en stock." << endl;
    } else {
        cout << "\nDel producto " << productos[index].nombre << " hay " << productos[index].stock << " unidades en stock." << endl;
    }
}

void productos_bajo_stock (Producto productos[], int len){
    cout << "\nBuscando productos con bajo stock..." << endl;
    for(int i=0; i< len; i++){
        if(productos[0].stock > 10){
            cout << "No hay productos con bajo stock." << endl;
            i = len;
        } else {
            if(productos[i].stock < 10){
                cout << "El producto " << productos[i].nombre << " tiene bajo stock (" << productos[i].stock << ")" << endl;
            } else {
                i = len;
            }
        }
    }
}

void ejercicio6(){
    Producto productos[12];
    carga_productos(productos,12);
    cout << "\nProductos antes de ser ordenados:" << endl;
    mostrar_productos(productos,12);
    burbujeo_mejorado(productos,12);
    cout << "\nProductos despues de ser ordenados:" << endl;
    mostrar_productos(productos,12);
    busqueda_producto(productos,12);
    productos_bajo_stock(productos,12);
    return;
}

int main (){
    //ejercicio1();
    //ejercicio2();
    //ejercicio3();
    //ejercicio4();
    //ejercicio5();
    ejercicio6();
    return 0;
}