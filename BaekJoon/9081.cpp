#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
string input[10];

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < T; i++) {
		vector<char> collect;

		int j;
		for (j = input[i].length()-1; j > 0; j--) {
			collect.push_back(input[i][j]);
			if (input[i][j] > input[i][j - 1]) {
				collect.push_back(input[i][j - 1]);
				break;
			}
		}
		if (j == 0) {
			cout << input[i] << endl;
			continue;
		}
		vector<char> ans;
		for (int k = 0; k < j - 1; k++) {
			cout << input[i][k];
		}
		sort(collect.begin(), collect.end());
		int nextBigidx = upper_bound(collect.begin(), collect.end(), input[i][j-1]) - collect.begin();
		cout << collect[nextBigidx];
		collect.erase(collect.begin() + nextBigidx);
		sort(collect.begin(), collect.end());
		for (int k = 0; k < collect.size(); k++)
			cout << collect[k];
		cout << endl;
	}
}