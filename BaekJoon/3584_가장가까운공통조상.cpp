#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void initTree(int num, vector<vector<int>>& v);
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int nodeNum; cin >> nodeNum;
		vector<vector<int>> tree;
		initTree(nodeNum, tree);
		for (int j = 1; j < nodeNum; j++) {
			int parent, child; cin >> parent >> child;
			tree[parent].push_back(child);
			tree[child][0] = parent;
		}
		int node1, node2; cin >> node1 >> node2;
		vector<int> parents;
		parents.push_back(node1);
		while (1) {
			node1 = tree[node1][0];
			if (node1 == -1) break;
			parents.push_back(node1);
		}
		while (find(parents.begin(), parents.end(), node2) == parents.end()) {
			node2 = tree[node2][0];
		}
		cout << node2 << "\n";
	}
}

void initTree(int num, vector<vector<int>>& v) {
	vector<int> tmp; tmp.push_back(-1);
	for (int i = 0; i <= num; i++) {
		v.push_back(tmp);
	}
}