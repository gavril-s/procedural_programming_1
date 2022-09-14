#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::cout << "Введите строку:" << std::endl;
    std::string str;
    std::cin >> str;
    
    for (char ch : str)
        if (!isalpha(ch))
        {
            std::cout << "Что-то ты перепутал";
            return 0;
        }
    if (str.length() < 30)
    {
        std::cout << "Что-то ты перепутал";
        return 0;
    }
    
    str = str.substr(0, 30);

    std::sort(str.begin(), str.end());
    std::cout << str << std::endl;
    return 0;
}
