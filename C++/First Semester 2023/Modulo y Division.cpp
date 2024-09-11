#include <iostream>

int main() {
  int a, b, c, d , e, f, num;
  
  std::cout << "Ingrese un numero de 6 cifras: "; std::cin >> num;

  f = num % 10; // 123456 % 10 = 6
  e = num % 100 / 10; // 123456 % 100 = 56 / 10 = 5
  d = num % 1000 / 100; // 123456 % 1000 = 456 / 100 = 4
  c = num % 10000 / 1000; // 123456 % 10000 = 3456 / 1000 = 3
  b = num % 100000 / 10000; // 123456 % 100000 = 23456 / 10000 = 2
  a = num % 1000000 / 100000; // 123456 % 1000000 = 123456 / 100000 = 1
  
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << d << std::endl;
  std::cout << e << std::endl;
  std::cout << f << std::endl;
}