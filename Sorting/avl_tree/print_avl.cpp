#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include <limits.h>
#include <math.h>
#include "avl_tree.h"
#include "../rb_tree/rb_tree.h"
#include "../bin_tree/bin_tree.h"

int randrange(int min, int max)
{
    if (min == INT_MIN && max == INT_MAX)
    {
        return std::rand();
    }
    return min + (std::rand() % static_cast<int>(max - min + 1));
}

void fill_vector(std::vector<int>& vec, int len,
                 int min=INT_MIN, int max=INT_MAX)
{
    vec.clear();
    for (int i = 0; i < len; ++i)
        vec.push_back(randrange(min, max));
}

void dump_points(std::vector<std::pair<int, int>>& points, 
                 std::string filename)
{
    std::ofstream out(filename);
    for (auto point : points)
    {
        out << point.first << ' ' << point.second << std::endl;
    }
    out.close();
}

int main()
{
    std::srand((unsigned int)time(NULL));

    std::vector<std::pair<int, int>> res;

    for (int i = 0; i <= 20; ++i)
    {
        avl_tree<int> avl;
        std::vector<int> tst(std::pow(2, i), 0);
        fill_vector(tst, tst.size());

        for (int j : tst)
        {
            avl.insert(j);
        }
        res.push_back(std::make_pair(i, avl.max_height()));
    }

    dump_points(res, "result.txt");
    return 0;
}