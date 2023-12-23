#include <iostream>
using namespace std;

class Angelina {
    int16_t* g;
    int16_t n;
public:
    Angelina(int16_t size) {
        if(size != 0)
            g = new int16_t[size]{0};
        n = size;
    };
    void add(int16_t l) {

        if (-100 <= l && l <= 100) {
            int16_t* w = new int16_t[n + 1]{ 0 };
            for (int i = 0; i < n; i++) {
                *(w + i) = *(g + i);
            };
            *(w + n) = l;
            if (g != nullptr) {
                delete[] g;
            }
            g = w;
            n = n + 1;
        };
    };
    void sum(Angelina& sat1) {
        int a = min(n, sat1.n);
        for (int i=0; i<a; i++) {
           *(g + i) = *(g + i) + *(sat1.g + i);
        };
    };
    void raz(Angelina& sat1) {
        int a = min(n,sat1.n);
        for (int i=0; i<a ;i++) {
            *(g + i) = *(g + i) - *(sat1.g + i);
        };
    };
    Angelina(const Angelina& ang) : Angelina(ang.n) { 
        for (int i = 0; i < n; i++) {
            *(g + i) = *(ang.g + i);
        };
    };
    ~Angelina() {
        if (g != nullptr)
            delete [] g;
    };
    void print() {
        for (int i = 0; i<n; i++) {
            cout << *(g + i) << " ";
        };
        cout << endl;
    };
    void setter(int o, int16_t t) {
        if (-100 <= t && t <= 100 && 0<=o<n) {
            *(g + o) = t;
        };

    };
    int getter(int16_t e) {
        if (0 <= e && e <= n) {
            int y= *(g + e);
            return y;
        };
        return 0;
    };

};
int main()
{
    int e = 0;
    int el = 0;
    int kom = 0;
    int kom1 = 0;
    int kom2 = 0;
    int kom3 = 0;
    int kom4 = 0;

    cin >> e;
    Angelina fin = Angelina(e);
    for (int i = 0; i < e; i++) {
        cin >> el;
        fin.setter(i, el);
    };

    cin >> e;
    Angelina fin1 = Angelina(e); 
    for (int i = 0; i < e; i++) { 
        cin >> el; 
        fin1.setter(i, el);  
    };

    cin >> kom;
    for (int i =0; i<kom; i++) {
        cin >> kom1;

        switch (kom1) {
        case 1: 
            cin >> kom2 >> kom3;
            switch (kom2) {
            case 1:
                cout << fin.getter(kom3) << endl;
                break;
            case 2:
                cout << fin1.getter(kom3) << endl;
                break;
            }
            break;
        case 2:
            cin >> kom2 >> kom3 >> kom4; 
            switch (kom2) {
            case 1:
                fin.setter(kom3, kom4);
                break;
            case 2:
                fin1.setter(kom3, kom4);
                break;
            };
            break;
        case 3:
            cin >> kom2 >> kom3; 
            switch (kom2) {
            case 1:
                fin.add(kom3);
                break;
            case 2:
                fin1.add(kom3);
                break;
            };
            break;
        case 4:
            cin >> kom2;
            switch (kom2) {
            case 1:
                fin.print();
                break;
            case 2:
                fin1.print();
                break;
            };
            break;
        case 5:
            cin >> kom2;
            switch (kom2) {
            case 1:
                fin.sum(fin1);
                break;
            case 2:
                fin1.sum(fin);
                break;
            };
            break;
        case 6:
            cin >> kom2;
            switch (kom2) {
            case 1:
                fin.raz(fin1);
                break;
            case 2:
                fin1.raz(fin);
                break;
            };
            break;

        };
    };

};
