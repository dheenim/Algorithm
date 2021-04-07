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
		//���� 1~H����(������ 0.5 ~ (H-0.5)��� �ǹ�) ���ʰ� ��ġ�� ������ �Ʒ��� ������ ���� �ּҸ� ���س���
		//�̹� ���� �ּҰ��� ���ƴٸ� ������ �����ϴ� ���̰�, ���ο� �ּҰ��� ã�Ҵٸ� ������ 1�� �ʱ�ȭ
		int up = top.end() - upper_bound(top.begin(), top.end(), H - height);//������ �� ����H���� Ȯ���� height��ŭ ���� 
		//H-height���� ū�� ���� �� �ִ�
		int down = bottom.end() - lower_bound(bottom.begin(), bottom.end(), height);
		//height���� ���� ���� ���� �� �ִ�.
		if (up + down < ans) {
			ans = up + down; cnt=1;
		}
		else if (up + down == ans) {
			cnt++;
		}
	}
	cout << ans << ' ' << cnt << endl;
}