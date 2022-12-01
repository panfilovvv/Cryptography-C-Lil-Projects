#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>
#include <algorithm>
#include <cctype>
using namespace std;
int cnt, M = 1, X = 0; vector<int> a, m, Ms, y, t;

map<char, int> alphabet = { {'�', 0}, {'�', 1}, {'�', 2}, {'�', 3}, {'�', 4}, {'�', 5}, {'�', 6}, {'�', 7},
                            {'�', 8}, {'�', 9}, {'�', 10}, {'�', 11}, {'�', 12}, {'�', 13}, {'�', 14}, {'�', 15},
                            {'�', 16}, {'�', 17}, {'�', 18}, {'�', 19}, {'�', 20}, {'�', 21}, {'�', 22}, {'�', 23},
                            {'�', 24}, {'�', 25}, {'�', 26}, {'�', 27}, {'�', 28}, {'�', 29}, {'�', 30}, {'�', 31},
                            {'�', 32}
};

map<int, char> alphabetrev = { {0, '�'}, {1, '�'}, {2, '�'}, {3, '�'}, {4, '�'}, {5, '�'}, {6, '�'}, {7, '�'}, {8, '�'},
                               {9, '�'}, {10, '�'}, {11, '�'}, {12, '�'}, {13, '�'}, {14, '�'}, {15, '�'}, {16, '�'}, {17, '�'},
                               {18, '�'}, {19, '�'}, {20, '�'}, {21, '�'}, {22, '�'}, {23, '�'}, {24, '�'}, {25, '�'}, {26, '�'},
                               {27, '�'}, {28, '�'}, {29, '�'}, {30, '�'}, {31, '�'}, {32, '�'}
};

int main()
{
    int n = 33;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    string tmp, ot, ans = ""; int k;
    cout << "������� �� "; cin >> tmp;
    transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c) { return tolower(c); });
    for (int i = 0; i < tmp.length(); i++)
        if ((tmp[i] < '�' || tmp[i] > '�') && tmp[i] != '�') {
            cout << "�������� ����\n"; return 0;
        }
    ot = tmp;
    cout << "������� ����:\n"; cin >> tmp;
    for (int i = 0; i < tmp.length(); i++)
        if (tmp[i] < '0' || tmp[i] > '9') {
            cout << "�������� ����\n"; return 0;
        }
    k = stoi(tmp);
    for (int i = 0; i < ot.length(); i++) {
        int c = ((n + k - alphabet[ot[i]]) % n);
        ans += alphabetrev[c];
    }
    cout << "�����: " << ans << endl;
}
