#include <iostream>
#include <string>

bool ask(std::string q)
{
    std::string ans;
    std::cout << q << " (y/n) ";
    std::cin >> ans;

    if (ans == "y")
        return true;
    else if (ans == "n")
        return false;
    else
        return ask(q);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    bool curtains = ask("����� ����������?");
    bool lamp = ask("����� ��������?");
    bool day = ask("�� ����� ����?");

    if ((day && curtains) || lamp)
        std::cout << "������" << std::endl;
    else
        std::cout << "�����" << std::endl;

    return 0;
}
