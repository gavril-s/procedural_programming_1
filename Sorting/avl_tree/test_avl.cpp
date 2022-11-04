#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include "avl_tree.h"
#include "../rb_tree/rb_tree.h"
#include "../bin_tree/bin_tree.h"

int randrange(int min, int max)
{
    return min + (std::rand() % static_cast<int>(max - min + 1));
}

void fill_vector(std::vector<int>& vec, int len, int min, int max)
{
    vec.clear();
    for (int i = 0; i < len; ++i)
        vec.push_back(randrange(min, max));
}

int main()
{
    std::srand((unsigned int)time(NULL));
    avl_tree<int> avl;
    rb_tree<int> rb;
    bin_tree<int> bin;

    std::vector<int> tst(1000000, 0);
    fill_vector(tst, tst.size(), -2000000000, 2000000000);

    for (int i : tst)
    {
        avl.insert(i);
        rb.insert(i);
        bin.insert(i);
    }

    double rb_sum = 0;
    double avl_sum = 0;
    double bin_sum = 0;

    for (int i : tst)
    {
        std::chrono::high_resolution_clock::time_point t1;
        std::chrono::high_resolution_clock::time_point t2;
        std::chrono::duration<double> time_span_rb, 
                                      time_span_avl, 
                                      time_span_bin;

        t1 = std::chrono::high_resolution_clock::now();
        rb.find(i);
        t2 = std::chrono::high_resolution_clock::now();
        time_span_rb = t2 - t1;
        
        t1 = std::chrono::high_resolution_clock::now();
        avl.find(i);
        t2 = std::chrono::high_resolution_clock::now();
        time_span_avl = t2 - t1;

        t1 = std::chrono::high_resolution_clock::now();
        bin.find(i);
        t2 = std::chrono::high_resolution_clock::now();
        time_span_bin = t2 - t1;

        rb_sum  += time_span_rb.count();
        avl_sum += time_span_avl.count();
        bin_sum += time_span_bin.count();
    }

    double rb_avg_ns  = rb_sum  * 1000000000 / tst.size();
    double avl_avg_ns = avl_sum * 1000000000 / tst.size();
    double bin_avg_ns = bin_sum * 1000000000 / tst.size(); 

    std::cout << "rb  : " << rb_avg_ns  << std::endl;
    std::cout << "avl : " << avl_avg_ns << std::endl;
    std::cout << "bin : " << bin_avg_ns << std::endl;

    return 0;
}