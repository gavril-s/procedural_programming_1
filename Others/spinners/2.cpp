#include <iostream>

int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

std::pair<int, int> euclid_pro(int a, int b)
{
    int p = 1, q = 0, r = 0, s = 1;
    int x = 0, y = 0;

    while (a != 0 && b != 0) 
    {
        if (a>=b)
        {
            a -= b; 
            p -= r; 
            q -= s; 
        } 
        else
        {
            b -= a; 
            r -= p; 
            s -= q; 
        }
    }

    if (a != 0)
    {
        x = p;
        y = q;
    }
    else
    {
        x = r;
        y = s;
    }

    return std::make_pair(x, y);
}

int main()
{   
    // 3*x + 4*y = M
    const int border = 100000;
    int M = 0;
    if(!(std::cin >> M))
    {
        std::cout << "Некорректный ввод" << std::endl;
        return 0;
    }

    int res_x = 0;
    int res_y = 0;

    for (int i = 0; i < border;)
    {
        int x = -M - i * 4;
        int y =  M + i * 3;

        if (x >= 0 && y >= 0)
        {
            res_x = x;
            res_y = y;
            break;
        }

        int new_i = std::abs(i);
        new_i++;
        new_i *= (i < 0 ? 1 : -1);
        i = new_i;
    }

    std::cout << res_x << std::endl;
    std::cout << res_y << std::endl;

    return 0;
}