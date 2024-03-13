#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename Container>
void print(Container& cont, char c) {

	for (auto i = cont.begin(); i != cont.end(); ++i) {
		if (i != cont.begin()) {
			cout << c;
		}
		cout << *i;
	}
}

string frequent_word(string& text) {

	vector<string> vec = {};

	string tmp = "";

	text += ".";


	for (int i = 0; i != text.size(); ++i) {
		if (text[i] >= 65 and text[i] <= 90 or text[i] >= 97 and text[i] <= 122) {
			tmp += text[i];
		}

		else {
			if (tmp != "") {
				vec.push_back(tmp);
				tmp = "";
			}
			
		}
	}

	//print(vec, ' ');

	tmp = "";
	int c = 0;

	for (auto i = vec.begin(); i != vec.end(); ++i) {
		int ct = 0;
		for (auto j = vec.begin(); j != vec.end(); ++j) {
			if (*j == *i) {
				ct++;

			}
		}
		if (ct >= c) {
			if (ct == c) {
				if (*i < tmp) {
					tmp = *i;
				}
			}
			else {
				tmp = *i;
			}
			c = ct;
		}

		ct = 0;
	}

	return tmp;
}

int main() {

	string str = "aaa23123, 213 23213,, , ,, 3213 aaaa.aaaa.aaaa";
	
	cout << "freq word: " << frequent_word(str) << endl;;

	return 0;
}