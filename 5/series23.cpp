#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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

bool is_valid_num(std::string num, int base)
{
    std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int dot_count = 0;
    for (int i = 0; i < num.length(); ++i)
    {   
        if (num[i] == '-' || num[i] == '+')
        {
            if (i == 0)
                continue;
            else
                return false;
        }
        if (num[i] == '.')
        {
            if (dot_count > 0)
                return false;
            else
            {
                dot_count++;
                continue;
            }
        }

        if (index(num[i], digits) == -1 || index(num[i], digits) >= base)
            return false;
    }
    return true;
}

int find_min_rank(std::string num)
{
    int dot_ind = index('.', num);
    if (dot_ind == -1)
        return 0;    
    else
        return -(num.length() - dot_ind - 1);
}

void remove_unneeded_zeros(std::string& str)
{
    if (index('.', str) == -1)
        return;

    while (str[str.length() - 1] == '0')
        str.erase(str.end() - 1);
    if (str[str.length() - 1] == '.')
        str.erase(str.end() - 1);
}

std::string translate(std::string num, int curr_base, int target_base)
{
    const int max_after_dot = 10;

    if (curr_base < 2 || curr_base > 36 ||
        target_base < 2 || target_base > 36)
        return std::string{"Некорректное основание"};

    if (!is_valid_num(num, curr_base))
        return std::string{"Некорректное число"};

    std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (curr_base == 10)
    {
        std::string sign = "";
        if (num.length() != 0)
            if (num[0] == '-' || num[0] == '+')
            {
                sign = std::string{num[0]};
                num.erase(num.begin());
            }
        
        unsigned long long int_part = (unsigned long long)std::stod(num);
        double float_part = std::stod(num) - int_part;
        std::string res;

        while (int_part > 0)
        {
            res += digits[int_part % target_base];
            int_part /= target_base;
        }
        if (res.length() == 0)
            res = "0";

        std::reverse(res.begin(), res.end());

        if (float_part != 0)
            res += '.';

        int after_dot_count = 0;
        while (float_part > 0 && after_dot_count < max_after_dot)
        {
            float_part *= target_base;
            res += std::to_string((int)float_part);
            after_dot_count++;
            float_part -= (int)float_part;
        }

        remove_unneeded_zeros(res);
        if (res == "0")
            sign = "";
        return sign + res;
    }
    else if (target_base == 10)
    {
        std::string sign = "";
        if (num.length() != 0)
            if (num[0] == '-' || num[0] == '+')
            {
                sign = std::string{num[0]};
                num.erase(num.begin());
            }
        
        int min_rank = find_min_rank(num);
        int rank = min_rank;

        double res_d = 0;
        for (int i = num.length() - 1; i >= 0; --i)
        {
            if (num[i] == '.')
                continue;
            res_d += std::pow(curr_base, rank) * index(num[i], digits);
            rank++;
        }
        
        std::string res = std::to_string(res_d);
        remove_unneeded_zeros(res);
        if (res == "0")
            sign = "";
        return sign + res;
    }
    else
    {
        std::string temp = translate(num, curr_base, 10);
        return translate(temp, 10, target_base);
    }
}

std::string get_spaces(int num)
{
    std::string res;
    for (int i = 0; i < num; ++i)
        res += ' ';
    return res;
}

void get_strings(std::istream& is, std::vector<std::string>& out)
{
    char temp_ch;
    std::string temp_str;
    while (is.get(temp_ch))
    {
        if (temp_ch == '\n')
            return;
        else
            is.putback(temp_ch);

        if (is >> temp_str)
            out.push_back(temp_str);
    }
}

int main()
{
    const int BASE_FROM = 3;
    const int BASE_TO   = 6;

    std::cout << "Введите массив чисел через пробел:" << std::endl;

    std::vector<std::string> input_array;
    get_strings(std::cin, input_array);

    size_t max_input_num_length = 0;
    std::vector<std::string> output_array;
    for (std::string num : input_array)
    {
        max_input_num_length = std::max(num.length(), max_input_num_length);
        output_array.push_back(translate(num, BASE_FROM, BASE_TO));
    }

    std::cout << "Результат перевода:" << std::endl;
    for (int i = 0; i < output_array.size(); ++i)
    {
        std::string delim = "->";
        std::cout << input_array[i]; 
        int needed_spaces = max_input_num_length - input_array[i].length();
        std::cout << get_spaces(needed_spaces) << ' ' << delim << ' ';
        std::cout << output_array[i] << std::endl;
    }

    return 0;
}