#include <iostream>

using namespace std;

template <typename T>
class TreeNode
{
public:
    T value;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T value, TreeNode *left = nullptr, TreeNode *right = nullptr) : value(value), left(left), right(right) {}

    void display_pre_order()
    {
        cout << this->value << " ";

        if (this->left)
            this->left->display_pre_order();

        if (this->right)
            this->right->display_pre_order();
    }

    void display_in_order()
    {

        if (this->left)
            this->left->display_in_order();

        cout << this->value << " ";

        if (this->right)
            this->right->display_in_order();
    }

    void display_post_order()
    {
        if (this->left)
            this->left->display_post_order();

        cout << this->value << " ";

        if (this->right)
            this->right->display_post_order();
    }
};