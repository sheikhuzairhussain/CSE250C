#include "BinaryTree.cpp"

using namespace std;

int main()
{
  /**************
       1
     /  \
    2    3
   / \  / \
  4  5 6   7
  **************/

  // Bottom-up approach
  TreeNode<int> v4(40);
  TreeNode<int> v5(50);
  TreeNode<int> v6(60);
  TreeNode<int> v7(70);

  TreeNode<int> v2(20, &v4, &v5);
  TreeNode<int> v3(30, &v6, &v7);

  TreeNode<int> root(10, &v2, &v3);

  cout << "Pre-order: ";
  root.display_pre_order();

  cout << endl;

  cout << "In-order: ";
  root.display_in_order();

  cout << endl;

  cout << "Post-order: ";
  root.display_post_order();
}