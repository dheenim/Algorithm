#include <iostream>
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

int dp[1001][1001];
int ans = 0;
int main() {
	string first, second;
	cin >> first;
	cin >> second;
	for (int i = 1; i <= first.length(); i++) {
		if (second[0] == first[i - 1]) dp[1][i] = 1;
		else dp[1][i] = dp[1][i - 1];
	}
	for (int i = 2; i <= second.length(); i++) {
		for (int j = 1; j <= first.length(); j++) {
			if (second[i-1] == first[j-1]) {
				dp[i][j] = dp[i - 1][j-1] + 1;
			}
			else {
				dp[i][j] = MAX(dp[i - 1][j],dp[i][j-1]);
			}
		}
	}
	//for (int i = 0; i <= second.length(); i++) {
	//	for (int j = 0; j <= first.length(); j++) {
	//		cout << dp[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	cout << dp[second.length()][first.length()] << endl;
}