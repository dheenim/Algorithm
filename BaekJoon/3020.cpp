#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int N, H;

vector<int> top;
vector<int> bottom;

bool cmp_decline(int a, int b) {
	return a > b;
}

int main() {
	cin >> N >> H;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		if (i % 2 == 0) {
			bottom.push_back(input);
		}
		else {
			top.push_back(input);
		}
	}
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	int ans = 1000000000;
	int cnt = 0;
	for (int height = 1; height <= H; height++) {
		//높이 1~H까지(구간은 0.5 ~ (H-0.5)라는 의미) 위쪽과 겹치는 갯수와 아래쪽 갯수를 더해 최소를 구해나감
		//이미 구한 최소값과 같아다면 구간이 증가하는 것이고, 새로운 최소값을 찾았다면 구간을 1로 초기화
		int up = top.end() - upper_bound(top.begin(), top.end(), H - height);//위쪽은 총 높이H에서 확인할 height만큼 빼면 
		//H-height보다 큰놈만 구할 수 있다
		int down = bottom.end() - lower_bound(bottom.begin(), bottom.end(), height);
		//height보다 작은 놈을 구할 수 있다.
		if (up + down < ans) {
			ans = up + down; cnt=1;
		}
		else if (up + down == ans) {
			cnt++;
		}
	}
	cout << ans << ' ' << cnt << endl;
}