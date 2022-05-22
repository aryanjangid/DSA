#include <bits/stdc++.h>
using namespace std;

struct Node
{
  string data;
  vector<Node *> child;
};

Node *newNode(string key)
{
  Node *temp = new Node;
  temp->data = key;
  return temp;
}

Node *root;

void createTree()
{
  cout << "Enter name of book: ";

  string book_name;
  cin >> book_name;

  root = newNode(book_name);

  cout << "Enter no. of chapters in book: ";
  int number_of_chapter;
  cin >> number_of_chapter;

  for (int i = 0; i < number_of_chapter; i++)
  {
    cout << "Enter Chapter " << i + 1 << " name: ";

    string chapter_name;
    cin >> chapter_name;

    (root->child).push_back(newNode(chapter_name));
    cout << "Enter no. of sections in  Chapter " << root->child[i]->data << " : ";

    int number_of_sections;
    cin >> number_of_sections;
    for (int j = 0; j < number_of_sections; j++)
    {

      cout << "Enter Section " << j + 1 << " name: ";
      string section_name;
      cin >> section_name;
      (root->child[i]->child).push_back(newNode(section_name));
    }
  }
}

void displayTree(Node *root)
{
  if (root != NULL)
  {
    cout << "\n-----Book Hierarchy---";
    cout << "\nBook title : " << root->data;

    int number_of_chapter = (root->child).size();

    for (int i = 0; i < number_of_chapter; i++)
    {
      cout << "\n Chapter " << i + 1 << " : ";
      cout << root->child[i]->data << endl;

      cout << "  Sections: " << endl;
      int number_of_sections = (root->child[i]->child).size();

      for (int j = 0; j < number_of_sections; j++)
      {
        cout << "  " << root->child[i]->child[j]->data << endl;
      }
    }
  }
}


int main()
{
  int choice=1;
  while (choice != 3)
  {
    cout << "-----------------" << endl;
    cout << "Book Tree Creation" << endl;
    cout << "-----------------" << endl;
    cout << "1.Create" << endl;
    cout << "2.Display" << endl;
    cout << "3.Quit" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    if(choice==1){
      createTree();
    }
    else if(choice==2){
      displayTree(root);
    }
  }

  return 0;
}
