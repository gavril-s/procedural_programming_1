#include <iostream>
#include <string>
#include <random>
#include <ctime>

bool is_num(std::string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

std::string construct_number(int size)
{
    if (size < 0 || size > 10) return "";
    std::string digits = "0123456789";
    std::string res = "";

    for (int i = 0; i < size; ++i)
    {
        int min = (i == 0) ? 1 : 0;
        int max = size - 1;
        int index = min + (rand() % (max - min + 1));
        res += digits[index];
        digits.erase(index, 1);
    }

    return res;
}

std::pair<int, int> guess(std::string num, std::string guess_num)
{
    int pluses = 0;
    int minuses = 0;
    for (int i = 0; 
         i < std::min(num.length(), guess_num.length()); 
         ++i)
    {
        for (int j = 0; 
             j < std::min(num.length(), guess_num.length()); 
             ++j)
        {
            if (num[i] == guess_num[j])
            {
                if (i == j)
                {
                    pluses++;
                }
                else
                {
                    minuses++;
                }
            }
        }
    }

    return std::make_pair(pluses, minuses);
}

int main()
{
    srand(time(NULL));
    const int NUM_LENGTH = 4;
    std::string num = construct_number(NUM_LENGTH);
    std::cout << num << std::endl;;
    std::string inp;
    while (true)
    {
        std::cout << "Введите число: ";
        if (!(std::cin >> inp) || inp.length() != NUM_LENGTH ||
            !is_num(inp))
        {
            continue;
        }
        std::pair<int, int> res = guess(num, inp);
        std::cout << "Плюсы:  " << res.first  << std::endl
                  << "Минусы: " << res.second << std::endl; 
        if (res.first == NUM_LENGTH)
        {
            std::cout << "Вы победили!" << std::endl;
            break;
        }
    }
    return 0;
}