#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	//vector<int> ans;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
				//ans.push_back(0);
			}
			else {
				//ans.push_back(pq.top());
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}
	//for (int i = 0; i < ans.size(); i++)
		//cout << ans[i] << "\n";
}