#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> val;
int ans[2];
int min_ = 2000000001;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		val.push_back(tmp);
	}
	sort(val.begin(), val.end());
	int left = 0;
	int right = val.size() -1;
	while (left != right) {
		if (abs(val[left] + val[right]) < min_) {
			min_ = abs(val[left] + val[right]);
			ans[0] = val[left];
			ans[1] = val[right];
		}
		int leftmove = val[left + 1] + val[right];
		int rightmove = val[right - 1] + val[left];
		if (abs(leftmove) < abs(rightmove)) {
			left++;
		}
		else {
			right--;
		}
	}
	cout << ans[0] << ' ' << ans[1] << endl;
}