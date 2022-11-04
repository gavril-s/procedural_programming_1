#pragma once
#include <iostream>
#include <vector>

template <typename T>
struct avl_tree_node
{
    T val_=T();
    int height_=1;
    avl_tree_node* parent_=nullptr;
    avl_tree_node* left_child_=nullptr;
    avl_tree_node* right_child_=nullptr;

    avl_tree_node(int val,
                  avl_tree_node* parent=nullptr,
                  avl_tree_node* left_child=nullptr, 
                  avl_tree_node* right_child=nullptr)
    : val_(val), parent_(parent),
      left_child_(left_child), right_child_(right_child) {}
};

template <typename T>
int height(avl_tree_node<T>* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height_;
}

template <typename T>
void update_height(avl_tree_node<T>* node)
{
    if (node == nullptr)
    {
        return;
    }
    
    node->height_ = 1 + std::max(
        height(node->left_child_),
        height(node->right_child_));
    //update_height(node->parent_);
}

template <typename T>
void update_height_r(avl_tree_node<T>* node)
{
    if (node == nullptr)
    {
        return;
    }
    
    node->height_ = 1 + std::max(
        height(node->left_child_),
        height(node->right_child_));
    update_height_r(node->parent_);
}

template <typename T>
void update_height_d(avl_tree_node<T>* node)
{
    if (node == nullptr)
    {
        return;
    }

    update_height_d(node->left_child_);
    update_height_d(node->right_child_);
    
    node->height_ = 1 + std::max(
        height(node->left_child_),
        height(node->right_child_));
}

template <typename T>
int get_balance(avl_tree_node<T>* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->left_child_) - height(node->right_child_);
}

template <typename T>
avl_tree_node<T>* grandparent(avl_tree_node<T>* node)
{
    if (node == nullptr || node->parent_ == nullptr)
    {
        return nullptr;
    }
    return node->parent_->parent_;
}

template <typename T>
avl_tree_node<T>* uncle(avl_tree_node<T>* node)
{
    avl_tree_node<T>* grandpa = grandparent(node);
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
class avl_tree
{
private:
    avl_tree_node<T>* root_=nullptr;
    size_t size_=0;
    avl_tree_node<T>* last_check_=nullptr;

    void del_tree(avl_tree_node<T>* node)
    {
        if (node == nullptr) return;
        del_tree(node->left_child_);
        del_tree(node->right_child_);
        delete node;
    }

    void rotate_left(avl_tree_node<T>* node)
    {
        if (node == nullptr || node->right_child_ == nullptr)
        {
            return;
        }
        avl_tree_node<T>* pivot = node->right_child_;
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

        update_height(node);
        update_height(pivot);
    }
    
    void rotate_right(avl_tree_node<T>* node)
    {
        if (node == nullptr || node->left_child_ == nullptr)
        {
            return;
        }
        avl_tree_node<T>* pivot = node->left_child_;
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
        
        update_height(node);
        update_height(pivot);
    }

    void balance(avl_tree_node<T>* node)
    {
        if (node == nullptr || node->parent_ == nullptr)
        {
            return;
        }

        int blnc = get_balance(node->parent_);
        if (blnc > 1 && 
            node->parent_->val_ < node->parent_->left_child_->val_)
        {
            rotate_right(node);
        }
        if (blnc < -1 && 
            node->parent_->val_ > node->parent_->right_child_->val_)
        {
            rotate_left(node);
        }
        if (blnc > 1 &&
            node->parent_->val_ > node->parent_->left_child_->val_)
        {
            rotate_left(node->left_child_);
            rotate_right(node);
        }
        if (blnc < -1 && 
            node->parent_->val_ < node->parent_->right_child_->val_)
        {
            rotate_right(node->right_child_);
            rotate_left(node);
        }
    }

public:
    ~avl_tree()
    {
        del_tree(root_);
    }

    avl_tree_node<T>* insert(avl_tree_node<T>* parent, T val)
    {
        update_height_r(parent);
        size_++;
        if (parent == nullptr || root_ == nullptr)
        {
            root_ = new avl_tree_node<T>(val);
            this->balance(root_);
            return root_;
        }
        avl_tree_node<T>* new_node = new avl_tree_node<T>(val, parent);
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

    avl_tree_node<T>* insert(T val)
    {
        avl_tree_node<T>* search_res = this->find_leaf(val);
        if (search_res == nullptr)
        {
            return this->insert(last_check_, val);
        }
        else
        {
            return this->insert(search_res, val);
        }
    }

    avl_tree_node<T>* find_leaf(T val)
    {
        avl_tree_node<T>* curr = root_;
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

    avl_tree_node<T>* find(T val)
    {
        avl_tree_node<T>* curr = root_;
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

    void print(avl_tree_node<T>* node)
    {
        if (node == nullptr) return;
        print(node->left_child_);
        std::cout << node->val_ << " (" << node->height_ << ") "
                  << "parent: " << (node->parent_ == nullptr ? "NULL" : std::to_string(node->parent_->val_)) << std::endl;
        print(node->right_child_);
    }

    void print()
    {
        update_height_d(root_);
        print(root_);
    }

    int max_height()
    {
        update_height_d(root_);
        return root_->height_;
    }

    void to_vector(avl_tree_node<T>* node, std::vector<T>& vec)
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