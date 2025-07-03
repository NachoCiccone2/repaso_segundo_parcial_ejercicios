/* Ejercicio Biblioteca:
    Una biblioteca universitaria cuenta con personal bibliotecario distribuido en tres sedes diferentes. El sistema mantiene un registro completo de todos los préstamos realizados, organizando la información por código de bibliotecario.

    Código del bibliotecario
    Fecha del préstamo
    Material prestado (libro, revista, tesis)
    Valor de multa potencial (si se devuelve tarde)
    Puntos de evaluación obtenidos (por eficiencia en el servicio)

    Código de empleado
    Información personal (nombre y apellido)
    Sede de trabajo: 1=Central, 2=Ingeniería, 3=Medicina
    Categoría: A=Senior, B=Junior

    Información precargada en estructuras de datos estáticas
    Variables auxiliares indican cantidad de registros válidos
    Condición: todos los bibliotecarios registrados tienen al menos un préstamo procesado
    Bonificación: préstamos de material tipo "tesis" en sede Central otorgan 25% adicional en puntos de evaluación

    Desarrollo requerido:

    1) Diseñar las estructuras de datos necesarias para el manejo eficiente de la información.

    2) Implementar algoritmo de ordenamiento por selección para organizar bibliotecarios según sede de trabajo.

    3) Desarrollar búsqueda binaria que localice bibliotecarios por código y retorne su posición en el arreglo, considerando que los datos están ordenados por código de empleado.

    4) Implementar apareo para generar estructura que registre cada material prestado junto con la sede donde fue prestado (combinando información de préstamos y bibliotecarios).

    5) Generar reporte por sede mediante técnica de corte de control, mostrando: nombre de la sede, cantidad total de préstamos procesados, y el tipo de material más prestado en esa sede.
*/

#include <iostream>
using namespace std;

// 1) Diseñar las estructuras de datos necesarias para el manejo eficiente de la información.
struct Prestamo {
    int codigo_bibliotecario;
    int fecha_prestamo;
    string material_prestado;
    float valor_multa_potencial;
    int puntos;
};

struct Empleado {
    int codigo_empleado;
    string nombre_completo;
    int sede;
    char categoria;
};

void mostrar_prestamos(Prestamo prestamos[], int cant_prestamos){
    cout << "\nPrestamos: [";
    for(int i=0; i<cant_prestamos; i++){
        cout << "\n(codigo_bibliotecario  " << i+1 << " : " << prestamos[i].codigo_bibliotecario;
        cout << "; fecha : " << prestamos[i].fecha_prestamo;
        cout << "; material : " << prestamos[i].material_prestado;
        cout << "; multa_potencial : " << prestamos[i].valor_multa_potencial;
        if(i==cant_prestamos-1){
            cout << "; puntos :" << prestamos[i].puntos <<")\n]" << endl;
        } else {
            cout << "; puntos :" << prestamos[i].puntos <<"),";
        }
    }
    return;
}

void mostrar_empleados(Empleado empleados[], int cant_empleados){
    cout << "\nEmpleados: [";
    for(int i=0; i<cant_empleados; i++){
        cout << "\n     (codigo_empleado de empleado numero " << i+1 << " : " << empleados[i].codigo_empleado;
        cout << "; nombre_completo : " << empleados[i].nombre_completo;
        cout << "; sede : " << empleados[i].sede;
        if(i==cant_empleados-1){
            cout << "; categoria :" << empleados[i].categoria <<")\n]" << endl;
        } else {
            cout << "; categoria :" << empleados[i].categoria <<"),";
        }
    }
    return;
}

// 2) Implementar algoritmo de ordenamiento por selección para organizar bibliotecarios según sede de trabajo.
void ordenar_empleados_por_sede(Empleado empleados[], int cant_empleados){
    bool ordenado = false;
    for(int i=0; (i<cant_empleados && !ordenado); i++){
        ordenado = true;
        for(int j=0; j< cant_empleados-i-1; j++){
            if(empleados[j].sede > empleados[j+1].sede){
                Empleado aux = empleados[j];
                empleados[j] = empleados[j+1];
                empleados[j+1] = aux;
                ordenado = false;
            }
        }
    }
    return;
}

void ordenar_prestamos_por_codigo(Prestamo prestamos[], int cant_prestamos){
    bool ordenado = false;
    for(int i=0; (i<cant_prestamos && !ordenado); i++){
        ordenado = true;
        for(int j=0; j< cant_prestamos-i-1; j++){
            if(prestamos[j].codigo_bibliotecario > prestamos[j+1].codigo_bibliotecario){
                Prestamo aux = prestamos[j];
                prestamos[j] = prestamos[j+1];
                prestamos[j+1] = aux;
                ordenado = false;
            }
        }
    }
    return;
}

void ordenar_empleados_por_codigo(Empleado empleados[], int cant_empleados){
    bool ordenado = false;
    for(int i=0; (i<cant_empleados && !ordenado); i++){
        ordenado = true;
        for(int j=0; j< cant_empleados-i-1; j++){
            if(empleados[j].codigo_empleado > empleados[j+1].codigo_empleado){
                Empleado aux = empleados[j];
                empleados[j] = empleados[j+1];
                empleados[j+1] = aux;
                ordenado = false;
            }
        }
    }
    return;
}

// 3) Desarrollar búsqueda binaria que localice bibliotecarios por código y retorne su posición en el arreglo, considerando que los datos están ordenados por código de empleado.

int buscar_prestamo_por_codigo (Prestamo prestamos[], int cant_prestamos, int codigo){
    int ret = -1;
    int inicio=0, fin = cant_prestamos-1;

    while(fin >= inicio && ret==-1){
        int medio = inicio + (fin - inicio)/2;
        if(prestamos[medio].codigo_bibliotecario == codigo){
            ret = medio;
        } else if (codigo > prestamos[medio].codigo_bibliotecario){
            inicio = medio+1;
        } else {
            fin = medio-1;
        }
    }
    return ret;
}

int buscar_empleado_por_codigo (Empleado empleados[], int cant_empleados, int codigo){
    int ret = -1;
    int inicio=0, fin = cant_empleados-1;

    while(fin >= inicio && ret==-1){
        int medio = inicio + (fin - inicio)/2;
        if(empleados[medio].codigo_empleado == codigo){
            ret = medio;
        } else if (codigo > empleados[medio].codigo_empleado){
            inicio = medio+1;
        } else {
            fin = medio-1;
        }
    }
    return ret;
}

// 4) Implementar apareo para generar estructura que registre cada material prestado junto con la sede donde fue prestado (combinando información de préstamos y bibliotecarios).
struct PrestamoConSede{
    int codigo_bibliotecario;
    int fecha_prestamo;
    string material_prestado;
    float valor_multa_potencial;
    int puntos;
    int sede;
};

void mostrar_prestamos_con_sede(PrestamoConSede prestamos_con_sede[], int cant_prestamos_con_sede){
    cout << "\nPrestamos con sede: [";
    for(int i=0; i<cant_prestamos_con_sede; i++){
        cout << "\n(codigo_bibliotecario  " << i+1 << " : " << prestamos_con_sede[i].codigo_bibliotecario;
        cout << "; fecha : " << prestamos_con_sede[i].fecha_prestamo;
        cout << "; material : " << prestamos_con_sede[i].material_prestado;
        cout << "; multa_potencial : " << prestamos_con_sede[i].valor_multa_potencial;
        cout << "; puntos : " << prestamos_con_sede[i].puntos;
        if(i==cant_prestamos_con_sede-1){
            cout << "; sede :" << prestamos_con_sede[i].sede <<")\n]" << endl;
        } else {
            cout << "; sede :" << prestamos_con_sede[i].sede <<"),";
        }
    }
    return;
}

// Asumo que empleado = bibliotecario.
int generar_registro_de_prestamo_con_sede(Prestamo prestamos[], int cant_prestamos, Empleado empleados[], int cant_empleados, PrestamoConSede prestamos_con_sede []){
    for(int i=0; i< cant_prestamos; i++){
        // para sacar la sede tengo que cruzar la info del codigo del bibliotecario del prestamo con el codigo del empleado y obtener su sede.
        int indice = buscar_empleado_por_codigo(empleados, cant_empleados, prestamos[i].codigo_bibliotecario);
        prestamos_con_sede[i].codigo_bibliotecario = prestamos[i].codigo_bibliotecario;
        prestamos_con_sede[i].fecha_prestamo = prestamos[i].fecha_prestamo;
        prestamos_con_sede[i].material_prestado = prestamos[i].material_prestado;
        prestamos_con_sede[i].valor_multa_potencial = prestamos[i].valor_multa_potencial;
        prestamos_con_sede[i].puntos = prestamos[i].puntos;
        prestamos_con_sede[i].sede = empleados[indice].sede;
    }
    return cant_prestamos;
}
// opcion sin usar "buscar_empleado_por_codigo"
// requiere "empleados" y "prestamos" ordenados por codigo
int generar_registro_de_prestamo_con_sede2(Prestamo prestamos[], int cant_prestamos, Empleado empleados[], int cant_empleados, PrestamoConSede prestamos_con_sede []){
    int j=0;
    for(int i=0; i< cant_empleados; i++){
        int key = empleados[i].codigo_empleado;

        while(key == prestamos[j].codigo_bibliotecario && j<cant_prestamos){
            prestamos_con_sede[j].codigo_bibliotecario = prestamos[j].codigo_bibliotecario;
            prestamos_con_sede[j].fecha_prestamo = prestamos[j].fecha_prestamo;
            prestamos_con_sede[j].material_prestado = prestamos[j].material_prestado;
            prestamos_con_sede[j].valor_multa_potencial = prestamos[j].valor_multa_potencial;
            prestamos_con_sede[j].puntos = prestamos[j].puntos;
            prestamos_con_sede[j].sede = empleados[i].sede;
            j++;
        }
    }
    return cant_prestamos;
}

// 5) Generar reporte por sede mediante técnica de corte de control, mostrando: nombre de la sede, cantidad total de préstamos procesados, y el tipo de material más prestado en esa sede.
void ordenar_prestamos_con_sede_por_sede(PrestamoConSede prestamos_con_sede[], int cant_prestamos_con_sede){
    bool ordenado = false;
    for(int i=0; (i<cant_prestamos_con_sede && !ordenado); i++){
        ordenado = true;
        for(int j=0; j< cant_prestamos_con_sede-i-1; j++){
            if(prestamos_con_sede[j].sede > prestamos_con_sede[j+1].sede){
                PrestamoConSede aux = prestamos_con_sede[j];
                prestamos_con_sede[j] = prestamos_con_sede[j+1];
                prestamos_con_sede[j+1] = aux;
                ordenado = false;
            }
        }
    }
    return;
}

string nombre_sede(int num_sede){
    string nombre="No hay sede con ese numero";
    switch (num_sede){
    case 1:
        nombre = "Central";
        break;
    
    case 2:
        nombre = "Ingenieria";
        break;

    case 3:
        nombre = "Medicina";
        break;

    default:
        break;
    }
    return nombre;
}

string material_mas_prestado (int libros, int revistas, int tesis, int &cant){
    string ret = "Ninguno";
    if(libros > revistas && libros > tesis){
        cant = libros;
        ret = "libro";
    } else if (revistas > libros && revistas > tesis){
        cant = revistas;
        ret = "revista";
    } else {
        cant = tesis;
        ret = "tesis";
    }
    return ret;
}
// para que funcione correctamente, los prestamos con sede deben estar oredenados por sede.
void reporte_por_sede (PrestamoConSede prestamos_con_sede [], int cant_prestamos_con_sede){
    int i=0;
    while(i<cant_prestamos_con_sede){
        int cant_prestamos = 0;
        int cant_libros=0;
        int cant_revistas=0;
        int cant_tesis=0;
        int key = prestamos_con_sede[i].sede;

        while(prestamos_con_sede[i].sede == key && i<cant_prestamos_con_sede){
            if(prestamos_con_sede[i].material_prestado == "Libro"){
                cant_libros++;
            } else if(prestamos_con_sede[i].material_prestado == "Revista"){
                cant_revistas++;
            } else {
                cant_tesis++;
            }
            cant_prestamos ++;
            i++;
        }

        int cantidad_material_mas_prestado;
        string material = material_mas_prestado(cant_libros,cant_revistas,cant_tesis,cantidad_material_mas_prestado);
        
        cout << "\nSede " << nombre_sede(key) << ": " << endl;
        cout << "   Cantidad de prestamos de la sede: " << cant_prestamos << endl;
        if(material == "tesis"){
            cout << "   Material mas prestado en la sede: " << material << " con " << cantidad_material_mas_prestado << " de " << material << "."<<endl;
        } else {
            cout << "   Material mas prestado en la sede: " << material << " con " << cantidad_material_mas_prestado << " de " << material << "s."<<endl;
        }
    }

    return;
}

const int MAX_PRESTAMOS = 50;
const int MAX_EMPLEADOS = 50;

Prestamo prestamos[]={
    {1, 15032024, "Libro", 150.0, 450},
    {1, 16032024, "Revista", 250.0, 750},
    {1, 18032024, "Tesis", 300.0, 900},
    {3, 17032024, "Libro", 180.0, 540},
    {3, 20032024, "Libro", 220.0, 660},
    {5, 19032024, "Revista", 120.0, 360},
    {5, 21032024, "Tesis", 160.0, 480},
    {7, 23032024, "Revista", 350.0, 1050},
    {7, 25032024, "Revista", 400.0, 1200},
    {9, 26032024, "Libro", 80.0, 240},
    {9, 28032024, "Tesis", 450.0, 1350},
    {10, 28032024, "Tesis", 280.0, 840},
    {11, 28032024, "Libro", 180.0, 540},
    {11, 28032024, "Tesis", 350.0, 1050},
    {12, 22032024, "Libro", 280.0, 840}
};
const int cant_prestamos = 15;

Empleado empleados[]={
    {1, "Juan Perez", 1, 'A'},
    {3, "Ana Lopez", 1, 'A'},
    {5, "Carlos Ruiz", 3, 'B'},
    {7, "Maria Garcia", 2, 'B'},
    {9, "Luis Martinez", 1, 'A'},
    {10, "Nombre1 Apellido1", 3, 'B'},
    {11, "Nombre2 Apellido2", 1, 'A'},
    {12, "Nombre3 Apellido3", 2, 'A'}
};
const int cant_empleados = 8;
int main(){
    cout << "--- Inicio de Pruebas ---" << endl;
    
    cout << "\nLista de empleados sin ordenar: " << endl;
    mostrar_empleados(empleados, cant_empleados);
    ordenar_empleados_por_sede(empleados, cant_empleados);
    cout << "\nLista de empleados ordenada por sede: " << endl;
    mostrar_empleados(empleados, cant_empleados);

    cout << "\n Busco prestamos de codigos 0 a 12:\n" << endl;
    int indice;
    for(int y = 0; y<13; y++){
        indice = buscar_prestamo_por_codigo (prestamos, cant_prestamos, y);
        if (indice != -1) {
            cout << "   prestamo de codigo " << y <<  " encontrada en indice " << indice << ". fecha_prestamo: " << prestamos[indice].fecha_prestamo << endl;
        } else {
            cout << "   prestamos de indice " << y << " no encontrado." << endl;
        }
    }
    
    ordenar_empleados_por_codigo(empleados, cant_empleados);
    //mostrar_empleados(empleados, cant_empleados);
    cout << "\n Busco empleados de codigos 0 a 12:\n" << endl;
    for(int y = 0; y<13; y++){
        indice = buscar_empleado_por_codigo (empleados, cant_empleados, y);
        if (indice != -1) {
            cout << "   empleado de codigo " << y <<  " encontrada en indice " << indice << ". nombre_completo: " << empleados[indice].nombre_completo << endl;
        } else {
            cout << "   empleado de indice " << y << " no encontrado." << endl;
        }
    }
    
    PrestamoConSede prestamos_con_sede[MAX_PRESTAMOS];
    int cantPrestamosConSede = generar_registro_de_prestamo_con_sede2(prestamos, cant_prestamos, empleados, cant_empleados, prestamos_con_sede);
    mostrar_prestamos_con_sede(prestamos_con_sede, cantPrestamosConSede);

    ordenar_prestamos_con_sede_por_sede(prestamos_con_sede, cantPrestamosConSede);
    reporte_por_sede(prestamos_con_sede, cantPrestamosConSede);
    return 0;
}