#include <iostream>
#include <math.h>
using namespace std;

#define SWAP(type,x,y) do{type tmp=x;x=y;y=tmp;} while(0)

struct DonThuc {
    float heso;
    int somu;
};

struct DaThuc
{
    DonThuc A[50];
};

struct TraVe
{
    DaThuc X;
    int y;
};

void Nhap(DaThuc& a, int& n);
void Xuat(DaThuc a, int n);
void SapXepDaThuc(DaThuc& a, int n);
void TimBacDaThuc(DaThuc a, int n);
void TinhGiaTriCuaDaThuc(DaThuc a, int n);
TraVe CongHaiDaThuc(DaThuc a, DaThuc b, DaThuc& c, int n, int m);
TraVe TruHaiDaThuc(DaThuc a, DaThuc b, DaThuc& c, int n, int m);
DaThuc NhanHaiDaThuc(DaThuc a, DaThuc b, DaThuc& c, int n, int m);

int main()
{
    DaThuc a, b;
    int n, m;

    cout << "a.Nhap da thuc. ";
    Nhap(a, n);
    cout << "Da thuc sau khi nhap la: ";
    Xuat(a, n);

    cout << endl;
    cout << "\nb.Xac dinh bac cua da thuc.";
    TimBacDaThuc(a, n);


    cout << "\nSap xep da thuc theo bac giam dan. ";
    cout << "\nDa thuc sau khi sap xep: ";
    SapXepDaThuc(a, n);
    Xuat(a, n);

    cout << endl;
    cout << "\nc.Tinh gia tri cua da thuc vua nhap.";
    TinhGiaTriCuaDaThuc(a, n);
    cout << endl;

    cout << "\nd.Tim tong, hieu tich cua 2 da thuc." << endl;
    cout << "Nhap da thuc thu 2 can tinh. ";
    Nhap(b, m);
    cout << "Tong cua 2 da thuc la: ";
    DaThuc c;
    TraVe cong = CongHaiDaThuc(a, b, c, n, m);
    Xuat(cong.X, cong.y);

    cout << "\nHieu cua 2 da thuc la: ";
    TraVe tru = TruHaiDaThuc(a, b, c, n, m);
    Xuat(tru.X, tru.y);

    cout << "\nTich cua 2 da thuc la: ";
    NhanHaiDaThuc(a, b, c, n, m);
    Xuat(c, m * n);

    return 0;

}

void Nhap(DaThuc& a, int& n)
{
    cout << "\nNhap so phan tu cua da thuc: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap he so thu " << i + 1 << " : ";
        cin >> a.A[i].heso;
        cout << "Nhap so mu thu " << i + 1 << " : ";
        cin >> a.A[i].somu;
    }
}

void Xuat(DaThuc a, int n)
{
    int i = 0, dem = 0;
    for (i; i < n; i++) {
        if (a.A[i].heso != 0)
            dem++;
        if (a.A[i].heso == 0)
            continue;

        if (a.A[i].heso > 0) {
            if (a.A[i].heso != 1) {
                if (dem == 1)
                    cout << a.A[i].heso;
                if (dem != 1)
                    cout << "+" << a.A[i].heso;
            }
            else if (a.A[i].heso == 1) {
                if (dem == 1 && a.A[i].somu == 0)
                    cout << 1;
                if (dem == 1 && a.A[i].somu != 0)
                    cout << "";
                if (dem != 1 && a.A[i].somu == 0)
                    cout << "+1";
                if (dem != 1 && a.A[i].somu != 0)
                    cout << "+";
            }
        }
        if (a.A[i].heso < 0) {
            if (a.A[i].heso != -1) {
                cout << a.A[i].heso;
            }
            if (a.A[i].heso == -1) {
                if (a.A[i].somu == 0)
                    cout << -1;
                if (a.A[i].somu != 0)
                    cout << "-";
            }
        }

        if (a.A[i].somu > 1)
            cout << "x^" << a.A[i].somu;
        if (a.A[i].somu == 1)
            cout << "x";

    }
    if (dem == 0)
        cout << 0;
}

void SapXepDaThuc(DaThuc& a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a.A[i].somu < a.A[j].somu) SWAP(DonThuc, a.A[i], a.A[j]);
        }
    }
}

void TimBacDaThuc(DaThuc a, int n)
{
    int max = a.A[0].somu;
    for (int i = 1; i < n; i++)
    {
        if (a.A[i].somu > max) max = a.A[i].somu;
    }
    cout << "\nBac cua da thuc da cho la: " << max;
}

void TinhGiaTriCuaDaThuc(DaThuc a, int n)
{
    cout << "\nNhap gia tri cua bien so x: ";
    float x; cin >> x;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a.A[i].heso * pow(x, a.A[i].somu);
    }
    cout << "Gia tri cua da thuc da cho la: " << sum;
}

TraVe CongHaiDaThuc(DaThuc a, DaThuc b, DaThuc& c, int n, int m)
{
    SapXepDaThuc(b, m);

    int i = 0, j = 0, k = 0;

    while (i < n || j < m) {
        if (a.A[i].somu > b.A[j].somu)
        {
            c.A[k] = a.A[i];
            if (i < n)
                i++;
        }
        else if (a.A[i].somu < b.A[j].somu)
        {
            c.A[k] = b.A[j];
            if (j < m)
                j++;
        }

        else
        {
            c.A[k].heso = a.A[i].heso + b.A[j].heso;
            c.A[k].somu = a.A[i].somu;
            if (i < n)
                i++;
            if (j < m)
                j++;
        }
        k++;
    }

    c.A[k].heso = 0;
    c.A[k].somu = 0;

    TraVe v;
    v.X = c;
    v.y = k;

    return v;
}

TraVe TruHaiDaThuc(DaThuc a, DaThuc b, DaThuc& c, int n, int m)
{
    SapXepDaThuc(b, m);

    int i = 0, j = 0, k = 0;

    while (i < n || j < m) {
        if (a.A[i].somu > b.A[j].somu)
        {
            c.A[k] = a.A[i];
            i++;
        }
        else if (a.A[i].somu < b.A[j].somu)
        {
            c.A[k].heso = -b.A[j].heso;
            c.A[k].somu = b.A[j].somu;
            j++;
        }

        else
        {
            c.A[k].heso = a.A[i].heso - b.A[j].heso;
            c.A[k].somu = a.A[i].somu;
            i++;
            j++;
        }
        k++;
    }

    c.A[k].heso = 0;
    c.A[k].somu = 0;

    TraVe v;
    v.X = c;
    v.y = k;

    return v;
}

DaThuc NhanHaiDaThuc(DaThuc a, DaThuc b, DaThuc& c, int n, int m)
{
    SapXepDaThuc(b, m);

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c.A[k].heso = a.A[i].heso * b.A[j].heso;
            c.A[k].somu = a.A[i].somu + b.A[j].somu;
            k++;
        }
    }

    c.A[k].heso = 0;
    c.A[k].somu = 0;

    SapXepDaThuc(c, m * n);

    for (int i = 0; i < (m * n); i++) {
        for (int j = i + 1; j < (m * n); j++) {
            if (c.A[i].heso != 0 && c.A[j].heso != 0) {
                if (c.A[i].somu == c.A[j].somu) {
                    c.A[i].heso += c.A[j].heso;
                    c.A[j].heso = 0;
                }
            }
        }
    }

    return c;
}
