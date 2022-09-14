#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    //std::string str = "wqphjsaeflmbieyplfbuibetyegkj";
    std::cout << "Введите строку:" << std::endl;
    std::string str;
    std::cin >> str;

    std::sort(str.begin(), str.end());
    std::cout << str << std::endl;
    return 0;
}
