#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;

int dp_left[1001];//���ʺ��� �˻��س����� �ش���ġ ���� �������� �� ���� �� ����
int dp_right[1001];//�����ʺ��� �˻��س����� �ش���ġ���� ���������� �� ���� �� ����

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		A.push_back(input);
	}
	dp_left[0] = dp_right[N - 1] = 0;
	for (int i = 1; i < N; i++) {
		int j;
		int max_ = 0;
		for (j = i - 1; j >= 0; j--) {
			if (A[j] < A[i]) {
				if (max_ <= dp_left[j]) max_ = dp_left[j] + 1;
			}

		}
		dp_left[i] = max_;
	}
	for (int i = N - 2; i >= 0; i--) {
		int j;
		int max_ = 0;
		for (j = i + 1; j < N; j++) {
			if (A[j] < A[i]) {
				if (max_ <= dp_right[j]) max_ = dp_right[j] + 1;
			}

		}
		dp_right[i] = max_;
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (dp_left[i] + dp_right[i] + 1 > ans) ans = dp_left[i] + dp_right[i] + 1;
	}
	cout << ans << endl;
}