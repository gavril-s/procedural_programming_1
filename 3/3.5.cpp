#include <iostream>
#include <string>
#include <algorithm>

void bubble_sort(std::string& str)
{
    int start = 0, end = str.length() - 1;
    bool is_sorted = false;
    while (!is_sorted)
    {
        is_sorted = true;
        for (int i = start; i < end; ++i)
        {
            if (tolower(str[i]) > tolower(str[i + 1]))
            {
                std::swap(str[i], str[i + 1]);
                is_sorted = false;
            }
            else if (tolower(str[i]) == tolower(str[i + 1]) && str[i] > str[i + 1])
            {
                std::swap(str[i], str[i + 1]);
                is_sorted = false;
            }
        }
        end--;
    }
}

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

    bubble_sort(str);
    std::cout << str << std::endl;
    return 0;
}
