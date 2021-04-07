#include <iostream>
#include <regex>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string input;
		cin >> input;
		if (regex_match(input, regex("(100+1+|01)+")))
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}