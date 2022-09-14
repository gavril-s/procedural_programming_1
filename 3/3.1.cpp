#include <iostream>
#include <cmath>

double m(double S, double p, double n)
{
    double r = p / 100;
    return (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double S = 0, p = 0, n = 0;
    std::cout << "������� S, p � n: ";
    std::cin >> S >> p >> n;

    if (p != 0)
        std::cout << "m = " << m(S, p, n) << std::endl;
    else
        std::cout << "���-�� �� ���������" << std::endl;
    return 0;
}
