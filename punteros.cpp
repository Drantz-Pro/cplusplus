#include<iostream>


int main(){

    int a = 5;

    std::cout << "El valor de a = " << a << std::endl;
    std::cout << "El es la direccion de memoria de a = " << &a << std::endl;

    int *b = &a;

    std::cout << "El valor de b = " << b << std::endl;
    std::cout << "El es la direccion de memoria de b = " << &b << std::endl;
    std::cout << "El valor de la direccion que guarda b =" << *b << std::endl;

    
    delete b;



    return 0;
}