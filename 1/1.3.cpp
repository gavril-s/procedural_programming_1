#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    double b = 0, c = 0;
    std::cout << "������� ��� �����: ";
    std::cin >> b >> c;

    if (b != 0)
        std::cout << "x = " << -c / b << std::endl;
    else
        std::cout << "���-�� �� ���������" << std::endl;

    return 0;
}
