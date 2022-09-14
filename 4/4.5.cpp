#include <iostream>
#include <cmath>
#include <vector>

int main()
{
    double start_x = 0, end_x = 10;
    double x_step = 0.5, y_step = 0.1;
    int graph_x_size = ceil((end_x - start_x) / x_step);
    std::vector<std::vector<bool>> graph;
    for (double y = -1; y <= 1; y += y_step)
        graph.push_back(std::vector<bool> (graph_x_size, false));

    int i = 0;
    for (double x = start_x; x <= end_x; x += x_step)
    {
        double f = sin(x);
        int res_j = 0;
        int j = 0;
        for (double y = -1; y <= 1; y += y_step)
        {
            if (f >= y && f <= y + y_step)
            {
                if (std::abs(f - y) < std::abs(f - (y + y_step)))
                    res_j = j;
                else
                    res_j = j + 1;
            }
            else if (f >= y - y_step && f <= y)
            {
                if (std::abs(f - y) < std::abs(f - (y - y_step)))
                    res_j = j;
                else
                    res_j = j - 1;
            }
            j++;
        }
        graph[i][res_j] = true;
        i++;
    }

    for (auto i : graph)
    {
        for (bool j : i)
            if (j) std::cout << "■";
            else   std::cout << ' ';
        std::cout << std::endl;
    }

    /*for (i = graph_x_size - 1; i >= 0; --i)
    {
        for (int j = 0; j < graph.size(); ++j)
            if (graph[j][i]) std::cout << "■";
            else             std::cout << ' ';
        std::cout << std::endl;
    }*/
    return 0;
}