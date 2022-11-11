#include <iostream>

int main()
{
    int N = 0, K = 0;
    if (!(std::cin >> N >> K))
    {
        std::cout << "Некорректный ввод" << std::endl;
        return 0;
    }

    int prev_longest = 0;
    int curr_longest = N;
    int last_free_left = N;
    int last_free_right = N;
    for (int i = 0; i < K; ++i)
    {
        if (curr_longest % 2 == 0)
        {
            curr_longest /= 2;
            last_free_left = curr_longest - 1;
            last_free_right = curr_longest;
            if (prev_longest > curr_longest)
            {
                std::swap(curr_longest, prev_longest);
            }
            else
            {
                prev_longest = curr_longest - 1;
            }
        }
        else
        {
            curr_longest = (curr_longest - 1) / 2;
            last_free_left = curr_longest;
            last_free_right = curr_longest;

            if (prev_longest > curr_longest)
            {
                std::swap(curr_longest, prev_longest);
            }
            else
            {
                prev_longest = curr_longest;
            }
        }
    }
    
    std::cout << last_free_left << std::endl;
    std::cout << last_free_right << std::endl;
    return 0;
}