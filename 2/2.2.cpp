#include <iostream>
#include <cmath>

double w(double x, double a)
{
    if (std::abs(x) < 1)
        return a * log(std::abs(x));
    else
        return sqrt(a - x*x);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double x = 0, a = 0;
    std::cout << "Введите два числа: ";
    std::cin >> x >> a;
    std::cout << "w = " << w(x, a) << std::endl;
    return 0;
}
