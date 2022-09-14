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
    bool curtains = ask("Шторы раздвинуты?");
    bool lamp = ask("Лампа включена?");
    bool day = ask("На улице день?");

    if ((day && curtains) || lamp)
        std::cout << "Светло" << std::endl;
    else
        std::cout << "Темно" << std::endl;

    return 0;
}
