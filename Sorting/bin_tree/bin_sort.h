#include <vector>
#include "bin_tree.h"

template <typename T>
void bin_sort(std::vector<T>& vec)
{
    bin_tree<T> sorting_tree;

    for (T elem : vec)
        sorting_tree.insert(elem);

    sorting_tree.to_vector(vec);
}