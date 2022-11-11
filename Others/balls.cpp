#include <iostream>
#include <vector>

void permute(std::vector<int>& inp, std::vector<std::vector<int>>& out, int l, int r)
{
    if (l == r)
    {
        out.push_back(std::vector<int>(inp));
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            std::swap(inp[l], inp[i]);
            permute(inp, out, l+1, r);
            std::swap(inp[l], inp[i]);
        }
    }
}

void permute(std::vector<int>& inp, std::vector<std::vector<int>>& out)
{
    permute(inp, out, 0, inp.size() - 1);
}


int main()
{
    int balls_amount = 0;
    if(!(std::cin >> balls_amount) || balls_amount < 0)
    {
        std::cout << "Некорректный ввод" << std::endl;
        return 0;
    }

    std::vector<int> balls(balls_amount, 0);
    for (int i = 0; i < balls.size(); ++i)
        balls[i] = i + 1;

    std::vector<std::vector<int>> res;
    permute(balls, res, 0, balls.size() - 1);

    int count = 0;
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[i].size(); ++j)
        {
            if (j == res[i][j]) count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}