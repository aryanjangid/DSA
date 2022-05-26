#include <iostream>
using namespace std;

//Define a structure
struct Node
{
    int data;
    Node *left;
    Node *right;
    bool isThreaded;    
};

//Function to make a new node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->left = temp->right = NULL;
    temp->data = val;
    return temp;
}

//insert new node 
Node* insert(Node *root, int value)
{
    if (root==NULL)//if root is NULL than make return a new node having the value val
    {
        return newNode(value);
    }
    else if (value < root->data)//if value is smaller than root->data then we move to the left side of the tree
    {
        root->left=insert(root->left, value);
    }
    else////if value is grater than root->data then we move to the right side of the tree
    {
        root->right=insert(root->right, value);
    }
    return root;
}

//Creatng threads to the tree
Node *createThreaded(Node *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)//if both left right node is null than we return root
        return root;
 
    if (root->left != NULL)//if root left is null than we point it to inorder predecessor 
    {
        Node* l = createThreaded(root->left);
 
        l->right = root;
        l->isThreaded = true;
    }
 
    if (root->right == NULL)////if root right is null than we point it to inorder successo 
        return root;
 
    return createThreaded(root->right);
}
 
//moving left
Node *leftMost(Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
 
 //inorder traversal
void inOrder(Node *root)
{
    if (root == NULL) return;
 
    Node *cur = leftMost(root);//move to leftmost node of the root
 
    while (cur != NULL)
    {
        cout << cur->data << " ";
        if (cur->isThreaded)//cheack wheather a node is threaded or not
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
