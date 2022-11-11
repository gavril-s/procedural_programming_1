#pragma once
#include <iostream>
#include <vector>

template <typename T>
struct bin_tree_node
{
    T val_ = T();
    bin_tree_node* parent_      = nullptr;
    bin_tree_node* left_child_  = nullptr;
    bin_tree_node* right_child_ = nullptr;

    bin_tree_node(int val,
                  bin_tree_node* parent      = nullptr,
                  bin_tree_node* left_child  = nullptr, 
                  bin_tree_node* right_child = nullptr)
    : val_(val), parent_(parent), left_child_(left_child),
      right_child_(right_child) {}
};

template <typename T>
class bin_tree
{
private:
    bin_tree_node<T>* root_ = nullptr;

    void del_tree(bin_tree_node<T>* node);

    bin_tree_node<T>* insert    (bin_tree_node<T>* parent, T val);
    void              print     (bin_tree_node<T>* node);
    void              to_vector (bin_tree_node<T>* node, std::vector<T>& vec);
    int               height    (bin_tree_node<T>* node);
public:
    ~bin_tree();

    bin_tree_node<T>* insert    (T val);
    void              print     ();
    void              to_vector (std::vector<T>& vec);
    int               max_height();
};

template <typename T>
void bin_tree<T>::del_tree(bin_tree_node<T>* node)
{
    if (node == nullptr) return;
    del_tree(node->left_child_);
    del_tree(node->right_child_);
    delete node;
}

template <typename T>
bin_tree_node<T>* bin_tree<T>::insert(bin_tree_node<T>* parent, T val)
{
    if (parent == nullptr)
    {
        if (root_ == nullptr)
        {
            root_ = new bin_tree_node<T>(val);
            return root_;
        }
        return nullptr;
    }

    if (val < parent->val_)
    {
        if (parent->left_child_ == nullptr)
        {
            bin_tree_node<T>* new_node = new bin_tree_node<T>(val, parent);
            parent->left_child_ = new_node;
            return new_node;
        }
        else
        {
            return insert(parent->left_child_, val);
        }
    }
    else
    {
        if (parent->right_child_ == nullptr)
        {
            bin_tree_node<T>* new_node = new bin_tree_node<T>(val, parent);
            parent->right_child_ = new_node;
            return new_node;
        }
        else
        {
            return insert(parent->right_child_, val);
        }
    }
}

template <typename T>
void bin_tree<T>::print(bin_tree_node<T>* node)
{
    if (node == nullptr) return;
    print(node->left_child_);
    std::cout << node->val_ << std::endl;
    print(node->right_child_);
}

template <typename T>
void bin_tree<T>::to_vector(bin_tree_node<T>* node, std::vector<T>& vec)
{
    if (node == nullptr) return;
    to_vector(node->left_child_, vec);
    vec.push_back(node->val_);
    to_vector(node->right_child_, vec);
}

template <typename T>
int bin_tree<T>::height(bin_tree_node<T>* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    
    return 1 + std::max(
        height(node->left_child_),
        height(node->right_child_)
    );
}

template <typename T>
bin_tree<T>::~bin_tree()
{
    del_tree(root_);
}

template <typename T>
bin_tree_node<T>* bin_tree<T>::insert(T val)
{
    return insert(root_, val);
}

template <typename T>
void bin_tree<T>::print()
{
    print(root_);
}

template <typename T>
void bin_tree<T>::to_vector(std::vector<T>& vec)
{
    vec.clear();
    to_vector(root_, vec);
}

template <typename T>
int bin_tree<T>::max_height()
{
    return height(root_);
}