#include <iostream>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream ifst;
    ifst.open("text3.3.txt");

    char ch = 'a';
    while (ifst.get(ch))
    {
        std::cout << ch;
    }

    return 0;
}
