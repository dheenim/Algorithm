#include <iostream>
#define MAX(a,b) ((a)>(b))?(a):(b)
using namespace std;

int main() {
	int row, col;
	string input[50];
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		cin >> input[i];
	}
	int k;
	int ans = 0;
	cin >> k;
	for (int r = 0; r < row; r++) {
		int zerocnt = 0;
		for (int c = 0; c < col; c++) {
			if (input[r][c] == '0') zerocnt++;
		}
		int on = 0;
		if (zerocnt <= k && zerocnt % 2 == k % 2) {
			for (int ro = 0; ro < row; ro++) {
				if (input[ro] == input[r]) {
					on++;
				}
			}
		}
		ans = MAX(ans, on);
	}
	cout << ans << endl;
	return 0;
}