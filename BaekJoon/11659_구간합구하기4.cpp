#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[100001];
	arr[0] = 0;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = arr[i-1] + tmp;
	}
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		cout << arr[e] - arr[s-1] << "\n";
	}
}