#include <iostream>
using namespace std;
int arr[1025][1025];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp; cin >> tmp;
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i-1][j-1]+ tmp;
		}
	}
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << arr[y2][x2] - arr[y2][x1-1] - arr[y1-1][x2] + arr[y1-1][x1-1] << '\n';
	}
}