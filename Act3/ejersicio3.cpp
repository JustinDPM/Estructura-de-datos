#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void imprimir_vector(vector<int> vector)
{
    cout << "vector: "; 
    for (int n : vector)
    {
        cout << n << " ";
    }
    cout << endl;
}

int main () {

    cout << "-- Algoritmos --" <<endl; 
    
    vector<int> datos = {9, 3, 5, 10, 8, 4};
    imprimir_vector(datos);
    
    sort(datos.begin(), datos.end());
    imprimir_vector(datos);

    cout << "Maximo: "<< *max_element(datos.begin() , datos.end()) << endl;
    cout << "Minimo: " << *min_element(datos.begin() , datos.end()) << endl;

    //Invertir un vector
    reverse(datos.begin() , datos.end());
    imprimir_vector(datos);

    return 0;
}