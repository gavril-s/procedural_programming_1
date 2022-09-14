#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian");

    double a = 0, b = 0, c = 0;
    std::cout << "Введите коэффициенты квадратного уравнения: ";
    std::cin >> a >> b >> c;

    if (a == 0)
    {
        if (b == 0)
            std::cout << "Все вещественные числа" << std::endl;
        else
            std::cout << "x = " << -c / b << std::endl;
    }
    else
    {
        double D = b * b - 4 * a * c;
        if (D < 0)
        {
            std::cout << "Решений нет" << std::endl;
        }
        else if (D == 0)
        {
            std::cout << "x = " << -b / (2 * a) << std::endl;
        }
        else
        {
            double x1 = (-b - sqrt(D)) / (2 * a);
            double x2 = (-b + sqrt(D)) / (2 * a);
            std::cout << "x1 = " << x1 << std::endl
                      << "x2 = " << x2 << std::endl;
        }
    }

    return 0;
}
