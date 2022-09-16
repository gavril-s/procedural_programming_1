#include <iostream>
#include <string>
#include <map>

bool is_roman(std::string number)
{
    std::string digits = "IVXLCDM";
    for (char ch : number)
    {
        if (digits.find(ch) == -1)
        {
            return false;
        }
    }
    return true;
}

int roman_cast(std::string number)
{
    std::map<char, int> digits = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int res = 0;
    for (int i = 0; i < number.length(); ++i)
    {
        if (i + 1 < number.length() && 
            digits[number[i]] < digits[number[i + 1]])
        {
            res -= digits[number[i]];
        }
        else
        {
            res += digits[number[i]];
        }
    }

    return res;
}

int main()
{
    std::string roman_number;
    std::cout << "Введите римское число: ";
    std::cin >> roman_number;
    
    if (is_roman(roman_number))
        std::cout << "Результат: " << roman_cast(roman_number) << std::endl;
    else
        std::cout << "Что-то ты перепутал" << std::endl;
    return 0;
}