#include <iostream>
#include <cmath>

double get_m(double S, double p, double n)
{
    double r = p / 100;
    return (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
}

int main()
{
    const double precision = 0.01;

    double S = 0, m = 0, n = 0;
    std::cout << "Введите S, m и n: ";
    std::cin >> S >> m >> n;
    while (S < 0 || m < 0 || n < 0)
    {
        std::cout << "Что-то ты перепутал..." << std::endl;
        std::cin >> S >> m >> n;
    }

    double best_p = 0;
    double best_p_diff = -1;
    for (double p = precision; p <= 100; p += precision)
    {
        double curr_m = get_m(S, p, n);
        double curr_diff = std::abs(curr_m - m);
        if (curr_diff < best_p_diff || best_p_diff == -1)
        {
            //std::cout << "best p : " << p << " diff : " << curr_diff <<std::endl;
            best_p = p;
            best_p_diff = curr_diff;
        }
    }
    std::cout << "p = " << best_p << std::endl;
    return 0;
}
