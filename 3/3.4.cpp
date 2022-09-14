#include <iostream>
#include <fstream>

int main()
{
    std::ifstream ifs("3.4.file.txt");
    char ch;
    while (ifs >> ch)
        if (isdigit(ch))
            std::cout << ch;
    std::cout << std::endl;
    return 0;
}