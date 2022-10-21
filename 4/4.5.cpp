#include <iostream>
#include <math.h>
#include <vector>

int main()
{
    int pi_mult = 0;
    std::cout << "Напечатать синус до ?*π ";
    std::cin >> pi_mult;

    double start_x = 0, end_x = pi_mult*M_PI;
    double x_step = 0.1, y_step = 0.1;

    int graph_x_size = ceil((end_x - start_x) / x_step);
    int graph_y_size = 0;
    std::vector<std::vector<bool>> graph;
    for (double y = -1; y <= 1; y += y_step)
    {
        graph.push_back(std::vector<bool> (graph_x_size, false));
        graph_y_size++;
    }

    int i = 0;
    for (double x = start_x; x <= end_x; x += x_step)
    {
        double f = cos(x);
        int j = graph_y_size - round((f + 1) / y_step) - 1;
        graph[j][i] = true;
        i++;
    }

    for (int j = 0; j < graph_y_size; ++j)
    {
        for (int i = 0; i < graph_x_size; ++i)
        {
            if (graph[j][i]) std::cout << "■";
            else             std::cout << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}