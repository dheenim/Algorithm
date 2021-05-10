#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

bool cmp(int a, int b) {
	return a>b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> ans;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		ans.push_back(tmp);
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			ans.push_back(tmp);
		}
		sort(ans.begin(), ans.end(),cmp);
		ans.erase(ans.begin()+N, ans.end());
		cout << "ans.size:" << ans.size() << endl;
	}
	cout << ans[N-1];
}