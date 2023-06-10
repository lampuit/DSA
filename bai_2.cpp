// bai_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
map<pair<char, char>, int> myMap;
vector <pair <char, char>> edge;
vector <char> adj[500];
int e;
char a, b;

void input()
{
    cin >> e;
    char u, v;
    int x;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> x;
        myMap.insert(make_pair(make_pair(u, v), x));
        edge.push_back(make_pair(u, v));  //edge.push_back({ u,v });
    }
    cin >> a >> b; // nhap dinh dau va dinh cuoi
}

bool check_2_dinh_ke_nhau(char u, char v)
{
    for (auto x : myMap)
    {
        if (u == x.first.first && v == x.first.second || u == x.first.second && v == x.first.first)
            return true;
        return false;
    }
}

void DanhSachCacDinhKeVoi1Dinh()
{

    for (auto x : edge)
    {
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }

    for (char i = 'A'; i< 'A' + e; i++)
    {
        if (!adj[i].empty())
        {
            cout << i << ": ";
            for (auto x : adj[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
        
    }
}
int main() {
    input();
    if (check_2_dinh_ke_nhau('A', 'B')) cout<<"\n2 dinh ke nhau.";
    else cout<<"\n2 dinh khong ke nhau.";
    cout << endl;

    cout << "Danh sach dinh ke." << endl;
    DanhSachCacDinhKeVoi1Dinh();
}
