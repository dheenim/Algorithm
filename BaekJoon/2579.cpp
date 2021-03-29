#include<iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int arr[311][311];

int main() {
	memset(arr, 0, sizeof(arr));
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][i];
	}
	for (int i = 2; i <= N; i++) {
		arr[i - 1][i] = arr[i - 1][i - 1] + arr[i][i];
	}
	for (int i = 1; i <= N - 2; i++) {
		arr[i][i + 2] = max(arr[i][i], arr[i + 1][i + 1]) + arr[i + 2][i + 2];
	}
	for (int i = 3; i < N; i++) {
		for (int j = 1; j <= N-i; j++) {
			arr[j][j + i] = max(arr[j+i][j+i] + arr[j][j + i - 2], arr[j+i][j+i] + arr[j+i-1][j + i - 1] + arr[j][j + i - 3]);
		}
	}
	cout << arr[1][N] << endl;
	return 0;
}