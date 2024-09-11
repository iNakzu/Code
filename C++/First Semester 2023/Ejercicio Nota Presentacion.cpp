#include <iostream>

int main() {
    float s1, s2, c, lab;
    std::cout << "Ingrese nota de solemne 1: "; std::cin >> s1;
    std::cout << "Ingrese nota de solemne 2: "; std::cin >> s2;
    std::cout << "Ingrese promedio de controles: "; std::cin >> c;
    std::cout << "Ingrese nota de laboratorios: "; std::cin >> lab;
    float np = s1 * 0.35 + s2 * 0.35 + c * 0.15 + lab * 0.15;
    
    std::cout << "Su nota de presentacion es de: " << np << std::endl;
}