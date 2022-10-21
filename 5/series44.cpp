#include <iostream>
#include <map>

bool check_newline(std::istream& is)
{
    char ch = ' ';
    while (ch == ' ')
        is.get(ch);
    if (ch == '\n')
        return true;
    else
        is.putback(ch);
    return false;
}

int Cn2(int n)
{
    return n * (n - 1) / 2;
}

double get_average_height(const std::map<double, int>& group)
{
    double sum = 0;
    int total_amount = 0;
    for (auto it = group.begin(); it != group.end(); it++)
    {
        double height = it->first;
        int amount = it->second;
        sum += height * amount;
        total_amount += amount;
    }

    return sum / total_amount;
}

int count_equal_height_pairs(const std::map<double, int>& group)
{
    int count = 0;
    for (auto it = group.begin(); it != group.end(); it++)
    {
        double height = it->first;
        int amount = it->second;
        count += Cn2(amount);
    }

    return count;
}

int count_taller_than(double sup_height, const std::map<double, int>& group)
{
    int count = 0;
    for (auto it = group.begin(); it != group.end(); it++)
    {
        double height = it->first;
        int amount = it->second;
        if (height > sup_height)
            count += amount;
    }

    return count;
}

int main()
{
    std::map<double, int> group;

    std::cout << "Введите рост всех учеников класса через пробел:" << std::endl;
    double height = 0;
    char tmp = ' ';
    while (!check_newline(std::cin))
    {
        std::cin >> height;

        if (group.find(height) == group.end())
            group.insert(std::make_pair(height, 1));
        else
            group[height]++;
    }

    double average_height = get_average_height(group);
    int taller_than_avg = count_taller_than(average_height, group);
    int equal_height = count_equal_height_pairs(group);

    std::cout << "Средний рост класса:                         " << average_height << std::endl;
    std::cout << "Количество учеников выше среднего:           " << taller_than_avg << std::endl;
    std::cout << "Количестко пар учеников с одинаковым ростом: " << equal_height << std::endl;

    return 0;
}