#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	int ans = 0;
	
	cin >> n >> k;
	int before; cin >> before;
	ans = k / before;
	for (int i = 2; i <= n; i++) {
		int after;
		cin >> after;
		if (k - after >= 0) {
			int mul = after / before;
			int tmp = k;
			while (tmp - after>=0) {
				tmp -= after;
				ans = ans - mul + 1;
			}
		}
		before = after;
	}
	
	cout << ans << "\n";
}