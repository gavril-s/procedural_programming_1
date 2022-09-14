#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    int N = 0;
    std::cout << "Введите N: ";
    std::cin >> N;

    if (N >= 1)
    {
        for (int i = N; i < N + 10; ++i)
            std::cout << i << ' ';
    }
    else
    {
        std::cout << "Что-то ты перепутал";
    }
    std::cout << std::endl;
    return 0;
}
