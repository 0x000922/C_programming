#include <bits/stdc++.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x);
    TreeNode();

} node;

using namespace std;


TreeNode::TreeNode()
{
    left = nullptr;
    right = nullptr;

}


TreeNode::TreeNode(int x)
{
    val = x;
    left = nullptr;
    right = nullptr;

}
/*
    -program description


    - printing a BST in sorted order using recursion


*/

void print_sorted_order(node *root)
{
    if(root == nullptr)
        return;
    
    print_sorted_order(root->left);
    cout << root->val << " ";
    print_sorted_order(root->right);
    // cout << root->val << " ";


}

int main()
{
    
    node *a =  new node(3);
    node *b =  new node(2);
    
    // node c = node();

    a->left = b;
    // a.right = &c;
    
    print_sorted_order(a);
    return 0;
}