#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

bool isCoprime(int a, int b) {
    for (int gcd = a; ; gcd = b, b = a % b, a = gcd)
        if (!b) return gcd == 1;
}


bool iscorrect(string s) {
    for (int i = 0; i < s.length(); i++) if (s[i] < 48 || s[i] > 57) return 0;
    return 1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string tmp1, tmp2; int n, b;
    cout << "Введите n и b: "; cin >> tmp1 >> tmp2;
    if (iscorrect(tmp1) && iscorrect(tmp2)) {
        n = stoi(tmp1);
        b = stoi(tmp2);
    }
    else { 
        cout << "Неверный ввод. \n"; 
        return 0; 
    }
    
    bool tocontinue = isCoprime(n, b);
    if (!tocontinue) {
        cout << "Введены не взаимно простые числа! "; 
        return 0; 
    }
    int k = pow(b, n - 1);
    bool isso = k % n == 1;
    cout << "Ответ: ";  
    isso ? cout << "n псевдопростое относительно b" : cout << "n НЕ псевдопростое относительно b"; 
    cout << endl;
}
