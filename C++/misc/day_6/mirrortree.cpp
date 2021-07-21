#include <bits/stdc++.h>

using namespace std;

/*
    -program description

    - 
*/

struct Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int k);
};

Node::Node(int k){
    data = k;
    left = nullptr;
    right = nullptr;    
}


bool check(Node* l, Node* r)
{
    bool flag = true; 
    if( l == nullptr and r == nullptr)
    {
        return true;
    }
    else if( l == nullptr || r == nullptr)
    {
        return false;
    }
    else
    {
        r->data = l->data;
        flag = flag and check(l->right, r->left);
        flag = flag and check( l->left, r->right);
    }

    return flag;
}


void mirrortree(Node* root)
{
    if(root == nullptr)
    {
        cout << -1 << endl;
        return;
    }
    if(root->left != nullptr and root->right != nullptr)
    {
        if(check(root->left, root->right))
        {
            cout << "yes";
        }
        else{
            cout << "no" ;
        }
    }
}
void inOrder(struct Node* node)
{
    if (node == NULL)
        return;
     
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}
void printLevelOrder(Node *root)
{
    // Base Case
    if (root == NULL)  return;
 
    // Create an empty queue for level order traversal
    queue<Node *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->right = new Node(7);
    root->right->left = new Node(8);
    root->left->left = new Node(5);
    root->left->right = new Node(4);

    printLevelOrder(root);
    cout << endl;

    mirrortree(root);
    inOrder(root);
    cout << endl;


    return 0;
}