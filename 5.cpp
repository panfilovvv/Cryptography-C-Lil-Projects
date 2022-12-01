#include <iostream>
#include<fstream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>
#include <algorithm>
#include <cctype>

using namespace std;
int cnt, M = 1, X = 0; vector<int> a, m, Ms, y, t;

map<char, string> alphabet = { {'�', "00000"}, {'�', "00001"}, {'�', "00010"}, {'�', "00011"}, {'�', "00100"}, {'�', "00101"},
                               {'�', "00101"}, {'�', "00110"}, {'�', "00111"}, {'�', "01000"}, {'�', "01001"}, {'�', "01010"}, 
                               {'�', "01011"}, {'�', "01100"}, {'�', "01101"}, {'�', "01110"}, {'�', "01111"}, {'�', "10000"},
                               {'�', "10001"}, {'�', "10010"}, {'�', "10011"}, {'�', "10100"}, {'�', "10101"}, {'�', "10110"}, 
                               {'�', "10111"}, {'�', "11000"}, {'�', "11001"}, {'�', "11010"}, {'�', "11011"}, {'�', "11100"},
                               {'�', "11101"}, {'�', "11110"}, {'�', "11111"}
};

map<string, char> alphabetrev = { {"00000", '�'}, {"00001", '�'}, {"00010", '�'}, {"00011", '�'}, {"00100", '�'}, {"00101", '�'},
                               {"00101", '�'}, {"00110", '�'}, {"00111", '�'}, {"01000", '�'}, {"01001", '�'}, {"01010", '�'},
                               {"01011", '�'}, {"01100", '�'}, {"01101", '�'}, {"01110", '�'}, {"01111", '�'}, {"10000", '�'},
                               {"10001", '�'}, {"10010", '�'}, {"10011", '�'}, {"10100", '�'}, {"10101", '�'}, {"10110", '�'},
                               {"10111", '�'}, {"11000", '�'}, {"11001", '�'}, {"11010", '�'}, {"11011", '�'}, {"11100", '�'},
                               {"11101", '�'}, {"11110", '�'}, {"11111", '�'}
};

int main()
{
    string command = "";
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    ifstream in("in.txt");
    do {
        fstream out1("out.txt"), key1("key.txt");
        cout << "1 - ����������� ����� �� �����, ���� ����� �� �������\n2 - ������������ ����� �� �����, ���� ������������ � �����\n0 - �����\n";
        cin >> command;
        string tmp, binOT = "", binK = "", ans = ""; int k;
        if (command == "1") {
            cout << "������� ������ �������� ������: "; cin >> tmp;
            for (int i = 0; i < tmp.length(); i++)
                if (tmp[i] < '0' || tmp[i] > '9') {
                    cout << "�������� ����\n"; return 0;
                }
            k = stoi(tmp);
            cout << "������� ���� ��� ��� ������ � �������� ����:\n"; cin >> tmp;
            for (int i = 0; i < tmp.length(); i++)
                if (tmp[i] < '0' || tmp[i] > '9') {
                    cout << "�������� ����\n"; return 0;
                }
            int t = k;
            binK = tmp;
            cout << "����������� �� �� �����... \n";
            while (getline(in, tmp)) {
                transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c) { return tolower(c); });
                for (int i = 0; i < tmp.length(); i++) {
                    if (tmp[i] >= '�' && tmp[i] <= '�' || tmp[i] == '�') {
                        binOT += alphabet[tmp[i]];
                    }
                }
            }
            cout << "������ �������� ������������������(��� �������������) � ������� ����������... \n";
            while (binK.length() % k != 0) binK += binK[binK.length() - 1 - k];
            int cip = 0;
            while (cip < binK.length()) {
                ans += (((int)binOT[cip] + (int)binK[cip]) % 2) + '0';
                cip++;
            }
            while (cip < binOT.length()) {
                int sum = 0;
                for (int i = 1; i <= k; i++) sum += ans[ans.length() - i] - '0';
                binK += (sum % 2) + '0';
                ans += ((binOT[cip] - '0') + (binK[cip] - '0')) % 2 + '0';
                cip++;
                for (int i = 0; i < k - 1 && cip < binOT.length(); i++) {
                    binK += binK[binK.length() - k - 1];
                    ans += ((binOT[cip] - '0') + (binK[cip] - '0')) % 2 + '0';
                    cip++;
                }
            }
            out1 << ans;
            key1 << binK;
            cout << "���������� ���������\n\n";
        }
        if (command == "2") {
            ifstream out("out.txt"), key("key.txt");
            string ans = "", ansb = "";
            cout << "������� ������ �������� ������: "; cin >> tmp;
            for (int i = 0; i < tmp.length(); i++)
                if (tmp[i] < '0' || tmp[i] > '9') {
                    cout << "�������� ����\n"; return 0;
                }
            k = stoi(tmp);
            cout << "������� ���� ��� ��� ������ � �������� ����:\n"; cin >> tmp;
            for (int i = 0; i < tmp.length(); i++)
                if (tmp[i] < '0' || tmp[i] > '9') {
                    cout << "�������� ����\n"; return 0;
                }
            out >> binOT; 
            binK = tmp;
            while (binK.length() % k != 0) binK += binK[binK.length() - 1 - k];
            int cip = 0;
            while (cip < binK.length()) {
                ans += (((int)binOT[cip] + (int)binK[cip]) % 2) + '0';
                cip++;
            }
            while (cip < binOT.length()) {
                int sum = 0;
                for (int i = 1; i <= k; i++) sum += binOT[ans.length() - i] - '0';
                binK += (sum % 2) + '0';
                ans += ((binOT[cip] - '0') + (binK[cip] - '0')) % 2 + '0';
                cip++;
                for (int i = 0; i < k - 1 && cip < binOT.length(); i++) {
                    binK += binK[binK.length() - k - 1];
                    ans += ((binOT[cip] - '0') + (binK[cip] - '0')) % 2 + '0';
                    cip++;
                }
            }
            for (int i = 0; i < ans.length(); i += 5) {
                ansb += alphabetrev[ans.substr(i, 5)];
            }
            cout << "�������� ������������������ ��: " << ans << "\n��������� ������������� ��: " << ansb << endl << "������������� ���������\n";
        }
    } while (command != "0");
}
