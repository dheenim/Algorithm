#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int answer = 1;
		int n;
		cin >> n;
		map<string, int> m;
		for (int j = 0; j < n; j++) {
			string a, b;
			cin >> a >> b;
			m[b]++;
		}
		for (auto it = m.begin(); it != m.end(); it++) {
			answer *= (it->second + 1);
		}
		//vector<int> v;
		//int k = 0;
		//for (auto it = m.begin(); it != m.end(); it++) {
		//	v.push_back(it->second);
		//	answer += it->second;
		//}
		//
		//for (int pick = 2; pick <= v.size(); pick++) {
		//	int ans = 1;
		//	vector<int> ind;
		//	for (int ok = 0; ok < pick; ok++) {
		//		ind.push_back(1);
		//	}
		//	for (int no = 0; no < v.size() - pick; no++) {
		//		ind.push_back(0);
		//	}
		//	sort(ind.begin(), ind.end());
		//	do {
		//		for (int p = 0; p < ind.size(); p++) {
		//			if (ind[p] == 1) {
		//				ans *= v[p];
		//			}
		//		}
		//		//cout << "pick:" << pick << " ans:" << ans << endl;
		//	} while (next_permutation(ind.begin(), ind.end()));
		//	answer += ans;
		//	
		//}
		cout << answer -1 << endl;
	}
}