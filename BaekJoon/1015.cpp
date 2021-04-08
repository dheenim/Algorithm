#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N;
int ans[51];
vector<pair<int,int>> A;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back({ tmp,i });
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) {
		ans[A[i].second] = i;
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
