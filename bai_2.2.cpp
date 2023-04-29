

#include <iostream>
using namespace std;

struct DonThuc {
    float heso;
    float somu;
};
struct DaThuc {
    DonThuc a;
    DaThuc* next;
};

struct list {
    DaThuc* pHead;
    DaThuc* pTail;
    
};

void KhoiTao(list& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}


DaThuc* makeDaThuc(DonThuc p)
{
    DaThuc* tmp = new DaThuc();
    tmp->a = p;
    tmp->next = NULL;
    return tmp;
}

void InsertLast(list& l, DaThuc* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->next = p;
        l.pTail = p;
    }
}

void NhapDaThuc(list& l, int n)
{
    for (int i=0;i<n;i++)
    {
        DonThuc x;
        cout << "Nhap he so thu "<< i + 1<<": "; cin >> x.heso;
        cout << "Nhap so mu thu " << i + 1 << ": "; cin >> x.somu;
        DaThuc* p = makeDaThuc(x);
        InsertLast(l, p);
    }
}

void insert(list& l, float heso, float somu) {
   
    DaThuc* new_node = new DaThuc();
    new_node->a.heso = heso;
    new_node->a.somu = somu;
    new_node->next = NULL;

    if (l.pHead == NULL)
    {
        l.pHead = new_node;
    }
    else
    {
        DaThuc* current = l.pHead;
        while (current->next != NULL) current = current->next;
        current->next = new_node;
    }
}
void CongHaiDaThuc(list& l, list l1, list l2)
{
    DaThuc* p = l1.pHead;
    DaThuc* q = l2.pHead;
    
    while (p != nullptr && q != nullptr) {
        if (p->a.somu == q->a.somu) {
            float sum = p->a.heso + q->a.heso;
            insert(l, sum, p->a.somu);
            p = p->next;
            q = q->next;
        }
        else if (p->a.somu > q->a.somu) {
            insert(l, p->a.heso, p->a.somu);
            p = p->next;
        }
        else {
            insert(l, q->a.heso, q->a.somu);
            q = q->next;
        }
    }

    while (p != nullptr) {
        insert(l, p->a.heso, p->a.somu);
        p = p->next;
    }

    while (q != nullptr) {
        insert(l, q->a.heso, q->a.somu);
        q = q->next;
    }
}
void Xuat(list l)
{
    DaThuc* p; int dem = 0;
    for (p = l.pHead; p != NULL; p = p->next)
    {
        if (p->a.heso != 0)
            dem++;
        if (p->a.heso == 0)
            continue;

        if (p->a.heso > 0) {
            if (p->a.heso != 1) {
                if (dem == 1)
                    cout << p->a.heso;
                if (dem != 1)
                    cout << "+" << p->a.heso;
            }
            else if (p->a.heso == 1) {
                if (dem == 1 && p->a.somu == 0)
                    cout << 1;
                if (dem == 1 && p->a.somu != 0)
                    cout << "";
                if (dem != 1 && p->a.somu == 0)
                    cout << "+1";
                if (dem != 1 && p->a.somu != 0)
                    cout << "+";
            }
        }
        if (p->a.heso < 0) {
            if (p->a.heso != -1) {
                cout << p->a.heso;
            }
            if (p->a.heso == -1) {
                if (p->a.somu == 0)
                    cout << -1;
                if (p->a.somu != 0)
                    cout << "-";
            }
        }

        if (p->a.somu > 1)
            cout << "x^" << p->a.somu;
        if (p->a.somu == 1)
            cout << "x";

    }
    if (dem == 0)
        cout << 0;
 }
int main()
{
    list l, l1, l2; KhoiTao(l);
    KhoiTao(l1);
    int n; cout << "Nhap so luong don thuc cua da thuc: "; cin >> n;
    NhapDaThuc(l1,n);
    cout << "Da thuc thu 1: ";
    Xuat(l1);

    KhoiTao(l2);
    int m; cout << "\nNhap so luong don thuc cua da thuc: "; cin >> m;
    NhapDaThuc(l2,m);
    cout << "Da thuc thu 2: ";
    Xuat(l2);
   
    cout << "\nDa thuc sau khi cong la:";
    CongHaiDaThuc(l, l1, l2);
    Xuat(l);

    return 0;
}
