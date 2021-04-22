#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int>a, pair<int,int> b) {
	return a.first < b.first;
}

int main() {
	string str;
	cin >> str;
	vector<int> v[15];
	vector<pair<int, int>> order;
	int vidx = 0;
	string num = "";
	int middle = 0;

	for (int idx = 1; idx < str.length() - 1; idx++) {
		if (str[idx] == '{') {
			middle++;
		}
		else if (str[idx] == ',') {
			if (middle == 1) {
				v[vidx].push_back(stoi(num));
				num.clear();
			}
		}
		else if (str[idx] == '}') {
			middle--;
			v[vidx].push_back(stoi(num));
			num.clear();
			order.push_back({ v[vidx].size(), vidx });
			vidx++;
		}
		else num += str[idx];
	}
	sort(order.begin(), order.end(), cmp);
	set<int> chk_duple;
	vector<int> ans;
	for (int i = 0; i < vidx; i++) {
		//cout << "i:" << i << endl;
		for (int j = 0; j < v[order[i].second].size(); j++) {
			//cout << v[order[i].second][j] << endl;
			auto chk = chk_duple.insert(v[order[i].second][j]);
			if (chk.second) ans.push_back(v[order[i].second][j]);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}