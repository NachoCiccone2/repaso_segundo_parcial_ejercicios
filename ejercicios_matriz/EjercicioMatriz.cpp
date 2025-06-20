/*  Ejercicio 1: Suma de diagonal
    Crea un programa que tenga una matriz cuadrada de 3x3, calcule la suma de la diagonal principal.
*/  
    
/*  Ejercicio 2: Transponer una matriz
    Haz un programa que tome una matriz de 2x3, cree su transpuesta (3x2) y muestre ambas matrices.
*/

/*  Ejercicio 3: Suma de filas y columnas
    Escribe un programa que calcule la suma de cada fila y cada columna de una matriz de 3x4, y muestre los resultados.
*/

#include <iostream>

using namespace std;

const int MATRIZ3X3[3][3]= { {1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9} };

const int MATRIZ2X3[2][3]= { {1, 2, 3},
                             {4, 5, 6} };

const int MATRIZ3X4[3][4]= { {1, 2, 3, 4}, 
                             {5, 6, 7, 8}, 
                             {9, 10, 11, 12} };

void ejercicio1(){
    int suma = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==j){
                suma += MATRIZ3X3[i][j];
            }
        }
    }
    cout << "Suma = " << suma << endl;

    return;
}

void ejercicio2(){
    int matrix3x2[3][2];

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            matrix3x2[j][i] = MATRIZ2X3[i][j];
        }
    }

    cout << "matrix2x3:"<< endl;
    for(int i=0; i<2; i++){
        cout << "[";
        for(int j=0; j<3; j++){
            cout << " " << MATRIZ2X3[i][j]<< " "; 
        }
        cout << "]" << endl;
    }

    cout << "matrix3x2:"<< endl;
    for(int i=0; i<3; i++){
        cout << "[";
        for(int j=0; j<2; j++){
            cout << " " << matrix3x2[i][j]<< " "; 
        }
        cout << "]" << endl;
    }
    return;
}

void ejercicio3(){
    int suma_fila[3] = {0,0,0}, suma_columma[4] = {0,0,0,0};

    cout << "matrix3x4:"<< endl;
    for(int i=0; i<3; i++){
        cout << "[";
        for(int j=0; j<4; j++){
            cout << " " << MATRIZ3X4[i][j]<< " "; 
        }
        cout << "]" << endl;
    }
    cout << endl;
    //i = filas, j = por columna
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            suma_fila[i] += MATRIZ3X4[i][j];
            suma_columma[j] += MATRIZ3X4[i][j];
        }
    }

    for(int i = 0; i<3; i++){
        cout << "suma fila numero " << i+1 << " : " << suma_fila[i] << endl;
    }
    cout << endl;
    for(int i = 0; i<4; i++){
        cout << "suma columna numero " << i+1 << " : " << suma_columma[i] << endl;
    }

    return;
}

int main(){
    //ejercicio1();
    //ejercicio2();
    //ejercicio3();
    return 0;
}