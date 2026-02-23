#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Alumno {

    int matricula;
    string nombre;
    double promedio;

};

int buscarAlumno(vector<Alumno> grupo, int matricula){
    
    for(int i = 0; i < grupo.size(); i++){

        if(matricula == grupo[i].matricula) {
            
            return i; //devuelve el indice del alumno
            break;

        }
      }

    return -1;
}

bool agregarAlumno(vector<Alumno>& grupo, const Alumno& alumno) {

    if (buscarAlumno(grupo, alumno.matricula) != -1) // ya existe un alumno con esa matricula
    {
        
        return false;
        
    }

    grupo.push_back(alumno);
    return true;
}

void mostrarAlumnos(vector<Alumno>& grupo) {

    if (grupo.empty()) {
        cout << "Grupo vacio" << endl;
    }
    else {
        cout << "=====Listado de alumnos=====" << endl;
        cout << left << setw(12) << "Matricula"
            << setw(20) << "Nombre"
            << setw(12) << "Promedio" << endl;
        for(Alumno a : grupo){

            cout << left << setw(12) << a.matricula
            << setw(20) << a.nombre
            << setw(12) << a.promedio << endl;
        
        }
    }
}

int calcularPromedio(vector<Alumno>& grupo){
    double promedio = 0;
    if (grupo.empty()) {
        return -1;
    }
    for(const Alumno& a : grupo){

        promedio += a.promedio;
            
    }
    return promedio / grupo.size();
    
}

void actualizarAlumno (vector<Alumno>& grupo, int matricula, string nombre, double promedio){
    int index = buscarAlumno(grupo, matricula);
    if( index != -1){
        grupo[index].nombre = nombre;
        grupo[index].promedio = promedio;
        
    } 
}

int main(){

    vector<Alumno> grupo;
    Alumno temp_alumno;

    int opcion;
    int matricula;
    int index;
    int promedio;
  
    do
    {
        cout << "\n====================================\n";
        cout << "Menu - vector<Alumno>";
        cout << "\n====================================\n";
        cout << "1) Agregar alumno" <<endl; //listo
        cout << "2) Mostrar alumnos" <<endl; //listo
        cout << "3) Buscar alumno por matricula" <<endl; //listo
        cout << "4) Actualizar alumno" <<endl;
        cout << "5) Eliminar alumno" <<endl; //listo
        cout << "6) Ordenar por promedio (desc)" <<endl;
        cout << "7) Ordenar por promedio (asc)" <<endl;
        cout << "8) Calcular promedio del grupo)" <<endl; //listo
        cout << "0) Salir"<<endl; //listo
        cout << "Opcion: ";
        cin>>opcion;

        switch (opcion)
        {
        case 1: 
            
            cout << "Agregar alumno" <<endl;
            cout << "Ingresa matricula: ";
            cin >> temp_alumno.matricula;
            cin.ignore(); //Limpiar buffer

            cout << "Ingresa nombre: ";
            getline(cin, temp_alumno.nombre);

            cout << "Ingresa promedio: ";
            cin >> temp_alumno.promedio;

            if (agregarAlumno(grupo, temp_alumno)) {
                cout << "Alumno agregado" << endl;
            } else {
                cout << "ERROR";
            }

            break;
        case 2:
            cout << "Mostrar alumnos" <<endl;
            mostrarAlumnos(grupo);
            break;
        case 3: 
            cout << "Buscar alumno por matricula" <<endl;
            cout << "Ingrese matricula: ";
            cin >> matricula;
            index = buscarAlumno(grupo, matricula);
            if (index != -1)
            {
                cout << "---Datos del alumno---" << endl;
                cout << "Matricula: " << grupo[index].matricula << endl;
                cout << "Nombre: " << grupo[index].nombre << endl; 
                cout << "Promedio: " << grupo[index].promedio << endl;
            } else {
                cout << "ERROR: Alumno no encontrado" << endl;
            }
            break;
        case 4:
            cout << "Actualizar alumno" <<endl;
            cout << "Ingrese matricula del alumno: " ;
            cin >> matricula;
            index = buscarAlumno(grupo, matricula);
            cin.ignore();

            if (index != -1 ){
                int promedio;
                string nombre;
                cout << "Ingrese nuevo nombre: ";
                getline(cin, nombre);

                cout << "Ingrese nuevo promedio: ";
                cin >> promedio;

                actualizarAlumno(grupo, matricula, nombre, promedio);
            } else {
                cout << "Error: Matricula no encontrada";
            }

            break;
        case 5:
            cout << "Eliminar alumno" <<endl;
            cout << "Ingreseme matricula del alumno: ";
            cin >> matricula;
            index = buscarAlumno(grupo, matricula);
            if (index != -1) {

                grupo.erase(grupo.begin() + index);

            } else {
                cout << "ERROR" <<endl;
            }
            break;
        case 6:
            cout << "Ordenar por promedio (desc)" <<endl;
            break;    
        case 7:
            cout << "Ordenar por promedio (asc)" <<endl;
            break; 
        case 8:
            cout << "Calcular promedio del grupo" <<endl;
            promedio = calcularPromedio(grupo);
            if (promedio != -1) {
                cout << "El promedio grupal es: " << promedio;
            } else {
                cout << "ERROR: Grupo vacio";
            }
            break;
        case 0:
            cout << "Saliendo..." <<endl;
            break;       
        default:
            cout << "Opcion invalida" <<endl;
            break;
        }

    } while (opcion != 0);

    return 0;
}