#include <iostream>
#include <vector>
#include <algorithm>

bool contains(std::vector<int>& vec, int elem)
{
    return std::find(vec.begin(), vec.end(), elem) != vec.end();
}

bool coupe_free(int num, int max_seat, 
                std::vector<int>& free_seats)
{
    std::vector<int> coupe_seats = {
        num * 4 + 1,
        num * 4 + 2, 
        num * 4 + 3,
        num * 4 + 4,
        max_seat - num * 2,
        max_seat - num * 2 - 1,
    };

    for (int seat : coupe_seats)
    {
        if (!contains(free_seats, seat))
        {
            return false;
        } 
    }

    return true;
}

int main()
{
    const int MAX_SEAT = 54, COUPE_NUM = 5;
    int N = 0;
    if (!(std::cin >> N) || N < 0)
    {
        std::cout << "Некорректный ввод" << std::endl;
        return 0;
    }
    std::vector<int> free_seats(N, 0);
    for (int& i : free_seats)
    {
        if (!(std::cin >> i))
        {
            std::cout << "Некорректный ввод" << std::endl;
            return 0;
        }
    }

    int count = 0;
    for (int i = 0; i < COUPE_NUM; ++i)
    {
        if (coupe_free(i, MAX_SEAT, free_seats))
        {
            count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}