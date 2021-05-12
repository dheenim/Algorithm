#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> node[51];
void deleteChild(int idx);
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		node[i].push_back(-2);
	}
	for (int i = 0; i < N; i++) {
		int parent; 
		cin >> parent;
		if (parent == -1) {
			node[i][0] = parent;
			continue;
		}
		node[i][0] = parent;
		node[parent].push_back(i);
	}
	int deleteIdx; cin >> deleteIdx;
	if (node[deleteIdx][0] == -1) {
		cout << 0 << endl;
		return 0;
	}
	for (auto it = node[node[deleteIdx][0]].begin(); it != node[node[deleteIdx][0]].end(); it++) {
		if (*it == deleteIdx) {
			node[node[deleteIdx][0]].erase(it);
			break;
		}
	}
	deleteChild(deleteIdx);
	int ans = 0;
	/*for (int i = 0; i < N; i++) {
		cout << i << ": ";
		for (int j = 0; j < node[i].size(); j++) {
			cout << node[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 0; i < N; i++) {
		if (node[i].size() == 1) ans++;
	}
	cout << ans << endl;
}
void deleteChild(int idx) {
	if (node[idx].size() == 1) {
		node[idx].clear();
		return;
	}
	for (int i = 1; i < node[idx].size(); i++) {
		int child = node[idx][i];
		deleteChild(child);
	}
	node[idx].clear();
}