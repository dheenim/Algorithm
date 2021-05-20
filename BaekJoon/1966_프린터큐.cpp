#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//struct cmp {
//	bool operator()(pair<int, int>& a, pair<int, int>& b) {
//		if (a.first == b.first) {
//			return a.second < b.second;
//		}
//		return a.first > b.first;
//	}
//};

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		//cout << "---------------------------\n";
		int num, pos;
		cin >> num >> pos;
		vector<int> input;
		queue<pair<int,int>> q;
		for (int idx = 0; idx < num; idx++) {
			int weight; cin >> weight;
			input.push_back(weight);
			q.push({ idx, weight });
		}
		sort(input.begin(), input.end());
		int ans = 1;
		while (!q.empty()) {
			pair<int,int> frt = q.front();
			q.pop();
			//cout << "qfront: " << frt.first << " " << frt.second << endl;
			if (upper_bound(input.begin(), input.end(), frt.second) == input.end()) {
				if (frt.first == pos) {
					cout << ans << "\n";
					break;
				}
				ans++;
				input.erase(find(input.begin(), input.end(), frt.second));
			}
			else {
				q.push(frt);
			}
		}
	}
}