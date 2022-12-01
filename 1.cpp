#include <iostream>
#include <vector>
#include <string>
using namespace std;
int cnt, M= 1, X=0; vector<int> a, m, Ms, y, t;

bool isCoprime(int a, int b) {
    for (int gcd = a; ; gcd = b, b = a % b, a = gcd)
        if (!b) return gcd == 1;
}

bool simpl(vector<int> m) {
    for (int i = 0; i< m.size(); i++)
        for (int j = 0; j < m.size(); j++)
            if (i != j)
                if (!isCoprime(m[i], m[j])) return 0;
    return 1;
}

bool iscorrect(string s) {
    for (int i = 0; i < s.length(); i++) if (s[i] < 48 || s[i] > 57) return 0;
    return 1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string tmp; int iter = 0;
    cout << "Введите число уравнений: "; cin >> tmp;
    if (iscorrect(tmp)) cnt = stoi(tmp); else { cout << "Неверный ввод. \n"; return 0; }
    if (cnt < 1) { cout << "Решения нет"; return 0; }
    cout << "Введите коэффициенты для уравнений вида x = a (mod m):\n";
    while (cnt != 0) {
        iter++;
        cout << "Уравнение " << iter << ": ";
        cin >> tmp;
        if (iscorrect(tmp)) a.push_back(stoi(tmp)); else {cout << "Неверный ввод. \n"; return 0;}
        cin >> tmp; 
        if (iscorrect(tmp)) m.push_back(stoi(tmp)); else { cout << "Неверный ввод. \n"; return 0; }
        cnt--;
    }
    bool tocontinue = simpl(m);
    if (!tocontinue){ cout << "Введены не взаимно простые коэффициенты m. "; return 0;}
    for (int i = 0; i < m.size(); i++) M *= m[i];
    for (int i = 0; i < m.size(); i++) Ms.push_back(M/ m[i]);
    for (int i = 0; i < m.size(); i++) t.push_back(Ms[i] - m[i]*(Ms[i]/m[i]));
    for (int i = 0; i < m.size(); i++) {
        int sum = a[i];
        while (sum % t[i] != 0) sum += m[i];
        y.push_back(sum / t[i]);
    }
    for (int i = 0; i < m.size(); i++) X += Ms[i] * y[i];
    X %= M;
    cout << "Ответ: " << X << endl;
}
