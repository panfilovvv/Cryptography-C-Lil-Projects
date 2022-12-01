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

map<char, int> alphabet = { {'а', 0}, {'б', 1}, {'в', 2}, {'г', 3}, {'д', 4}, {'е', 5}, {'Є', 6}, {'ж', 7},
                            {'з', 8}, {'и', 9}, {'й', 10}, {'к', 11}, {'л', 12}, {'м', 13}, {'н', 14}, {'о', 15},
                            {'п', 16}, {'р', 17}, {'с', 18}, {'т', 19}, {'у', 20}, {'ф', 21}, {'х', 22}, {'ц', 23},
                            {'ч', 24}, {'ш', 25}, {'щ', 26}, {'ъ', 27}, {'ы', 28}, {'ь', 29}, {'э', 30}, {'ю', 31},
                            {'€', 32}
};

map<int, char> alphabetrev = { {0, 'а'}, {1, 'б'}, {2, 'в'}, {3, 'г'}, {4, 'д'}, {5, 'е'}, {6, 'Є'}, {7, 'ж'}, {8, 'з'},
                               {9, 'и'}, {10, 'й'}, {11, 'к'}, {12, 'л'}, {13, 'м'}, {14, 'н'}, {15, 'о'}, {16, 'п'}, {17, 'р'},
                               {18, 'с'}, {19, 'т'}, {20, 'у'}, {21, 'ф'}, {22, 'х'}, {23, 'ц'}, {24, 'ч'}, {25, 'ш'}, {26, 'щ'},
                               {27, 'ъ'}, {28, 'ы'}, {29, 'ь'}, {30, 'э'}, {31, 'ю'}, {32, '€'}
};

int main()
{
    int n = 33;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    ifstream in("in.txt");
    string tmp, ot, ans = ""; int k;
    cout << "¬ведите ключ:\n"; cin >> tmp;
    for (int i = 0; i < tmp.length(); i++)
        if (tmp[i] < '0' || tmp[i] > '9') {
            cout << "Ќеверный ввод\n"; return 0;
        }
    k = stoi(tmp);
    tmp = "";
    cout << "—читываетс€ ќ“ из файла ";
    cout << "ќтвет: ";
    while (getline(in, tmp)) {
        transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c) { return tolower(c); });
        ot = tmp;
        for (int i = 0; i < ot.length(); i++) {
            if (ot[i] >= 'а' && ot[i] <= '€' || ot[i] == 'Є') {
                int c = ((n + k - alphabet[ot[i]]) % n);
                ans += alphabetrev[c];
            }
        }
        cout << ans;
        ans = "";
    }
}
