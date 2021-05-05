#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string input;
	cin >> input;
	string ans = "";
	for (int i = 0; i < input.size(); i++) {
		ans += "z";
	}
	vector<int> pick;
	pick.push_back(1); pick.push_back(1);
	for (int i = 0; i < input.length() - 3; i++) {
		pick.push_back(0);
	}
	sort(pick.begin(), pick.end());
	do {
		vector<int> picks;
		for (int i = 0; i < pick.size(); i++) {
			if (pick[i]) {
				picks.push_back(i);
			}
		}
		string tmp1 = input.substr(0, picks[0] + 1);
		reverse(tmp1.begin(), tmp1.end());
		string tmp2 = input.substr(picks[0] + 1, picks[1] - picks[0]);
		reverse(tmp2.begin(), tmp2.end());
		string tmp3 = input.substr(picks[1] + 1, input.length() - picks[1]);
		reverse(tmp3.begin(), tmp3.end());
		tmp1 = tmp1 + tmp2 + tmp3;
		if (ans > tmp1) ans = tmp1;
	} while (next_permutation(pick.begin(), pick.end()));
	cout << ans << endl;
}