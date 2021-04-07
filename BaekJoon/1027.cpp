#include <iostream>
using namespace std;

double arr[51];
int N;
double building[51];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> building[i];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int newans = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				arr[i] = building[i];
			}
			else if (i < j) {
				arr[j] = (building[j] - building[i]) / (j - i);
			}
			else {
				arr[j] = (building[i] - building[j]) / (i - j);
			}
		}
		for (int j = 1; j <= N; j++) {
			//i와 j사이에 기울기 검사해서 가능한가 체크
			if (i == j)continue;
			bool chk = true;
			if (j < i) {
				for (int k = j + 1; k < i; k++) {
					if (arr[j] >= arr[k]) {
						chk = false;
						break;
					}
				}
			}
			else if (j > i) {
				for (int k = j - 1; k > i; k--) {
					if (arr[j] <= arr[k]) {
						chk = false;
						break;
					}
				}
			}
			if (chk) newans++;
		}
		ans = ans > newans ? ans : newans;
	}
	cout << ans << endl;
}