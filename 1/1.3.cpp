#include <iostream>

int main()
{
    double b = 0, c = 0;
    std::cout << "Введите два числа: ";
    std::cin >> b >> c;

    if (b != 0)
        std::cout << "x = " << -c / b << std::endl;
    else
        std::cout << "Что-то ты перепутал" << std::endl;

    return 0;
}
