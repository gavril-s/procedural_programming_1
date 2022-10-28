#pragma once
#include <iostream>

enum colors {black, red};

template <typename T>
struct rb_tree_node
{
    T val_=T();
    colors color_=black;
    rb_tree_node* parent_=nullptr;
    rb_tree_node* left_child_=nullptr;
    rb_tree_node* right_child_=nullptr;

    rb_tree_node(int val, colors color=black, rb_tree_node* parent=nullptr,
                 rb_tree_node* left_child=nullptr, 
                 rb_tree_node* right_child=nullptr)
    : val_(val), color_(color), parent_(parent),
      left_child_(left_child), right_child_(right_child) {}
};

template <typename T>
rb_tree_node<T>* grandparent(rb_tree_node<T>* node)
{
    if (node == nullptr || node->parent_ == nullptr)
    {
        return nullptr;
    }
    return node->parent_->parent_;
}

template <typename T>
rb_tree_node<T>* uncle(rb_tree_node<T>* node)
{
    rb_tree_node<T>* grandpa = grandparent(node);
    if (grandpa == nullptr)
    {
        return nullptr;
    }
    if (node->parent_ == grandpa->left_child_)
    {
        return grandpa->right_child_;
    }
    else
    {
        return grandpa->left_child_;
    }
}

template <typename T>
class rb_tree
{
private:
    rb_tree_node<T>* root_=nullptr;
    size_t size_=0;
    rb_tree_node<T>* last_check_=nullptr;

    void del_tree(rb_tree_node<T>* node)
    {
        if (node == nullptr) return;
        del_tree(node->left_child_);
        del_tree(node->right_child_);
        delete node;
    }

    void rotate_left(rb_tree_node<T>* node)
    {
        if (node == nullptr)
        {
            return;
        }
        rb_tree_node<T>* pivot = node->right_child_;
        pivot->parent_ = node->parent_;
        if (root_ == node)
        {
            root_ = pivot;
        }
        if (node->parent_ != nullptr)
        {
            if (node->parent_->left_child_ == node)
            {
                node->parent_->left_child_ = pivot;
            }
            else
            {
                node->parent_->right_child_ = pivot;
            }
        }

        node->right_child_ = pivot->left_child_;
        if (pivot->left_child_ != nullptr)
        {
            pivot->left_child_->parent_ = node;
        }
        node->parent_ = pivot;
        pivot->left_child_ = node;
    }
    
    void rotate_right(rb_tree_node<T>* node)
    {
        if (node == nullptr)
        {
            return;
        }
        rb_tree_node<T>* pivot = node->left_child_;
        pivot->parent_ = node->parent_;
        if (root_ == node)
        {
            root_ = pivot;
        }
        if (node->parent_ != nullptr)
        {
            if (node->parent_->left_child_ == node)
            {
                node->parent_->left_child_ = pivot;
            }
            else
            {
                node->parent_->right_child_ = pivot;
            }
        }

        node->left_child_ = pivot->right_child_;
        if (pivot->right_child_ != nullptr)
        {
            pivot->right_child_->parent_ = node;
        }
        node->parent_ = pivot;
        pivot->right_child_ = node;
    }

    void balance(rb_tree_node<T>* node)
    {
        if (node == nullptr)
        {
            return;
        }
        rb_tree_node<T>* unc = uncle(node);
        rb_tree_node<T>* grandpa = grandparent(node);
        if (node->parent_ == nullptr || root_ == node)
        {
            node->color_ = black;
        }
        else if (node->parent_->color_ == black)
        {
            return;
        }
        else if ((unc != nullptr) && (unc->color_ == red))
        {
            node->parent_->color_ = black;
            unc->color_ = black;
            if (grandpa != nullptr)
            {
                grandpa->color_ = red;
                balance(grandpa);
            }
        }
        else
        {
            if ((node == node->parent_->right_child_) && (node->parent_ == grandpa->left_child_))
            {
                rotate_left(node->parent_);
                node = node->left_child_;
            }
            else if ((node == node->parent_->left_child_) && (node->parent_ == grandpa->right_child_))
            {
                rotate_right(node->parent_);
            }

            node->parent_->color_ = black;
            grandpa->color_ = red;
            if ((node == node->parent_->left_child_) && (node->parent_ == grandpa->left_child_))
            {
                rotate_right(grandpa);
            }
            else
            {
                rotate_left(grandpa);
            }
        }
    }

public:
    ~rb_tree()
    {
        del_tree(root_);
    }

    rb_tree_node<T>* append(rb_tree_node<T>* parent, T val)
    {
        size_++;
        if (parent == nullptr || root_ == nullptr)
        {
            root_ = new rb_tree_node<T>(val, black);
            this->balance(root_);
            return root_;
        }
        rb_tree_node<T>* new_node = new rb_tree_node<T>(val, red, parent);
        if (new_node->val_ < parent->val_)
        {
            parent->left_child_ = new_node;
        }
        else
        {
            parent->right_child_ = new_node;
        }
        this->balance(new_node);
        return new_node;
    }

    rb_tree_node<T>* append(T val)
    {
        rb_tree_node<T>* search_res = this->find_leaf(val);
        if (search_res == nullptr)
        {
            return this->append(last_check_, val);
        }
        else
        {
            return this->append(search_res, val);
        }
    }

    rb_tree_node<T>* find(T val)
    {
        rb_tree_node<T>* curr = root_;
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

    rb_tree_node<T>* find_leaf(T val)
    {
        rb_tree_node<T>* curr = root_;
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

    void print(rb_tree_node<T>* node)
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

    void to_vec(rb_tree_node<T>* node, std::vector<T>& vec)
    {
        if (node == nullptr) return;
        to_vec(node->left_child_, vec);
        vec.push_back(node->val_);
        to_vec(node->right_child_, vec);
    }

    void to_vector(std::vector<T>& vec)
    {
        vec.clear();
        to_vec(root_, vec);
    }
};