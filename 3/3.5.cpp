#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    setlocale(LC_ALL, "Russian");

    //std::string str = "wqphjsaeflmbieyplfbuibetyegkj";
    std::cout << "¬ведите строку:" << std::endl;
    std::string str;
    std::cin >> str;

    std::sort(str.begin(), str.end());
    std::cout << str << std::endl;
    return 0;
}
