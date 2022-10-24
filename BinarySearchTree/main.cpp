#include <iostream>
#include "BinarySearchTree.cpp"

using namespace std;

int main()
{
    TreeNode<int> tree;

    tree.insert(7);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(10);
    tree.insert(4);
    tree.insert(4);
    tree.insert(33);
    tree.insert(2);
    tree.insert(25);
    tree.insert(6);

    tree.display_post_order();

    cout << endl;

    tree.remove(10);
    tree.display_post_order();
}