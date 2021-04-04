#include <iostream>

using namespace std;

int box[1002];
int dp[1002];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> box[i];
	}
	dp[1] = 1;//1번박스까지만 보면 박스는 하나밖에 못들어감
	for (int i = 2; i <= n; i++) {
		int max_ = 1;//최소 한개이므로
		for (int j = i - 1; j > 0; j--) {
			if (box[i] > box[j]) {
				if (max_ <= dp[j]) max_ = dp[j]+1;
			}
		}
		dp[i] = max_;
		//cout << "i:" << i << "  dp[i]:" << dp[i]<<endl;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < dp[i]) ans = dp[i];
	}
	cout << ans << endl;
}