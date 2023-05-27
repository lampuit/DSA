// bai_2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
    int data;
    node* pLeft;
    node* pRight;
};

typedef node* TREE;

void KhoiTaoTree(TREE& t)
{
    t = NULL;
}

void ThemVaoTree(TREE& t, int x)
{
    if (t == NULL)
    {
        TREE tmp =new node();
        tmp->data = x;
        tmp->pLeft = NULL;
        tmp->pRight = NULL;
        t = tmp;
    }
    else
    {
        if (x > t->data) ThemVaoTree(t->pRight, x);
        else if (x < t->data) ThemVaoTree(t->pLeft, x);
    }
}


int Height(TREE t, int& cnt)
{
        if (t == NULL) return -1;
        int a = Height(t->pLeft,cnt);
        int b = Height(t->pRight,cnt);
        return (a > b ? a : b) + 1;
}

int main()
{
    int n; cin >> n;
    TREE t;
    KhoiTaoTree(t);

    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        ThemVaoTree(t, x);
    }
    int cnt = 0;
    cout << Height(t, cnt);
}