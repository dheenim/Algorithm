#include <iostream>
using namespace std;

int main() {
	int x; cin >> x;
	int bar = 64;
	int ans = 0;
	while (bar > 0) {
		if (bar & x) ans++;
		bar = bar >> 1;
	}
	cout << ans << endl;
}