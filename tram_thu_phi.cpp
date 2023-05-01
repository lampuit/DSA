#include <iostream>
#include <queue>
#include <string>
#include <windows.h>

using namespace std;

struct Xe {
    string loai;
};

int tinhPhi(Xe xe) {
    int phi = 0;
    if (xe.loai == "otonho") {
        phi = 5000;
    }
    else if (xe.loai == "ototrungbinh") {
        phi = 10000;
    }
    else if (xe.loai == "otolon") {
        phi = 15000;
    }
    else if (xe.loai == "otohangnang") {
        phi = 20000;
    }
    return phi;
}

int main() 
{
    queue<Xe> cong1, cong2, cong3, cong4;
    int tienCong1 = 0, tienCong2 = 0, tienCong3 = 0, tienCong4 = 0;
    int soLuongXe = 0;
    queue<Xe>* hangDoi;
    Xe xe;
    while (true) {
       
        cout << "Nhap loai xe (oto nho, oto trung binh, oto lon, oto hang nang): ";
        cin >> xe.loai;

        
        if (cong1.size() <= cong2.size() && cong1.size() <= cong3.size() && cong1.size() <= cong4.size()) {
            hangDoi = &cong1;
        }
        else if (cong2.size() <= cong1.size() && cong2.size() <= cong3.size() && cong2.size() <= cong4.size()) {
            hangDoi = &cong2;
        }
        else if (cong3.size() <= cong1.size() && cong3.size() <= cong2.size() && cong3.size() <= cong4.size()) {
            hangDoi = &cong3;
        }
        else {
            hangDoi = &cong4;
        }

        if (hangDoi->size() >= 10) {
            cout << "Hang doi cua cong " << (hangDoi - &cong1) + 1 << " da day. Vui long cho xe vao cong khac!" << endl;
            break;
        }
        else {
            hangDoi->push(xe);
            soLuongXe++;
            int phi = tinhPhi(xe);
            if (hangDoi == &cong1) {
                tienCong1 += phi;
                cout << "Xe da vao hang doi cua cong 1\n";

            }
            else if (hangDoi == &cong2) {
                tienCong2 += phi;
                cout << "Xe da vao hang doi cua cong 2\n";
            }
            else if (hangDoi == &cong3) {
                tienCong3 += phi;
                cout << "Xe da vao hang doi cua cong 3\n";
            }
            else {
                tienCong4 += phi;
                cout << "Xe da vao hang doi cua cong 4\n";
            }
        }


        cout << "Chon 1 de tiep tuc, Chon 0 de ket thuc. "<<endl; int lc; cin >>lc;
        if (lc == 0) break;
        
    }
    while (!hangDoi->empty())
    {
        
            if (xe.loai == "otonho" || xe.loai == "ototrungbinh") {
                cout << "Xe dang qua tram ... \n";
                hangDoi->pop();
                Sleep(10*1000);
                cout << "Xe da qua tram thanh cong! \n";
            }

            if (xe.loai == "otolon" || xe.loai == "otohangnang") {
                cout << "Xe dang qua tram... \n";
                hangDoi->pop();
                Sleep(15*1000);
                cout << "Xe da qua tram thanh cong! \n";
            }
        
    }
    
    cout << "So luong xe qua tram: " << soLuongXe << endl;
    cout << "Tong tien thu duoc cua cong 1: " << tienCong1 << endl;
    cout << "Tong tien thu duoc cua cong 2: " << tienCong2 << endl;
    cout << "Tong tien thu duoc cua cong 3: " << tienCong3 << endl;
    cout << "Tong tien thu duoc cua cong 4: " << tienCong4 << endl;

}
