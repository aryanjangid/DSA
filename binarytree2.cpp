#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
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


bool search(Node *root, int target)
{
    if (!root)
        return NULL;
    if (root->data == target)
        return true;

    if (target < root->data)
    {
        search(root->left, target);
    }
    else
    {
        search(root->right, target);
    }
}


int minvalue(Node *root)
{
    if (!root)
        return 0;
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

int main()
{

    int choice = 1;
    Node *root=NULL;
    while (choice != 4)
    {
        
        cout << "-----------------" << endl;
        cout << "Binary Search tree" << endl;
        cout << "-----------------" << endl;
        cout << "1.Create" << endl;
        cout << "2.Insert" << endl;
        cout << "3.Minimum value in tree: " << endl;
        cout << "4.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        if(choice>4){
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
            cout << "Number you want to insert: ";
            int num;
            cin >> num;
            root=insert(root, num);
            cout << "\nInsert successful"<<endl;
        }
        else if (choice == 3)
        {
            cout << "Smallest Node: ";
            cout << minvalue(root) << endl;
        }
    }
}
