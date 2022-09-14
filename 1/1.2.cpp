#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    double a = 0, b = 0;
    std::cout << "¬ведите два числа: ";
    std::cin >> a >> b;

    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    if (b != 0)
        std::cout << a << " / " << b << " = " << a / b << std::endl;
    return 0;
}
