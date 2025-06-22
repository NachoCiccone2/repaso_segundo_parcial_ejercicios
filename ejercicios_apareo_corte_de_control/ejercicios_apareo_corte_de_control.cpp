#include<iostream>

using namespace std;

/*  Ejercicio 1: Apareo de Vectores
    Enunciado: Dados dos vectores de números enteros ya ordenados de menor a mayor, implementar una función que los combine en un tercer vector manteniendo el orden.
    Datos de prueba:
    Vector A: {1, 4, 8, 12}
    Vector B: {2, 5, 6, 10, 15}
    Resultado esperado: {1, 2, 4, 5, 6, 8, 10, 12, 15}
*/

void imprimir_vector(int arr[], int len){
    cout << " [";
    for(int i=0;i<len;i++){
        if(i == len-1){
            cout << arr[i];    
        } else {
            cout << arr[i]  << ", ";
        }
    }
    cout << "]" << endl;
}

int apareo_vectores(int arr_a[], int len_a, int arr_b[], int len_b, int arr_c[]){
    int i=0,j=0,k=0;
    int len_c;

    while(i<len_a && j<len_b){
        if(arr_a[i] < arr_b[j]){
            arr_c[k] = arr_a[i];
            i++;
        } else {
            arr_c[k] = arr_b[j];
            j++;
        }
        k++;
    }

    while(i<len_a){
        arr_c[k] = arr_a[i];
        i++;
        k++;
    }

    while(j<len_b){
        arr_c[k] = arr_b[j];
        j++;
        k++;
    }

    len_c = k;
    
    return len_c;
}

void ejercicio1(){
    int a[] = {1, 4, 8, 12}, b[] = {2, 5, 6, 10, 15}, c[10];
    int len_a = 4, len_b = 5, len_c;
    cout << "\nVector A: ";
    imprimir_vector(a, len_a);
    cout << "\nVector B: ";
    imprimir_vector(b, len_b);
    len_c =  apareo_vectores(a, len_a, b, len_b, c);
    cout << "\nVector C: ";
    imprimir_vector(c, len_c);
    return;
}

/*  Ejercicio 2: Corte de Control Simple
    Enunciado: Una librería tiene registros de ventas ordenados por vendedor. Crear un programa que muestre cuántos libros vendió cada vendedor en total.
    Estructura de datos:
    struct Venta {
        int codigoVendedor;
        int cantidadLibros;
    };
    Datos de prueba (ya ordenados por vendedor):
    Vendedor 101: vendió 5 libros
    Vendedor 101: vendió 3 libros  
    Vendedor 102: vendió 7 libros
    Vendedor 102: vendió 2 libros
    Vendedor 102: vendió 4 libros
    Vendedor 103: vendió 6 libros
    Resultado esperado:
    Vendedor 101: 8 libros totales
    Vendedor 102: 13 libros totales  
    Vendedor 103: 6 libros totales
*/

struct Venta {
    int codigoVendedor;
    int cantidadLibros;
};

const int CANT_VENTAS = 10;

void mostrar_ventas (Venta arr[], int len){
    cout << "ventas[";
    for(int i=0; i<len; i++){
        cout << "\n     {codigo_vendedor: " << arr[i].codigoVendedor << ", cantidad_libros: " << arr[i].cantidadLibros  << "}, ";
    }
    cout << "\n]" << endl;
    return;
}

void cargar_datos(Venta arr[], int len){
    for(int i=0; i<len; i++){
        cout << "\nIngrese el codigo del vendedor: ";
        cin >> arr[i].codigoVendedor;
        cout << "\nIngrese la cantidad de libros vendidos: ";
        cin >> arr[i].cantidadLibros;
    }
    cout << "\nCarga completa." << endl;
}

void ventas_por_vendedor(Venta arr[], int len){
    int key = arr[0].codigoVendedor;
    int cant_ventas=0;
    for(int i=0; i<len; i++){
        if(arr[i].codigoVendedor != key){
            cout << "\nEl vendedor " << arr[i-1].codigoVendedor << " vendio " << cant_ventas << " libros." << endl;
            key = arr[i].codigoVendedor;
            cant_ventas = 0;
        }
        cant_ventas += arr[i].cantidadLibros;
    }
    cout << "\nEl vendedor " << arr[len-1].codigoVendedor << " vendio " << cant_ventas << " libros." << endl;
}

void ejercicio2(){
    Venta ventas[CANT_VENTAS];
    cargar_datos(ventas, CANT_VENTAS);
    mostrar_ventas(ventas, CANT_VENTAS);
    cout << "\n\n\n";
    ventas_por_vendedor(ventas, CANT_VENTAS);
    return;
}

/*  Ejercicio 3: Corte de Control Múltiple
    Enunciado: Una escuela tiene registros de notas ordenados por curso y luego por alumno. Crear un programa que calcule el promedio de notas de cada alumno en cada curso.
    Estructura de datos:
    struct Nota {
        string curso;
        int legajo;
        int nota;
    };
    Datos de prueba (ya ordenados por curso, luego por legajo):
    Curso "1A", Legajo 123: nota 8
    Curso "1A", Legajo 123: nota 7
    Curso "1A", Legajo 456: nota 9
    Curso "1B", Legajo 234: nota 6
    Curso "1B", Legajo 789: nota 8
    Curso "1B", Legajo 789: nota 10
    Resultado esperado:
    Curso 1A:
    Legajo 123: Promedio 7.5
    Legajo 456: Promedio 9.0
    Curso 1B:  
    Legajo 234: Promedio 6.0
    Legajo 789: Promedio 9.0
*/

struct Nota {
    string curso;
    int legajo;
    int nota;
};

const int CANT_NOTAS = 10;

void mostrar_notas (Nota arr[], int len){
    cout << "\nnotas[";
    for(int i=0; i<len; i++){
        cout << "\n     {curso: " << arr[i].curso << ", legajo: " << arr[i].legajo << ", nota: " << arr[i].nota  << "}, ";
    }
    cout << "\n]" << endl;
    return;
}

void cargar_notas(Nota arr[], int len){
    for(int i=0; i<len; i++){
        cout << "\nIngrese el nombre del curso: ";
        cin >> arr[i].curso;
        cout << "\nIngrese el numero de legajo: ";
        cin >> arr[i].legajo;
        cout << "\nIngrese la nota correspondiente: ";
        cin >> arr[i].nota;
    }
    cout << "\nCarga completa.\n" << endl;
}

void reset_params(int &suma_notas, int &cant_notas, string &key_curso, int &key_legajo, Nota arr[], int index){
    float promedio= (float)suma_notas/(float)cant_notas;
    cout << "Legajo " << arr[index-1].legajo << ": Promedio: " << promedio << endl;
    suma_notas = 0;
    cant_notas = 0;
    key_curso = arr[index].curso;
    key_legajo = arr[index].legajo;
    return;
}

void notas_por_curso_por_alumno(Nota arr[], int len){
    string key_curso = arr[0].curso;
    int key_legajo = arr[0].legajo;
    int suma_notas = 0;
    int cant_notas=0;

    cout << "\nCurso " << key_curso << ":" << endl;
    for(int i=0; i<len; i++){
        if(key_curso != arr[i].curso){
            reset_params(suma_notas, cant_notas, key_curso, key_legajo, arr, i);
            cout << "Curso " << key_curso << ":" << endl;
        }
        if(key_legajo != arr[i].legajo){
            reset_params(suma_notas, cant_notas, key_curso, key_legajo, arr, i);
        }
        suma_notas += arr[i].nota;
        cant_notas++;
    }
    reset_params(suma_notas, cant_notas, key_curso, key_legajo, arr, len);
    return;
}

void ejercicio3(){
    Nota notas[CANT_NOTAS];
    cargar_notas(notas, CANT_NOTAS);
    mostrar_notas(notas, CANT_NOTAS);
    notas_por_curso_por_alumno(notas, CANT_NOTAS);
    return;
}

int main (){
    //ejercicio1();
    //ejercicio2();
    ejercicio3();
    return 0;
}