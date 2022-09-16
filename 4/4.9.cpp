#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int index(char ch, std::string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ch)
            return i;
    }
    return -1;
}

std::string translate(std::string num, int curr_base, int target_base)
{
    if (curr_base < 2 || curr_base > 36 ||
        target_base < 2 || target_base > 36)
        return std::string{"База"};

    char digits[36] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    if (curr_base == 10)
    {
        int n = std::stoi(num);
        std::string res;
        while (n > 0)
        {
            res += digits[n % target_base];
            n /= target_base;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
    else if (target_base == 10)
    {
        unsigned long long res = 0;
        for (int i = 0; i < num.length(); ++i)
        {
            res += std::pow(curr_base, i) * index(num[num.length() - i - 1], digits);
        }
        return std::to_string(res);
    }
    else
    {
        std::string temp = translate(num, curr_base, 10);
        return translate(temp, 10, target_base);
    }
}

int main()
{
    int curr_base = 0, target_base = 0;
    std::string num;

    std::cout << "Исходное число: ";
    std::cin >> num;

    std::cout << "Старое основание: ";
    std::cin >> curr_base;

    std::cout << "Новое основание: ";
    std::cin >> target_base;

    std::cout << std::endl << "Результат: " 
              << translate(num, curr_base, target_base) << std::endl;
    return 0;
}