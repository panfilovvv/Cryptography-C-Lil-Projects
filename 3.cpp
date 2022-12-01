#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>
using namespace std;
vector<unsigned int> npq;

void find(unsigned int n, unsigned int div)
{
    if (n==1)
        return;
    if (n%div == 0) {
        npq.push_back(div);
        find(n/div, div);
    }
    else if (div==2)
        find(n, div+1);
    else
        find(n, div+2);
}

unsigned int NOD(unsigned int n1, unsigned int n2)
{
    int div;
    if (n1 == n2)   
        return n1;
    int d = n1 - n2;
    if (d < 0) {
        d = -d;    
        div = NOD(n1, d);
    }
    else    
        div = NOD(n2, d); 
    return div;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    string  tmp; unsigned int n, e;
    cout << "Введите (n, e): "; cin >> tmp;
    for (int i = 0; i < tmp.length(); i++)
        if ((tmp[i] < '0' || tmp[i] > '9')) {
            cout << "Неверный ввод\n"; return 0;
        }
    n = stoul(tmp);
    cin >> tmp;
    for (int i = 0; i < tmp.length(); i++)
        if ((tmp[i] < '0' || tmp[i] > '9')) {
            cout << "Неверный ввод\n"; return 0;
        }
    e = stoul(tmp);
    find(n, 2);
    if (npq.size() != 2) {
        cout << "n не разложимо на 2 простых множителя!";
        return 0;
    }
    
    unsigned nodp = NOD(npq[0] - 1, e), nodq = NOD(npq[1] - 1, e);
    bool okay = (nodp == 1 && nodq == 1);
    cout << "Результаты: \nЧисло " << n << " = " << npq[0] << "*" << npq[1] << endl <<
        "НОД (p-1, e) = " << nodp << endl << "НОД (q-1, e) = " << nodq << endl;
    if (okay) cout << "Пара корректна\n"; else cout << "Пара некорректна!";
    return 0;
}
