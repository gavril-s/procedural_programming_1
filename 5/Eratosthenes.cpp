#include <iostream>
#include <vector>

std::vector<int> find_primes(int sup)
{
    if (sup <= 2)
    {
        return std::vector<int>();
    }

    std::vector<int> is_prime_table(sup, true);
    is_prime_table[0] = false;
    is_prime_table[1] = false;
    for (int i = 2; i < is_prime_table.size(); ++i)
    {
        if (!is_prime_table[i])
        {
            continue;
        }

        for (int j = i + i; j < is_prime_table.size(); j += i)
        {
            is_prime_table[j] = false;
        }
    }

    std::vector<int> primes;
    for (int i = 0; i < is_prime_table.size(); ++i)
    {
        if (is_prime_table[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
}

int main()
{
    int sup = 0;
    std::cout << "Найти все простые числа до ? ";

    if (!(std::cin >> sup))
    {
        std::cout << "Некорректный ввод" << std::endl;
    }
    else 
    {
        std::vector<int> primes = find_primes(sup);
        if (primes.size() == 0)
        {
            std::cout << "В этом диапазоне нет простых чисел" << std::endl;
        }
        else
        {
            std::cout << "Результат:" << std::endl;
            for (int p : primes)
            {
                std::cout << p << ' ';
            }
            std::cout << std::endl;
        }
    }

    return 0;
}