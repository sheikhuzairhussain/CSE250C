#include <iostream>

using namespace std;

template <typename T>
class TreeNode
{
    T value;
    bool hasValue;

public:
    TreeNode *left;
    TreeNode *right;

    TreeNode() : left(nullptr), right(nullptr), hasValue(false){};

    void insert(T value)
    {
        // Empty tree
        if (!hasValue)
        {
            this->value = value;
            this->hasValue = true;
            return;
        }

        // General case (prefer right if values are equal)
        if (value > this->value)
        {
            if (!this->right)
                this->right = new TreeNode();

            this->right->insert(value);
        }
        else if (value < this->value)
        {
            if (!this->left)
                this->left = new TreeNode();

            this->left->insert(value);
        }
        else
        {
            // Do nothing, since we're not allowing duplicates
        }
    }

    void display_pre_order()
    {
        cout << this->value << " ";

        if (this->has_left())
            this->left->display_pre_order();

        if (this->has_right())
            this->right->display_pre_order();
    }

    void display_in_order()
    {

        if (this->has_left())
            this->left->display_in_order();

        cout << this->value << " ";

        if (this->has_right())
            this->right->display_in_order();
    }

    void display_post_order()
    {
        if (this->has_left())
            this->left->display_post_order();

        if (this->has_right())
            this->right->display_post_order();

        cout << this->value << " ";
    }

    bool exists(T value)
    {
        if (this->value == value)
            return true;

        if (value > this->value && this->has_right())
            return this->right->exists(value);

        if (value < this->value && this->has_left())
            return this->left->exists(value);

        return false;
    }

    void remove(T value)
    {
        if (this->value == value)
        {
            // Case 1: Left subtree available
            if (this->has_left())
            {
                this->value = this->left->pop_largest();
                return;
            }

            // Case 2: Right subtree available
            if (this->has_right())
            {
                this->value = this->pop_smallest();
                return;
            }

            // Case 3: Leaf note
            this->hasValue = false;
            return;
        }

        if (value > this->value && this->right)
            return this->right->remove(value);

        if (value < this->value && this->left)
            return this->left->remove(value);

        cout << "Error: Value to delete does not exist.";
    }

private:
    bool has_left()
    {
        return this->left && this->left->hasValue;
    }

    bool has_right()
    {
        return this->right && this->right->hasValue;
    }

    T pop_largest()
    {
        while (this->has_right())
            return this->right->pop_largest();

        T largest = this->value;
        this->hasValue = false;

        return largest;
    }

    T pop_smallest()
    {
        while (this->has_left())
            return this->left->pop_smallest();

        T smallest = this->value;
        this->hasValue = false;

        return smallest;
    }
};