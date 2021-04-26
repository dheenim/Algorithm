#include <iostream>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int ans = 210000000;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int n = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[j + i]) n++;
		}
		if (ans > n) ans = n;
	}
	cout << ans << endl;
}