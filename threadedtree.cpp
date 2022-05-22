#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    bool isThreaded;    
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->left = temp->right = NULL;
    temp->data = val;
    return temp;
}

Node* insert(Node *root, int value)
{
    if (root==NULL)
    {
        return newNode(value);
    }
    else if (value < root->data)
    {
        root->left=insert(root->left, value);
    }
    else
    {
        root->right=insert(root->right, value);
    }
    return root;
}

Node *createThreaded(Node *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL &&
        root->right == NULL)
        return root;
 
    if (root->left != NULL)
    {
        Node* l = createThreaded(root->left);
 
        l->right = root;
        l->isThreaded = true;
    }
 
    if (root->right == NULL)
        return root;
 
    return createThreaded(root->right);
}
 
Node *leftMost(Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
 
void inOrder(Node *root)
{
    if (root == NULL) return;
 
    Node *cur = leftMost(root);
 
    while (cur != NULL)
    {
        cout << cur->data << " ";
        if (cur->isThreaded)
            cur = cur->right;
 
        else 
            cur = leftMost(cur->right);
    }
}
 


int main()
{

    int choice = 1;
    Node *root=NULL;
    while (choice != 3)
    {
        
        cout << "-----------------" << endl;
        cout << "Binary Search tree" << endl;
        cout << "-----------------" << endl;
        cout << "1.Create" << endl;
        cout << "2.Convert Binary search tree into threaded binary tree" << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        if(choice>3){
            cout<<"INVALID INPUT\n";
        }
        else if (choice == 1)
        {
            cout << "Number of elements: ";
            int number_of_element;
            cin >> number_of_element;
            cout << endl;
            for (int i = 0; i < number_of_element; i++)
            {
                cout << "Number you want to insert: ";
                int num;
                cin >> num;
                root=insert(root, num);
            }
        }
        else if (choice == 2)
        {
            createThreaded(root);
            inOrder(root);
        }
        
    }
}
