#include <iostream>

int count_containing(int in_x, int in_y, int out_x, int out_y)
{
    int res = 0;
    for (int left_up_x = 0; left_up_x < out_x; ++left_up_x)
    {
        for (int left_up_y = 0; left_up_y < out_y; ++left_up_y)
        {
            if (left_up_x + in_x <= out_x &&
                left_up_y + in_y <= out_y)
            {
                res++;
            }
        }
    }

    return res;
}

int main()
{
    int N = 0, M = 0;
    if (!(std::cin >> N >> M))
    {
        std::cout << "Некорректный ввод" << std::endl;
        return 0;
    }

    int res = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            res += count_containing(i, j, N, M);
        }
    }

    std::cout << res << std::endl;
    return 0;
}