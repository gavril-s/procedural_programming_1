#include <vector>
#include "rb_tree.h"

template <typename T>
void rb_sort(std::vector<T>& vec)
{
    rb_tree<T> sorting_tree;

    for (T elem : vec)
        sorting_tree.append(elem);

    sorting_tree.to_vector(vec);
}