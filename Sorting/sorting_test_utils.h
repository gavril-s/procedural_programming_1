#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include <algorithm>
#include "rb_tree/rb_sort.h"
#include "avl_tree/avl_sort.h"
#include "bin_tree/bin_sort.h"

struct sort_time
{
    size_t array_size=0;
    double rb_time=0;
    double avl_time=0;
    double bin_time=0;
    double std_time=0;
};

bool vec_equal(std::vector<int>& v1, std::vector<int>& v2)
{
    if (v1.size() != v2.size())
        return false;

    for (int i = 0; i < v1.size(); ++i)
        if (v1[i] != v2[i])
            return false;

    return true;
}

void print_vec(std::vector<int>& v)
{
    for (int e : v)
        std::cout << e << ' ';
}

void println_vec(std::vector<int>& v)
{
    for (int e : v)
        std::cout << e << ' ';
    std::cout << std::endl;
}

void fill_vector(std::vector<int>& vec, int len)
{
    vec.clear();
    for (int i = 0; i < len; ++i)
        vec.push_back(std::rand());
}

double time_rb_sort(std::vector<int>& inp)
{
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    std::chrono::duration<double> time_span;

    t1 = std::chrono::high_resolution_clock::now();
    rb_sort(inp);
    t2 = std::chrono::high_resolution_clock::now();
    time_span = t2 - t1;
    return time_span.count();
}

double time_avl_sort(std::vector<int>& inp)
{
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    std::chrono::duration<double> time_span;

    t1 = std::chrono::high_resolution_clock::now();
    avl_sort(inp);
    t2 = std::chrono::high_resolution_clock::now();
    time_span = t2 - t1;
    return time_span.count();
}

double time_bin_sort(std::vector<int>& inp)
{
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    std::chrono::duration<double> time_span;

    t1 = std::chrono::high_resolution_clock::now();
    bin_sort(inp);
    t2 = std::chrono::high_resolution_clock::now();
    time_span = t2 - t1;
    return time_span.count();
}

double time_std_sort(std::vector<int>& inp)
{
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    std::chrono::duration<double> time_span;

    t1 = std::chrono::high_resolution_clock::now();
    std::sort(inp.begin(), inp.end());
    t2 = std::chrono::high_resolution_clock::now();
    time_span = t2 - t1;
    return time_span.count();
}