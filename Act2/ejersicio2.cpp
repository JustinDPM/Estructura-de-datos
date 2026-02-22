#include <iostream>
#include <vector>

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

int main() {

    cout << "--- Crreacion de vectores ---" << endl;
    
    vector<int> v1;

    //vector con tamaño definido
    vector<int> v2 [5];
    
    //vector con tamaño y valor inicial
    vector<int> v3 (5, 10);
    
    //vector con valores iniciales
    vector<int> v4 = {1, 2, 3, 4, 5};

    //Copiar vectores
    vector<int> copia = v4;

    //Imprimir vector
    cout << "vector v4: " ;
    imprimir_vector(v4);

    cout <<endl  << endl << "------ Acceder a elementos de un vectos ------" << endl;

    cout << "Acceder a posicion 2 del vector v4: " << v4[2] << endl;
    cout << "primer elemento del vector v4: " << v4.front() << endl;
    cout << "ultimo elemento del vector v4: " << v4.back() << endl;

    cout << endl << "------ Modificar elementos de un vector -----" << endl;

    v4[0] = 100;

    //agregar valor al final
    v4.push_back(50); 
    imprimir_vector(v4);

    //agregar valor en posicion especifica
    v4.insert(v4.begin() + 2, 99);
    imprimir_vector(v4);

    //insertar varios valores
    v4.insert(v4.begin() + 1, 3 ,10);
    imprimir_vector(v4);

    //Borrar un elemento
    v4.erase(v4.begin() + 1);
    imprimir_vector(v4);

    //Eliminar por rango
    v4.erase(v4.begin() + 1 , v4.begin() + 3);
    imprimir_vector(v4);

    cout << "vector v4: " ;
    imprimir_vector(v4);

    cout << endl << endl <<"--- Obtener informacion del vector -----" << endl;
    cout << "size: " << v4.size() << endl;
    cout << "capacity: " << v4.capacity() << endl;
    cout << "vector vacio?: " << (v4.empty() ? "Si" : "No")<< endl;

    cout << endl << "----- Control de memoria ------" << endl;
    v4.reserve(100);
    cout << "capacity: " << v4.capacity() << endl;

    v4.resize(15, 5);
    cout << "capacity: " << v4.capacity() << endl;
    imprimir_vector(v4);

    return 0;
}