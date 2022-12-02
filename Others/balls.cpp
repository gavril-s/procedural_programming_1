#include <iostream>
#include <vector>

void process_permutation(std::vector<int> inp, int& count)
{
    bool good = false;
    for (int j = 0; j < inp.size(); ++j)
    {
        if (j + 1 == inp[j])
        {
            good = true;
        }
    }
    if (good) 
    {
        count++;
    }
}

void permute(std::vector<int>& inp, int l, int r, int& count)
{
    if (l == r)
    {
        process_permutation(std::vector<int>(inp), count);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            std::swap(inp[l], inp[i]);
            permute(inp, l+1, r, count);
            std::swap(inp[l], inp[i]);
        }
    }
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

    int count = 0;
    permute(balls, 0, balls.size() - 1, count);

    std::cout << count << std::endl;
    return 0;
}