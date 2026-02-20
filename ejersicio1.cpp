#include <iostream>
#include <vector>

int main() {

    int a = 4;
    int* p_a = &a;
    std::vector<int> hola (10);
    
    for (int i = 0; i < 17 ; i++)
    {
        hola.push_back(i);
    }
    
    for (int i = 0; i < hola.size(); i++)
    {
        std::cout << hola[i] << std::endl;

    }
    
    std::cout << "-------------size and capacity-------------" << std::endl;
    
    std::cout << "size: " << hola.size() << std::endl;
    std::cout << "capacity: " << hola.capacity() << std::endl;
    //Al no definir la capacidad del vector cuando va a pedir memoria se hace de forma exponencial

    std::cout << "-------------------------------------------" << std::endl;

    return 0;
}