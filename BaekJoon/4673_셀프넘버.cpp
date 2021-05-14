#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	bool chk[10001];
	memset(chk, 0, sizeof(chk));
	for (int num = 1; num < 10000; num++) {
		int sum = num, tmp = num;
		int div = 1000;
		while (div > 0) {
			int t = tmp / div;
			if (t) {
				sum += (tmp / div);
				tmp = tmp - (tmp / div) * div;
			}
			div /= 10;
		}
		if (sum < 10000) chk[sum] = true;
	}
	for (int i = 1; i <= 10000; i++) {
		if (!chk[i]) cout << i << "\n";
	}
}
