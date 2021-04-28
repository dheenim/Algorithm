#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	vector<string> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		if (*lower_bound(v.begin(), v.end(), s) == s) {
			ans++;
		}
	}
	cout << ans << endl;
}