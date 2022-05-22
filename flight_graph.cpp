#include <bits/stdc++.h>
using namespace std;

vector<string> cities;
vector<vector<int>> matrix;

void create()
{
    cout << "Enter number of cities: ";
    int number_of_cities;
    cin >> number_of_cities;
    vector<vector<int>> temp(number_of_cities, vector<int>(number_of_cities, 0));
    matrix = temp;

    for (int i = 1; i <= number_of_cities; i++)
    {
        cout << "Enter the city " << i << " name: ";
        string city;
        cin >> city;
        cities.push_back(city);
    }

    for (int i = 0; i < number_of_cities; i++)
    {
        for (int j = 0; j < number_of_cities; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 0;
                continue;
            }
            cout << "Enter time to reach " << cities[i] << " to " << cities[j] << " : ";
            int time;
            cin >> time;
            matrix[i][j] = time;
        }
    }
}

void display()
{
    cout << "* ";
    for (int i = 0; i < cities.size(); i++)
    {
        cout << cities[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << cities[i] << " ";
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool check()
{
    vector<int> visit(cities.size(), 0);

    string start;
    int index;
    cout << "\nEnter starting city: ";
    cin >> start;
    for (int i = 0; i < cities.size(); i++)
        if (start == cities[i])
            index = i;

    visit[index] = 1;
    int current = index;
    queue<int> q;
    for (int i = 0; i < cities.size(); i++)
    {
        if (matrix[current][i] != 0 && visit[i] == 0)
        {
            q.push(i);
            visit[i] = 1;
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < cities.size(); i++)
        {
            if (matrix[curr][i] != 0 && visit[i] == 0)
            {
                visit[i] = 1;
                q.push(i);
            }
        }
    }
    bool flag = 1;
    for (int i = 0; i < visit.size(); i++)
    {
        if (visit[i] == 0)
        {
            flag = 0;
        }
    }
    return flag;
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
        cout << "3.Check whether graph is connected or not" << endl;
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
            bool flag = check();
            if (flag == 1)
            {
                cout << "..........Yes the graph is connected.........." << endl;
            }
            else
            {
                cout << "..........No !! the graph is not connected.........." << endl;
            }
        }
    }
}