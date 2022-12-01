#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <windows.h>
#pragma hdrstop                  // Предоставляет дополнительный элемент управления по именам файлов предварительной компиляции и над местоположением на котором сохраняется состояние компиляции
using namespace std;
int osn = 10; bool tobreak;

map<char, string> alphabet = { {'а', "11"}, {'б', "12"}, {'в', "13"}, {'г', "14"}, {'д', "15"}, {'е', "16"}, {'ё', "17"}, {'ж', "18"},
							{'з', "19"}, {'и', "21"}, {'й', "22"}, {'к', "23"}, {'л', "24"}, {'м', "25"}, {'н', "26"}, {'о', "27"},
							{'п', "28"}, {'р', "29"}, {'с', "31"}, {'т', "32"}, {'у', "33"}, {'ф', "34"}, {'х', "35"}, {'ц', "36"},
							{'ч', "37"}, {'ш', "38"}, {'щ', "39"}, {'ъ', "41"}, {'ы', "42"}, {'ь', "43"}, {'э', "44"}, {'ю', "45"},
							{'я', "46"}, {'0', "47"}, {'1', "48"}, {'2', "49"}, {'3', "51"}, {'4', "52"}, {'5', "53"}, {'6', "54"},
							{'7', "55"}, {'8', "56"}, {'9', "57"}, {'.', "58"}, {',', "59"}, {'!', "61"}, {'?', "62"}, {';', "63"}, {'-', "64"}, {' ', "65"}, {'\n', "66"} };

map<char, char> lower = { {'А', 'а'}, {'Б', 'б'}, {'В', 'в'}, {'Г', 'г'}, {'Д', 'д'}, {'Е', 'е'}, {'Ё', 'ё'}, {'Ж', 'ж'}, {'З', 'з'},
						  {'И', 'и'}, {'Й', 'й'}, {'К', 'к'}, {'Л', 'л'}, {'М', 'м'}, {'Н', 'н'}, {'О', 'о'}, {'П', 'п'}, {'Р', 'р'},
						  {'С', 'с'}, {'Т', 'т'}, {'У', 'у'}, {'Ф', 'ф'}, {'Х', 'х'}, {'Ц', 'ц'}, {'Ч', 'ч'}, {'Ш', 'ш'}, {'Щ', 'щ'},
						  {'Ъ', 'ъ'}, {'Ы', 'ы'}, {'Ь', 'ь'}, {'Э', 'э'}, {'Ю', 'ю'}, {'Я', 'я'} };

map<string, char> alphabetrev = { {"11",'а'}, {"12",'б'}, {"13",'в'}, {"14",'г'}, {"15",'д'}, {"16",'е'}, {"17",'ё'}, {"18",'ж'},
							{"19",'з'}, {"21",'и'}, {"22",'й'}, {"23",'к'}, {"24",'л'}, {"25",'м'}, {"26",'н'}, {"27",'о'},
							{"28",'п'}, {"29",'р'}, {"31",'с'}, {"32",'т'}, {"33",'у'}, {"34",'ф'}, {"35",'х'}, {"36",'ц'},
							{"37",'ч'}, {"38",'ш'}, {"39",'щ'}, {"41",'ъ'}, {"42",'ы'}, {"43",'ь'}, {"44",'э'}, {"45",'ю'},
							{"46",'я'}, {"47",'0'}, {"48",'1'}, {"49",'2'}, {"51",'3'}, {"52",'4'}, {"53",'5'}, {"54",'6'},
							{"55",'7'}, {"56",'8'}, {"57",'9'}, {"58",'.'}, {"59",','}, {"61",'!'}, {"62",'?'}, {"63",';'}, {"64",'-'}, {"65",' '}, {"66", '\n'} };


string reducenulls(string a) {
	int iter = 0;
	while (iter < a.size() && a[iter] == '0') iter++;
	string tmp = "";
	if (iter == a.size()) return "0";
	a.erase(0, iter);
	return a;
}

bool lesser(string a, string b) {
	if (a.length() > b.length())
		return true;
	else if (a.length() < b.length())
		return false;
	else {
		int i = 0;
		while (a[i] == b[i] && i < a.length() - 1)
			i++;

		return (((a[i] > b[i]) && (i < a.length())) || ((i == a.length() - 1) && (a[i] >= b[i])));
	}
}

string mns(string u, string v, bool min = false) {
	if (!lesser(u, v)) return "-1";
	string tmp = "";
	if (v.length() < u.length()) {
		for (int i = 0; i < (u.length() - v.length()); i++) tmp += '0';
		v = tmp + v;
	}
	string ans;
	int n = u.size();
	int j = 0;
	int k = 0;
	while (j < n) {
		int f = u[n - j - 1] - '0';
		int s = v[n - j - 1] - '0';
		if (f + k < s) f += osn;
		int cur = (f - s + k) % osn;
		k = (((u[n - j - 1] - '0') - s + k - osn + 1) / osn);
		ans += (cur + '0');
		j++;
	}
	reverse(ans.begin(), ans.end());
	ans = reducenulls(ans);
	return ans;
}

string pls(string u, string v, bool min = false) {
	string tmp = "";
	if (u.length() < v.length()) {
		for (int i = 0; i < (v.length() - u.length()); i++) tmp += '0';
		u = tmp + u;
	}
	else
		if (v.length() < u.length()) {
			for (int i = 0; i < (u.length() - v.length()); i++) tmp += '0';
			v = tmp + v;
		}
	string ans = "";
	int n = v.length();
	int j = 0;
	int k = 0;
	int w = 0;
	while (j < n) {
		int a = u[n - j - 1] - '0';
		int b = v[n - j - 1] - '0';
		w = (a + b + k) % osn;
		k = (a + b + k) / osn;
		ans += to_string(w);
		j++;
	}
	if (k != 0)
		ans += "1";
	reverse(ans.begin(), ans.end());
	return ans;
}

string multi(string a, string b) {
	int m = a.length(), n = b.length(); int i, j, k, t;
	j = 0; string res;
	for (int i = 0; i < m + n; i++) res += '0';
	reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
	for (int j = 0; j < n; j++) {
		k = 0;
		if (b[j] != '0')
			for (int i = 0; i < m; i++) {
				int t = (a[i] - '0') * (b[j] - '0') + (res[i + j] - '0') + k;
				string tmp = to_string(t % osn);
				res[i + j] = tmp[0];
				k = round(t / osn);
			}
		if (k != 0) {
			string tmp = to_string(k);
			res[j + a.length()] = tmp[0];
		}
	}
	reverse(res.begin(), res.end()); res = reducenulls(res);
	return res;
}

bool incorrect(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] - 0 < 48)
			if (a[i] != '-') return false;
			else if (i != 0) return true;
		if (a[i] - 0 > 47 + osn && osn <= 10) return false;
		if (osn > 10) {
			if (a[i] - 0 > 64 + osn - 10) return false;
			if (a[i] - 0 < 65)
				if (a[i] - 0 > 57) return false;
		}
	}
	return true;
}

pair<string, string> shortdiv(string a, int b) {
	string r = "0"; int n = a.length(), j = 0;
	string w; for (int i = 0; i < a.length(); i++) w += '0';
	while (j < n) {
		w[j] = (((r[0] - '0') * osn + a[j] - '0') / b) + '0';
		r = (((r[0] - '0') * osn + a[j] - '0') % b) + '0';
		j++;
	}
	w = reducenulls(w);
	return make_pair(w, r);
}

string rev(string v) {
	reverse(v.begin(), v.end()); return v;
}

pair<string, string> division(string u, string v, bool remainder = false) {
	if (v == "0") return make_pair("Деление на ноль запрещено", "");
	if (u == "0") return make_pair("0", "0");
	if (mns(u, v) == "-1") return make_pair("0", u);
	//if (stold(u) < stold(v)) return make_pair("0", u);
	if (v.length() == 1) return shortdiv(u, stoi(v));
	int n = v.length();
	int m = u.length() - v.length();
	if (m < 0) return make_pair("0", v);
	string res = "";

	int d = osn / (v[0] - '0' + 1);
	if (d == 1) {
		u.insert(0, "0");
	}
	else {
		u = multi(u, to_string(d));
		v = multi(v, to_string(d));
	}
	if (u.length() != m + n + 1) {
		u.insert(0, "0");
	}

	reverse(u.begin(), u.end());
	reverse(v.begin(), v.end());
	bool flag;
	bool re;
	for (int j = m; j >= 0; j--) {
		int q = ((u[j + n] - '0') * osn + (u[j + n - 1] - '0')) / (v[n - 1] - '0');
		int r = ((u[j + n] - '0') * osn + (u[j + n - 1] - '0')) % (v[n - 1] - '0');
		do {
			flag = 1;
			if (n >= 2) {
				if (q == osn || q * (v[n - 2] - '0') > osn * r + (u[j + n - 2] - '0')) {
					q--;
					r += (v[n - 1] - '0');
					flag = 0;
				}
			}
			else if (q == osn) {
				q--;
				r += (v[n - 1] - '0');
				flag = 0;
			}
		} while (r < osn && !flag);

		string first = u.substr(j, j + n + 1);
		reverse(first.begin(), first.end());
		int pt = 0;
		while (first[pt] == '0' && pt != first.length() - 1) {
			pt++;
		}
		first.erase(0, pt);;
		string second = multi(to_string(q), v);
		reverse(v.begin(), v.end());
		if (mns(first, second, first.length()) != "-1") {
			re = true;
			string subRes = mns(first, second);
			reverse(subRes.begin(), subRes.end());
			while (subRes.length() < n + 1) {
				subRes += "0";
			}
			for (int i = j, it = 0; i <= j + n; i++, it++) {
				u[i] = subRes[it];
			}
		}
		else {
			first = rev(mns(second, first, second.length()));
			re = true;
			string newBstr = "1";
			for (int it = 0; it < n + 1; it++) {
				newBstr += "0";
			}
			first = mns(newBstr, first, newBstr.length());
			second = v;
			q--;
			reverse(second.begin(), second.end());
			string plsRes = pls(first, second);
			reverse(plsRes.begin(), plsRes.end());
			for (int i = j, it = 0; i <= j + n; i++, it++) {
				u[i] = plsRes[it];
			}
		}
		reverse(v.begin(), v.end());
		string tmp = to_string(q);
		res += tmp[0];
	}

	int p = 0;
	while (res[p] == '0' && p != res.length() - 1) {
		p++;
	}
	res.erase(0, p);

	string rem = "";
	if (!remainder) {
		string first = u.substr(0, n);
		if (re) {
			reverse(first.begin(), first.end());
		}
		p = 0;
		while (first[p] == '0' && p != first.length() - 1) {
			p++;
		}
		first.erase(0, p);
		rem = shortdiv(first, d).first;
	}
	return make_pair(res, rem);
}

//pair<string, string> division(string u, string v) {
//	string ans = ""; string remain;
//	u = reducenulls(u); v = reducenulls(v);
//	if (!(lesser(u, v))) return make_pair("0", u);
//	if (u == "0") return make_pair("0", "0");
//	int n = v.length(), m = u.length() - n;
//	int vo = v[0] - '0';
//	string d = shortdiv(to_string(osn), (vo + 1)).first;
//	if (d == "1") u = "0" + u;
//	else {
//		u = multi(u, d);
//		v = multi(v, d);
//	}
//	if (u.length() != m + n + 1) {
//		u = '0' + u;
//	}
//	v = rev(v); u = rev(u);
//	for (int j = m; j >= 0; j--) {
//		int ujn = u[j + n] - '0', ujni = u[j + n - 1] - '0', vni = v[n - 1] - '0';
//		int q = stoi(shortdiv(to_string(ujn * osn + ujni), vni).first), r = stoi(shortdiv(to_string(ujn * osn + ujni), vni).second);
//
//		if (q == osn) {
//			q--;
//			int vni = v[n - 1] - '0';
//			r = r + vni;
//		}
//		else if (n > 1) {
//			int vni = v[n - 1] - '0', vnii = v[n - 2] - '0', ujnii = u[j + n - 2] - '0';
//			if (q * vnii > osn * r + ujnii || q == osn) {
//				r = r + vni;
//				q--;
//			}
//		}
//		if (n > 1) {
//			int  vnii = v[n - 2] - '0', ujnii = u[j + n - 2] - '0';
//			while (!(r > osn || !(q * vnii > osn * r + ujnii))) {
//				if (q == osn) {
//					q--;
//					int vni = v[n - 1] - '0';
//					r = r + vni;
//				}
//				else if (n > 1) {
//					int vni = v[n - 1] - '0', vnii = v[n - 2] - '0', ujnii = u[j + n - 2] - '0';
//					if (q * vnii > osn * r + ujnii || q == osn) {
//						r = r + vni;
//						q--;
//					}
//				}
//			};
//		}
//		v = rev(v);
//		string fst = rev(u.substr(j, j + n + 1));
//		fst = reducenulls(fst);
//		string snd = multi(to_string(q), v); v = rev(v);
//		if (!lesser(fst, snd)) {
//			fst = mns(to_string(pow(osn, n + 1)), mns(snd, fst));
//			string added = rev(pls(fst, v));
//			q--;
//			int iter = 0;
//			for (int i = j; i <= j + n; i++) {
//				u[i] = added[iter]; iter++;
//			}
//		}
//		else {
//			string substracted = rev(mns(fst, snd));
//			while (substracted.length() <= n) 	substracted += "0";
//			int iter = 0;
//			for (int i = j; i <= j + n; i++) {
//				u[i] = substracted[iter]; iter++;
//			}
//		}
//		char razryad = '0' + q % osn;
//		ans = ans + razryad;
//	}
//	ans = reducenulls(ans);
//
//	string fr = rev(u.substr(0, n));
//	fr = reducenulls(fr); int dd = d[0] - '0';
//	remain = shortdiv(fr, dd).first;
//	return make_pair(ans, remain);
//}

string stepen(string x, string n, string m) {
	string N = n, Y = "1", Z = x;
	while (true) {
		int last = (N[N.length() - 1] - '0') % 2;
		N = shortdiv(N, 2).first;
		if (last == 1) {
			Y = multi(Y, Z);
		}
		if (N == "0") return division(Y, m).second;
		Z = division(multi(Z, Z), m).second;
	}
}

string juststepen(string x, string n) {
	string N = n, Y = "1", Z = x;
	while (true) {
		int last = (N[N.length() - 1] - '0') % 2;
		N = shortdiv(N, 2).first;
		if (last == 1) {
			Y = multi(Y, Z);
		}
		if (N == "0") return Y;
		Z = multi(Z, Z);
	}
}

string genrandom(string min, string max) {
	max = pls(max, "1");
	return pls(min, division(multi(mns(max, min), to_string(rand())), to_string(RAND_MAX)).first);
}

bool MillerRabin(string n, int rounds) {
	if (n == "2" || n == "3") return true;
	if (!(lesser(n, "2")) || (n[n.length() - 1] - '0') % 2 == 0) return false;
	string t = mns(n, "1"); int s = 0;
	while ((t[t.length() - 1] - '0') % 2 == 0) {
		t = shortdiv(t, 2).first;
		s++;
	}
	for (int i = 0; i < rounds; i++) {
		string rnd = genrandom("2", mns(n, "2"));
		string x = stepen(rnd, t, n);
		if (x == "1" || x == mns(n, "1")) continue;
		for (int r = 1; r < s; r++) {
			x = stepen(x, "2", n);
			if (x == "1") return false;
			if (x == mns(n, "1")) break;
		}
		if (x != mns(n, "1")) return true;
	}
	return false;
}

string eler(string n) {
	string result = n;
	for (string i = "2"; !lesser(multi(i, i), n); i = pls(i, "1"))
		if (division(n, i).second == "0") {
			while (division(n, i).second == "0")
				n = division(n, i).first;
			result = mns(result, division(result, i).first);
		}
	if (lesser(n, "1") && n != "1")
		result = mns(result, division(result, n).first);
	return result;
}

string generator(string p) {
	vector<string> fact;
	string phi = mns(p, "1"), n = phi;
	for (string i = "2"; !lesser(multi(i, i), n); i = pls(i, "1"))
		if (division(n, i).second == "0") {
			fact.push_back(i);
			while (division(n, i).second == "0")
				n = division(n, i).first;
		}
	if (lesser(n, "1"))
		fact.push_back(n);
	for (string res = "2"; !lesser(res, p); res = pls(res, "1")) {
		bool ok = true;
		for (size_t i = 0; i < fact.size() && ok; ++i)
			ok &= stepen(res, division(phi, fact[i]).first, p) != "1";
		if (ok)
			return res;
	}
	return "-1";
}

bool NODb(string a, string b) {
	string tmp;
	while (b != "0") {
		tmp = b;
		b = stepen(a, "1", b);
		a = tmp;
	}
	if (a == "1")
		return 1;
	else
		return 0;
}


string NOD(string a, string b) {
	if (((a[a.length() - 1] - '0') % 2 == 0) && ((b[b.length() - 1] - '0') % 2 == 0)) return "2";
	while (a != b) {
		if (lesser(a, b) && a != b) {
			a = mns(a, b);
		}
		else {
			b = mns(b, a);
		}
	}
	return a;
}


int main() {
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "russian");
	string op = "-", p; string s, text; vector<string> blocks;
	while (op != "0") {
		cout << "Введите операцию:\n 1 - зашифрование\n 2 - расшифрование\n 3 - генерация ключей\n 0 - завершение работы\n\n";
		cin >> op; cout << endl;
		if (op != "1" && op != "2" && op != "3" && op != "0") cout << "Такой команды мы не знаем!\n";
		if (op == "1") {
			ifstream in("opentext.txt");
			ofstream outt("cryptogram.txt");
			cout << "Введите p: ";
			cin >> p; cout << endl;
			if ((!incorrect(p))) {
				cout << "Неверный ввод. Исправьте файл с открытым текстом и повторите попытку.\n";
				continue;
			}
			while (!in.eof()) {
				string tmp; in >> tmp; s += " " + tmp;
			}
			s = s.substr(1);
			for (int i = 0; i < s.length(); i++) {
				if (alphabet.count(s[i]) != 0) text += alphabet[s[i]];
				else if (lower.count(s[i]) != 0) text += alphabet[lower[s[i]]];
			}

			int delta = 0;
			while (text != "") {
				while (!lesser(text.substr(0, delta), p) && delta <= text.size()) delta++;
				blocks.push_back(text.substr(0, --delta));
				text = text.substr(delta);
				delta = 0;
			}

			srand(time(NULL));
			string g = generator(p);
			string x = mns(p, "1");
			while (!NODb(x, mns(p, "1")))
				x = genrandom("2", mns(p, "2"));
			string y = stepen(g, x, p);
			//outt << p << " " << x << endl;
			for (int i = 0; i < blocks.size(); i++) {
				string k = mns(p, "1");
				while (!NODb(k, mns(p, "1")))
					k = genrandom("2", mns(p, "2"));
				string a = stepen(g, k, p);
				string b = division(multi(juststepen(y, k), blocks[i]), p).second;
				outt << a << " " << b << endl;
			}
			cout << "\nЗашифрование произошло успешно\n Закрытый ключ " + x + "\n";
			in.close(); outt.close();
		}
		if (op == "2") {
			ifstream inn("cryptogram.txt");
			ofstream out("decrypt.txt");
			string x; text = ""; string ans = "";
			cout << "Введите p и x: ";
			cin >> p >> x; cout << endl;
			if (!incorrect(p) || !incorrect(x)) {
				cout << "Неверный ввод. Исправьте файл с открытым текстом и повторите попытку.\n";
				continue;
			}
			string a, b;
			while (!inn.eof()) {
				inn >> a >> b;
				if (!incorrect(a) || !incorrect(b)) {
					cout << "Неверный ввод. Исправьте файл с открытым текстом и повторите попытку.\n";
					continue;
				}
				string aa = juststepen(a, mns(p, pls("1", x)));
				string m = division(multi(b, aa), p).second;
				text += m;
			}
			for (int i = 0; i < text.size(); i += 2) {
				string tmp;  tmp += text[i]; tmp += text[i + 1];
				ans += alphabetrev[tmp];
			}
			ans = ans.substr(0, ans.size() - 1);
			out << ans << endl;
			cout << "\nРасшифрование произошло успешно\n\n";
			inn.close(); out.close();
		}

		if (op == "3") {
			cout << "Введите p: "; cin >> p;
			while (!MillerRabin(p, 10) || lesser("4", p)) {
				if (lesser("4", p)) cout << "Вы ввели число, для которого невозможно вычислить g.\nОбращаем ваше внимание, что использование p, не отвечающего требованиям шифрсистемы в функциях зашифрования и расшифрования приведет к необычным последствиям, за корректность которых мы не ручаемся.\nПовторите попытку ввода p : ";
				else cout << "Ввод неверен или Вы ввели не простое число.\nОбращаем ваше внимание, что использование p, не отвечающего требованиям шифрсистемы в функциях зашифрования и расшифрования приведет к необычным последствиям, за корректность которых мы не ручаемся.\nПовторите попытку ввода p:";
				cin >> p;
			}
			string g = generator(p);
			string x = mns(p, "1");
			while (!NODb(x, mns(p, "1")))
				x = genrandom("2", mns(p, "2"));
			string y = stepen(g, x, p);
			cout << "g = " << g << endl << "x = " << x << endl << "y = " << y << endl;
		}
	}

	return 0;
}