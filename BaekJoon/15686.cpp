#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int row, M;
vector<pair<int,int>> houses;
vector<pair<int,int>> chickens;
int answer = 99999999;

int calcDist(vector<int> picks) {
	int sum = 0;
	for (int i = 0; i < houses.size(); i++) {
		int dist = 9999999;
		for (int j = 0; j < picks.size(); j++) {
			int newDist = abs(houses[i].first - chickens[picks[j]].first) + abs(houses[i].second - chickens[picks[j]].second);
			if (dist > newDist) dist = newDist;
		}
		sum += dist;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> row >> M;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			int num; cin >> num;
			if (num == 1) {
				houses.push_back({ i,j });
			}
			else if (num == 2) {
				chickens.push_back({ i,j });
			}
		}
	}

	vector<int> v;
	for (int i = 0; i < M; i++) {
		v.push_back(1);
	}
	for (int i = 0; i < chickens.size() - M; i++) {
		v.push_back(0);
	}
	sort(v.begin(), v.end());

	do {
		vector<int> picks;
		for (int i = 0; i < chickens.size(); i++) {
			if (v[i] == 1) {
				picks.push_back(i);
			}
		}
		int dist = calcDist(picks);
		if (answer > dist) answer = dist;
	} while (next_permutation(v.begin(), v.end()));
	cout << answer;
}