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

map<char, string> alphabet = { {'а', "00000"}, {'б', "00001"}, {'в', "00010"}, {'г', "00011"}, {'д', "00100"}, {'е', "00101"},
                               {'ё', "00101"}, {'ж', "00110"}, {'з', "00111"}, {'и', "01000"}, {'й', "01001"}, {'к', "01010"},
                               {'л', "01011"}, {'м', "01100"}, {'н', "01101"}, {'о', "01110"}, {'п', "01111"}, {'р', "10000"},
                               {'с', "10001"}, {'т', "10010"}, {'у', "10011"}, {'ф', "10100"}, {'х', "10101"}, {'ц', "10110"},
                               {'ч', "10111"}, {'ш', "11000"}, {'щ', "11001"}, {'ъ', "11010"}, {'ы', "11011"}, {'ь', "11100"},
                               {'э', "11101"}, {'ю', "11110"}, {'я', "11111"}
};

map<string, char> alphabetrev = { {"00000", 'а'}, {"00001", 'б'}, {"00010", 'в'}, {"00011", 'г'}, {"00100", 'д'}, {"00101", 'е'},
                               {"00101", 'ё'}, {"00110", 'ж'}, {"00111", 'з'}, {"01000", 'и'}, {"01001", 'й'}, {"01010", 'к'},
                               {"01011", 'л'}, {"01100", 'м'}, {"01101", 'н'}, {"01110", 'о'}, {"01111", 'п'}, {"10000", 'р'},
                               {"10001", 'с'}, {"10010", 'т'}, {"10011", 'у'}, {"10100", 'ф'}, {"10101", 'х'}, {"10110", 'ц'},
                               {"10111", 'ч'}, {"11000", 'ш'}, {"11001", 'щ'}, {"11010", 'ъ'}, {"11011", 'ы'}, {"11100", 'ь'},
                               {"11101", 'э'}, {"11110", 'ю'}, {"11111", 'я'}
};

int main()
{
    string command = "";
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    ifstream in("in.txt");
    do {
        bool available = true;
        fstream out1("out.txt"), key1("key.txt");
        cout << "1 - зашифровать текст из файла, ввод ключа из консоли\n2 - расшифровать текст из файла, ключ сгенерирован в файле\n0 - выход\n";
        cin >> command;
        string tmp, binOT = "", binK = "", ans = ""; int k;
        if (command == "1") {
            cout << "Введите размер регистра сдвига: "; cin >> tmp;
            for (int i = 0; i < tmp.length(); i++)
                if (tmp[i] < '0' || tmp[i] > '9') {
                    cout << "Неверный ввод\n"; return 0;
                }
            k = stoi(tmp);
            cout << "Введите ключ или его начало в ДВОИЧНОМ виде:\n"; cin >> tmp;
            for (int i = 0; i < tmp.length(); i++)
                if (tmp[i] < '0' || tmp[i] > '9') {
                    cout << "Неверный ввод\n"; return 0;
                }
            int t = k;
            binK = tmp;
            cout << "Считывается ОТ из файла... \n";
            while (getline(in, tmp)) {
                transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c) { return tolower(c); });
                for (int i = 0; i < tmp.length(); i++) {
                    if (tmp[i] >= 'а' && tmp[i] <= 'я' || tmp[i] == 'ё') {
                        binOT += alphabet[tmp[i]];
                    }
                }
            }
            for (int i = k * (binK.length() / k) + 1; i < binK.length(); i++) {
                if (binK[i - 1 - k] != binK[i]) {
                    cout << "РСЛОС невозможен\n";
                    available = 0;
                    break;
                }
            }
            if (available) {
                cout << "Расчет ключевой последовательности(при необходимости) и подсчет результата... \n";
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
                cout << "Шифрование закончено\n\n";
            }
        }
        if (command == "2") {
            ifstream out("out.txt"), key("key.txt");
            string ans = "", ansb = "";
            cout << "Введите размер регистра сдвига: "; cin >> tmp;
            for (int i = 0; i < tmp.length(); i++)
                if (tmp[i] < '0' || tmp[i] > '9') {
                    cout << "Неверный ввод\n"; return 0;
                }
            k = stoi(tmp);
            cout << "Введите ключ или его начало в ДВОИЧНОМ виде:\n"; cin >> tmp;
            for (int i = 0; i < tmp.length(); i++)
                if (tmp[i] < '0' || tmp[i] > '9') {
                    cout << "Неверный ввод\n"; return 0;
                }
            binK = tmp;
            for (int i = k * (binK.length() / k) + 1; i < binK.length(); i++) {
                if (binK[i - 1 - k] != binK[i]) {
                    cout << "РСЛОС невозможен\n";
                    available = 0;
                    break;
                }
            }
            if (available) {
                out >> binOT;
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
                cout << "Двоичная последовательность ОТ: " << ans << "\nБуквенное представление ОТ: " << ansb << endl << "Расшифрование закончено\n";
            }
        }
    } while (command != "0");
}
