#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

vector<float> nro_al(int n) { //funcion para crear numeros aleatorios
    vector<float> result;
    for (int i = 0; i < n; i++) {
        result.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
    }
    return result;
}

float euclidiana1(float x, float y) { //funcion para ir sumando el cuadrado del resultado de restar cada dimension
    float result;
    result = pow(x - y, 2);
    return result;
}

float euclidiana2(vector<vector<float>> nros, int x, int y, int dim) { //funcion principal de la distancia euclidiana
    float res = 0;
    float result = 0;
    for (int i = 0; i < dim; i++) {
        res = res + euclidiana1(nros[x][i], nros[y][i]);
    }
    result = sqrt(res);
    return result;
}

void escribir(float x) { //funcion para escribir en un archivo de texto todas las distancias
    ofstream archivo;
    
    //archivo.open("dim1.txt", ios::app); //dim = 10
    //archivo.open("dim2.txt", ios::app); //dim = 50
    //archivo.open("dim3.txt", ios::app); //dim = 100
    //archivo.open("dim4.txt", ios::app); //dim = 500
    //archivo.open("dim5.txt", ios::app); //dim = 1000
    //archivo.open("dim6.txt", ios::app); //dim = 2000
    archivo.open("dim7.txt", ios::app); //dim = 5000

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    archivo << x << " ";
    archivo.close();
}

int main() {
    srand(time(0));
    int dim = 5000; //numero de dimensiones
    vector<vector<float>> vec_nros; //elementos con n-dimensiones
    for (int i = 0; i < 100; i++) {
        vec_nros.push_back(nro_al(dim));
    }

    float x; //el resultado de cada distancia euclidiana

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            x = euclidiana2(vec_nros, i, j, dim);
            escribir(x);
        }
    }

    return 0;
}