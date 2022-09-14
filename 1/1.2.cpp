#include <iostream>

int main()
{
    double a = 0, b = 0;
    std::cout << "Введите два числа: ";
    std::cin >> a >> b;

    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    if (b != 0)
        std::cout << a << " / " << b << " = " << a / b << std::endl;
    return 0;
}
