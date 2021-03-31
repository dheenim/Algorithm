#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
vector<int> house;

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		house.push_back(tmp);
	}
	sort(house.begin(), house.end());
	int high = house[house.size() - 1];
	int low = 0;
	while (low <= high) {
		int mid = (high + low) / 2;
		int cnt = 1;
		int idx=0;
		for (int i = 1; i < house.size(); i++) {
			if (house[i] - house[idx] >= mid) {
				cnt++;
				idx = i;
				if (cnt >= C) break;
			}
		}
		if (cnt >= C) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << high << endl;
}