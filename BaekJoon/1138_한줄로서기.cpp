#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> rule(1, 0);
	for (int i = 0; i < N; i++) {
		int t; cin >> t;
		rule.push_back(t);
	}
	vector<int> line;
	for (int i = 1; i <= N; i++) line.push_back(i);
	do {
		bool chk = true;
		for (int i = 0; i < N; i++) {
			int bigger = 0;
			for (int j = 0; j < i; j++) {
				if (line[i] < line[j]) bigger++;
			}
			if (rule[line[i]] != bigger) {
				chk = false;
				break;
			}
		}
		if (chk) {
			break;
		}
	} while (next_permutation(line.begin(),line.end()));
	for (int i = 0; i < N; i++) {
		cout << line[i] << " ";
	}
}