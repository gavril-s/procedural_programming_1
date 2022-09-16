#include <iostream>
#include <string>

std::string get_stars(int row)
{
    if (row > 8 || row < 0)
        return std::string{""};
    std::string var1 = "* * * * * *";
    std::string var2 = " * * * * * ";
    if (row % 2 == 0)
        return var1;
    else
        return var2;
}

std::string get_stripe(int row)
{
    if (row > 12 || row < 0)
        return std::string{""};
    std::string red_stripe   = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    std::string white_stripe = "oooooooooooooooooooooooooooooooooo";
    if (row % 2 == 0)
        return red_stripe;
    else
        return white_stripe;
}

void print_flag()
{
    
    for (int row = 0; row < 13; ++row)
    {
        std::string row_str = get_stars(row) + get_stripe(row);
        row_str = row_str.substr(0, 33);
        std::cout << row_str << std::endl;
    }
}

int main()
{
    print_flag();
    return 0;
}