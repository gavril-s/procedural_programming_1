#pragma once
#include <iostream>

template <typename T>
struct bin_tree_node
{
    T val_=T();
    bin_tree_node* parent_=nullptr;
    bin_tree_node* left_child_=nullptr;
    bin_tree_node* right_child_=nullptr;

    bin_tree_node(int val, bin_tree_node* parent=nullptr,
                 bin_tree_node* left_child=nullptr, 
                 bin_tree_node* right_child=nullptr)
    : val_(val), parent_(parent), left_child_(left_child),
      right_child_(right_child) {}
};

template <typename T>
class bin_tree
{
private:
    bin_tree_node<T>* root_=nullptr;
    size_t size_=0;
    bin_tree_node<T>* last_check_=nullptr;

    void del_tree(bin_tree_node<T>* node)
    {
        if (node == nullptr) return;
        del_tree(node->left_child_);
        del_tree(node->right_child_);
        delete node;
    }
public:
    ~bin_tree()
    {
        del_tree(root_);
    }

    bin_tree_node<T>* insert(bin_tree_node<T>* parent, T val)
    {
        size_++;
        if (parent == nullptr || root_ == nullptr)
        {
            root_ = new bin_tree_node<T>(val);
            return root_;
        }
        bin_tree_node<T>* new_node = new bin_tree_node<T>(val, parent);
        if (new_node->val_ < parent->val_)
        {
            parent->left_child_ = new_node;
        }
        else
        {
            parent->right_child_ = new_node;
        }
        return new_node;
    }

    bin_tree_node<T>* insert(T val)
    {
        bin_tree_node<T>* search_res = this->find_leaf(val);
        if (search_res == nullptr)
        {
            return this->insert(last_check_, val);
        }
        else
        {
            return this->insert(search_res, val);
        }
    }

    bin_tree_node<T>* find_leaf(T val)
    {
        bin_tree_node<T>* curr = root_;
        last_check_ = root_;
        while (curr != nullptr)
        {
            if (val < curr->val_)
            {
                curr = curr->left_child_;
            }
            else
            {
                curr = curr->right_child_;
            }
            if (curr != nullptr)
            {
                last_check_ = curr;
            }
        }
        return nullptr;
    }

    bin_tree_node<T>* find(T val)
    {
        bin_tree_node<T>* curr = root_;
        last_check_ = root_;
        while (curr != nullptr)
        {
            if (curr->val_ == val)
            {
                return curr;
            }
            else if (val < curr->val_)
            {
                curr = curr->left_child_;
            }
            else
            {
                curr = curr->right_child_;
            }
            if (curr != nullptr)
            {
                last_check_ = curr;
            }
        }
        return nullptr;
    }

    void print(bin_tree_node<T>* node)
    {
        if (node == nullptr) return;
        print(node->left_child_);
        std::cout << node->val_ << std::endl;
        print(node->right_child_);
    }

    void print()
    {
        print(root_);
    }

    void to_vector(bin_tree_node<T>* node, std::vector<T>& vec)
    {
        if (node == nullptr) return;
        to_vector(node->left_child_, vec);
        vec.push_back(node->val_);
        to_vector(node->right_child_, vec);
    }

    void to_vector(std::vector<T>& vec)
    {
        vec.clear();
        to_vector(root_, vec);
    }
};