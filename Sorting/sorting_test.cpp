#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "sorting_test_utils.h"

sort_time single_time_test(std::vector<int>& inp)
{
    std::vector<int> inp_copy_rb  (inp);
    std::vector<int> inp_copy_avl (inp);
    std::vector<int> inp_copy_bin (inp);
    std::vector<int> inp_copy_std (inp);

    double rb_time  = time_rb_sort (inp_copy_rb);
    double avl_time = time_avl_sort(inp_copy_avl);
    double bin_time = time_bin_sort(inp_copy_bin);
    double std_time = time_std_sort(inp_copy_std);

    if ((!vec_equal(inp_copy_rb, inp_copy_std))  || 
        (!vec_equal(inp_copy_avl, inp_copy_std)) ||
        (!vec_equal(inp_copy_bin, inp_copy_std)))
    {
        std::cout << "############### ОШИБКА ###############" << std::endl;
        std::cout << "Исходные данные:" << std::endl;
        println_vec(inp); 
        std::cout << std::endl;

        std::cout << "rb_sort: " << std::endl;
        println_vec(inp_copy_rb); 
        std::cout << std::endl;

        std::cout << "avl_sort: " << std::endl;
        println_vec(inp_copy_avl);
        std::cout << std::endl;

        std::cout << "bin_sort: " << std::endl;
        println_vec(inp_copy_bin);
        std::cout << std::endl;

        std::cout << "std::sort: " << std::endl;
        println_vec(inp_copy_std); 
        std::cout << "#####################################" << std::endl;

        throw nullptr;
    }   
    else
    {
        sort_time res;
        res.array_size = inp.size();
        res.rb_time  = rb_time;
        res.avl_time = avl_time;
        res.bin_time = bin_time;
        res.std_time = std_time;
        return res;
    } 
}

std::vector<sort_time> full_time_test(int n, int inf, int sup, int takes)
{
    std::vector<sort_time> res (n, sort_time());
    std::vector<int> inp;
    int step = (sup - inf) / n;
    for (int i = 0; i < n; ++i)
    {
        if (i != 0 && ((100.0 * i) / n) - int(((100.0 * i) / n)) == 0 && 
            int(((100.0 * i) / n)) % 10 == 0)
        {
            std::cout << ((100.0 * i) / n) << "%\n";
        }

        for (int j = 0; j < takes; ++j)
        {
            fill_vector(inp, inf + i * step);
            sort_time curr_res = single_time_test(inp);
            res[i].array_size = curr_res.array_size;
            res[i].rb_time  += curr_res.rb_time;
            res[i].avl_time += curr_res.avl_time;
            res[i].bin_time += curr_res.bin_time;
            res[i].std_time += curr_res.std_time;
        }

        res[i].rb_time  /= takes;
        res[i].avl_time /= takes;
        res[i].bin_time /= takes;
        res[i].std_time /= takes;
    }
    std::cout << "DONE" << std::endl;
    return res;
}

void dump_points(std::vector<sort_time>& points, std::string filename)
{
    std::ofstream out(filename);
    for (sort_time& point : points)
    {
        out << point.array_size << ' '
            << point.rb_time    << ' '
            << point.avl_time   << ' '
            << point.bin_time   << ' ' 
            << point.std_time   << std::endl;
    }
    out.close();
}

int main()
{
    std::srand((unsigned int)time(NULL));
    std::vector<sort_time> res = full_time_test(
        20,      // количество точек
        0,       // нижняя граница размера массива
        1000000, // верхняя граница размера массива
        3        // количество попыток на одно значение размера массива
    );
    dump_points(res, "data/results.txt");
    return 0;
}