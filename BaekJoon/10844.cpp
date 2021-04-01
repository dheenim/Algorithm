#include <iostream>

using namespace std;

long long arr[10][101];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i < 10; i++) {
		arr[i][1] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				arr[j][i] = arr[j + 1][i - 1] % 1000000000;
			}
			else if (j == 9) {
				arr[j][i] = arr[j - 1][i - 1] % 1000000000;
			}
			else {
				arr[j][i] = ((arr[j + 1][i - 1] % 1000000000) + (arr[j - 1][i - 1] % 1000000000)) % 1000000000;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += (arr[i][N] % 1000000000);
	}
	cout << ans % 1000000000 << endl;
}