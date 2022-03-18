#include <iostream>
#include <vector>

using namespace std;

int era(int n, int k) {
	vector<bool> chk(n + 1, false);
	int m = 2;
	while (1) {
		for (int i = 1; i*m <= n; i++) {
			if (!chk[i*m]) {
				chk[i*m] = true;
				k--;
				if (k == 0) return i*m;
			}
		}
		m++;
	}
}


int main() {
	int N, K;
	cin >> N >> K;
	cout << era(N, K) << endl;
}