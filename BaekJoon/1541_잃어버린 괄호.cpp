#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string input;
	cin >> input;
	vector<vector<int>> v;
	vector<int> vtmp;
	string tmp;
	int ans;
	for (int i = 0; i < input.length(); i++) {
		if(input[i] == '-'){
			vtmp.push_back(stoi(tmp));
			v.push_back(vtmp);
			vtmp.clear();
			tmp.clear();
		}
		else if (input[i] == '+') {
			vtmp.push_back(stoi(tmp));
			tmp.clear();
		}
		else {
			tmp.push_back(input[i]);
		}
	}
	vtmp.push_back(stoi(tmp));
	v.push_back(vtmp);
	vtmp.clear();
	for (int i = 0; i < v.size(); i++) {
		int num = 0;
		for (int j = 0; j < v[i].size(); j++) {
			num += v[i][j];
		}
		vtmp.push_back(num);
	}
	ans = vtmp[0];
	for (int i = 1; i < vtmp.size(); i++) {
		ans -= vtmp[i];
	}
	cout << ans << endl;
}