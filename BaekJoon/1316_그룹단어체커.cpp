#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		bool chk = true;
		set<char> s;
		s.insert(input[0]);
		for (int j = 1; j < input.length(); j++) {
			if (input[j] != input[j - 1]) {
				auto ret = s.insert(input[j]);
				if (!ret.second) {
					chk = false;
					break;
				}
			}
		}
		if (chk) ans++;
	}
	cout << ans << endl;
}