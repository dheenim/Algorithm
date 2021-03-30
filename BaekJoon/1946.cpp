#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int>> input;
vector<int> ans;
int min_ = 1e9;

void calc();

int main() {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		input.clear();
		for (int j = 0; j < N; j++) {
			int f, s;
			cin >> f >> s;
			input.push_back({f,s});
		}
		calc();
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

void calc() {
	int answer = 1;
	sort(input.begin(), input.end());
	min_ = input[0].second;
	for (int i = 1; i < input.size(); i++) {
		if (input[i].second < min_) {
			answer++;
			min_ = input[i].second;
		}
	}
	ans.push_back(answer);
}