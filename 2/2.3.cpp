#include <iostream>
#include <cmath>

double z(double x, double y, double b)
{
    return log(b - y) * sqrt(b - x);
}

int main()
{
    double x = 0, y = 0, b = 0;
    std::cout << "Введите три числа: ";
    std::cin >> x >> y >> b;

    std::cout << "z = " << z(x, y, b) << std::endl;
    return 0;
}
