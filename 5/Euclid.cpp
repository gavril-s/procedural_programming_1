#include <iostream>
#include <limits>
#include <string>

int GCD_sub(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a + b;
}

int GCD_div(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int main()
{
    int a = 0, b = 0;
    
    std::cout << "Введите два натуральных числа через пробел: ";
    if (!(std::cin >> a >> b))
    {
        std::cout << "Некорректный ввод!" << std::endl;
    }
    else
    {
        std::cout << std::endl << "\tРезультат" << std::endl;
        std::cout << "Вычитание:\t" << GCD_sub(a, b) << std::endl;
        std::cout << "Деление:\t" << GCD_sub(a, b) << std::endl; 
    }
    return 0;
}