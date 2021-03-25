#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	string str;
	set<string> ans;
	cin >> str;
	for (int i = 1; i <= str.length(); i++) {
		for (int j = 0; j < str.length(); j++) {
			if (i + j > str.length()) break;
			ans.insert(str.substr(j, i));
		}
	}
	/*for (set<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}*/
	cout << ans.size();
}