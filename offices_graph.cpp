#include <bits/stdc++.h>
using namespace std;

vector<string> offices;
vector<vector<int>> matrix;

void create()
{
    cout << "Enter number of offices: ";
    int number_of_offices;
    cin >> number_of_offices;
    vector<vector<int>> temp(number_of_offices, vector<int>(number_of_offices, 0));
    matrix = temp;

    for (int i = 1; i <= number_of_offices; i++)
    {
        cout << "Enter the office " << i << " name: ";
        string city;
        cin >> city;
        offices.push_back(city);
    }

    for (int i = 0; i < number_of_offices; i++)
    {
        for (int j = 0; j < number_of_offices; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 0;
                continue;
            }
            if(matrix[i][j]!=0){
                continue;
            }
            cout << "Enter time to reach " << offices[i] << " to " << offices[j] << " : ";
            int time;
            cin >> time;
            matrix[i][j] = time;
            matrix[j][i] = time;
        }
    }
}

void display()
{
    cout << "* ";
    for (int i = 0; i < offices.size(); i++)
    {
        cout << offices[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << offices[i] << " ";
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int prim(){
    int n=offices.size();
    vector<int>parent(n,-1),key(n,INT_MAX),mst(n,0);
    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<n-1;count++){
        int mini=INT_MAX,u;
        for(int v=0;v<n;v++){
            if(mst[v] == 0 && key[v]<mini){
                mini=key[v];
                u=v;
            }
        }
        mst[u]=1;
        for(int i=0;i<n;i++){
            if(matrix[u][i]!=0){
                int v=i;
                int cost=matrix[u][i];
                if(mst[v]==false && cost<key[v]){
                    parent[v]=u;
                    key[v]=cost;
                }
            }
        }
    }

    int sum=0;
    for(auto i:key){
        sum+=i;
    }
    return sum;
}

int main()
{
    int choice = 1;
    while (choice != 4)
    {
        cout << "-----------------" << endl;
        cout << "Flights" << endl;
        cout << "-----------------" << endl;
        cout << "1.Create Matrix" << endl;
        cout << "2.Display" << endl;
        cout << "3.Calculate minimum cost" << endl;
        cout << "4.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            create();
        }
        else if (choice == 2)
        {
            display();
        }
        else if (choice == 3)
        {
            int min_cost=prim();
            cout<<min_cost<<endl;
        }
    }
}