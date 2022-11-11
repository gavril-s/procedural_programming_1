#include <iostream>

int main()
{
    int A = 0, B = 0, C = 0;
    if(!(std::cin >> A >> B >> C))
    {
        std::cout << "Некорректный ввод" << std::endl;
        return 0;
    }
    std::cout << (C - A) / B << std::endl;
    return 0;
}