#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <list>
using namespace std;


struct Slovnyk {
	map<string, list<string>> slova;

	void addWord() {
		list<string> l;
		string word;
		cout << "Vvedite slovo: ";
		cin >> word;
		string tmp;
		cout << "Vvedite znacheniya dannogo slova po odnomy, chtoby zavershit vvedite 0: " << endl;
		while (tmp != "0") {
			cin >> tmp;
			if (tmp != "0") {
				l.push_back(tmp);
			}
		}

		slova.insert(pair<string, list<string>>(word, l));
	}

	void show() {
		for (auto it = slova.begin(); it != slova.end(); it++) {
			cout << it->first << " - ";
			for (auto iter = it->second.begin(); iter != it->second.end(); iter++) {
				cout << *iter << " ";
			}
			cout << endl;
		}
	}

	void findWord(string w) {
		for (auto it = slova.begin(); it != slova.end(); it++) {
			if (it->first == w) {
				cout << it->first << " - ";
				for (auto iter = it->second.begin(); iter != it->second.end(); iter++) {
					cout << *iter;
				}
			}
		}
	}

	void delWord(string w) {
		map<string, list<string>>::iterator pos;
		pos = slova.find(w);
		if (pos != slova.end()) {
			slova.erase(pos);
		}
		else { cout << "Wrong word!" << endl; }
	}

	void redact() {
		cout << "=============================" << endl;
		string word;
		string descr;
		string descr2;
		cout << "enter word to change: ";
		cin >> word;
		cout << "enter description to change: ";
		cin >> descr;
		cout << "enter new description: ";
		cin >> descr2;

		for (auto it = slova.begin(); it != slova.end(); it++) {
			if (it->first == word) {
				for (auto iter = it->second.begin(); iter != it->second.end(); iter++) {
					if (*iter == descr) {
						*iter = descr2;
					}
				}
			}
		}
		cout << "=============================" << endl;
	}

	void toTxt() {
		fstream write;
		write.open("123.txt", ios::out);
		for (auto it = slova.begin(); it != slova.end(); it++) {
			write << it->first<<" - ";
			for (auto iter = it->second.begin(); iter != it->second.end(); iter++) {
				write << *iter<<" ";
			}
			write << endl;
		}
	}
};


void main() {

	Slovnyk slovar;

	slovar.addWord();
	slovar.addWord();

	slovar.show();

	string tmp;
	cout << "enter word to find: ";
	cin >> tmp;
	slovar.findWord(tmp);
	cout << endl;

	cout << "enter word to delete: ";
	cin >> tmp;
	slovar.delWord(tmp);

	slovar.show();

	slovar.redact();
	slovar.show();

	slovar.toTxt();
	system("pause");
}