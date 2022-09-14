#include <iostream>
#include <cmath>

double y(double x)
{
    return (x*x - 2 * x + 2) / (x - 1);
}

void tab(double (*func)(double), double inf, double sup, double step)
{
    double res = 0;
    for (double x = inf; x <= sup; x += step)
    {
        res = func(x);
        std::cout << x << '\t';
        if (std::isfinite(res))
            std::cout << res;
        else
            std::cout << "нет значения";
        std::cout << std::endl;
    }
}

int main()
{
    tab(y, -4, 4, 0.5);
    return 0;
}
