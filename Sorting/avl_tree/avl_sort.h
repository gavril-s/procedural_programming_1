#include <vector>
#include "avl_tree.h"

template <typename T>
void avl_sort(std::vector<T>& vec)
{
    avl_tree<T> sorting_tree;

    for (T elem : vec)
        sorting_tree.insert(elem);

    sorting_tree.to_vector(vec);
}