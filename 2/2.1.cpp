#include <iostream>
#include <cmath>

int main()
{
    double R = 0, r = 0, h = 0, l = 0;
    double pi = 3.1415926535;
    std::cout << "Введите большой и малый радиусы, а также высоту конуса: ";
    std::cin >> R >> r >> h;
    l = sqrt(h*h + (R - r) * (R - r));

    double V = pi * h * (R*R + R*r + r*r) / 3.0;
    double S = pi * (R*R + (R + r) * l + r*r);
    std::cout << "V = " << V << std::endl << "S = " << S << std::endl;

    return 0;
}
