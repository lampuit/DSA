#include <iostream>
using namespace std;

void SuaHangRao(int a[], int b[], int n, int m)
{
    int k = 0;
    int* c = new int[n + m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c[k] = a[i] + b[j];
            k++;
        }
    }
    int hmax = 0; int kqhmax=0;
    int dem = 0, tmp = 0;
    for (int f = 0; f < n * m; f ++)
    {
        dem = 0;
        int i = 0; int j = 0;
        hmax = c[f];
        while (i<n && j<m)
        {
            if (a[i] >= hmax)
            {
                i++;
                continue;
            }
            if (a[i] + b[j] >= hmax)
            {
                dem++;
                i++;
                j++;
            }
            else j++;
        }
        if (dem > tmp)
        {
            tmp = dem;
            kqhmax = hmax;
        }
    }
    cout << kqhmax << " " << tmp << endl;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] >= kqhmax)
        {
            i++;
            continue;
        }
        if (a[i] + b[j] >= kqhmax)
        {
            cout << i+1 << " " << j+1 << endl;
            i++;
            j++;
        }
        else j++;
    }
}

int main()
{
    //cout << "Nhap so tam go da duoc ghep thanh hang rao:  ";
    int n; cin >> n;
    int* a = new int [n];
    //cout << "Nhap chieu cao cua moi tam go cua hang rao do: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    //cout << "Nhap so tam go con thua: ";
    int m; cin >> m;
    int* b = new int [m];
    for (int j = 0; j < m; j++) cin >> b[j];
    SuaHangRao(a, b, n, m);
    return  0;
}