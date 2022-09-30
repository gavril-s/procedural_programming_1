#include <iostream>

int sign(double x)
{
    if (x > 0)
        return 1;
    else if (x == 0)
        return 0;
    else
        return -1;
}

int main()
{
    double inp = 0;
    if (std::cin >> inp)
        std::cout << sign(inp) << std::endl;
    else
        std::cout << "Некорректный ввод" << std::endl;
    return 0;
}