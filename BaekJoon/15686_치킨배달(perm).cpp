#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int totChicken, totHouse;
vector<pair<int, int>> chickPos;
vector<pair<int, int>> housePos;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int info;
			cin >> info;
			if (info == 2) {
				chickPos.push_back({ i,j });
			}
			else if (info == 1) {
				housePos.push_back({ i,j });
			}
		}
	}
	totChicken = chickPos.size();
	totHouse = housePos.size();

	vector<bool> pick;
	for (int i = 0; i < totChicken; i++) {
		if (i >= M) pick.push_back(false);
		else pick.push_back(true);
	}
	sort(pick.begin(), pick.end());

	int ans = 1000000000;
	do {
		int totDist = 0;
		for (int i = 0; i < totHouse; i++) {
			int dist = 1000;
			for (int j = 0; j < totChicken; j++) {
				if (!pick[j]) continue;
				int tmpdist = abs(chickPos[j].first - housePos[i].first) + abs(chickPos[j].second - housePos[i].second);
				if (tmpdist < dist) dist = tmpdist;
			}
			totDist += dist;
		}
		if (totDist < ans) ans = totDist;
	} while (next_permutation(pick.begin(), pick.end()));

	cout << ans;
}
