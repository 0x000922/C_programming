#include <bits/stdc++.h>

using namespace std;

/*
    -program description

    - Union of char list - ( 3rd list ) linked list question
*/

class Node
{
public:
    char data;
    Node *next;
};

Node *newn(char k)
{
    Node *s = new Node;
    s->data = k;
    s->next = nullptr;
    
    return s;
}
void list_freq(Node *l, int *arr)
{
    Node *temp = l;
    while (temp != nullptr)
    {
        arr[temp->data - 'a'] = 1;
        temp = temp->next;
    }
}

void printlist(Node *l)
{
    Node* temp = l;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *makelist(char arr[], int k)
{
    Node *head = nullptr;
    Node *curr = nullptr;

    // if(arr[i] != 0)
    for (int i = 0; i < k; i++)
    {
        Node *a = newn(arr[i]);
        if (head == nullptr)
        {
            head = a;
            curr = a;
        }
        else
        {
            curr->next = a;
            curr = curr->next;
        }
    }
    // inserted[i] = true;
    // newarr[i] = 1;
    // }
    return head;
}
// make list from array
Node* mnew( int *arr)
{
    Node *head = nullptr;
    Node *curr = nullptr;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            Node *a = newn(i + 'a');
            if (head == nullptr)
            {
                head = a;
                curr = a;
            }
            else
            {
                curr->next = a;
                curr = curr->next;
            }
            // inserted[i] = true;
            // newarr[i] = 1;
        }
    }
    return head;
}
// make l1 U l2
Node *unionlist(int *l1, int *l2)
{
    bool inserted[26] = {};
    int newarr[26] = {};

    for (int i = 0; i < 26; i++)
    {
        if (l2[i] != 0 and !inserted[i])
        {
            inserted[i] = true;
            newarr[i] = 1;
        }
        if (l1[i] != 0 and !inserted[i])
        {
            inserted[i] = true;
            newarr[i] = 1;
        }
    }
    return mnew(newarr);
}
// Newlist - C
Node* subslist(int* l1, int* l2){
    int fi[26] = {};

    for(int i = 0; i < 26; i++)
    {
        if( l1[i] == 1 and l2[i] == 1)
        {
            
        }
        else if( l1[i] == 1)
        {
            fi[i] = 1;
        }
    }
    
    return mnew(fi);


}
Node *helper(Node *l1, Node *l2, Node *l3)
{
    int la1[26] = {}, la2[26] = {}, la3[26] = {}, la_U[26] = {};
    list_freq(l1, la1);
    list_freq(l2, la2);
    list_freq(l3, la3);

    Node *newlist_U = unionlist(la1, la2);
    list_freq(newlist_U, la_U);


    // printlist( newlist_U);
    return subslist(la_U, la3);
}

int main()
{

    char l1[] = {'a', 'd', 'e'};
    char l2[] = {'a', 'b', 'f', 'g'};
    char l3[] = { };

    Node* l1_list = makelist(l1, 3);
    Node* l2_list = makelist( l2, 4);
    Node* l3_list = makelist(l3, 0);
    
    Node* u  = helper(l1_list, l2_list, l3_list);
    printlist(u);

    return 0;
}