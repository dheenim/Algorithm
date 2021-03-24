#include <iostream>
#include <cstdio>
#include <cstring>

#define MIN(a,b) (((a)<(b))?(a):(b))
using namespace std;

int N;
int ans;
int** arr;

int main() {
	cin >> N;
	arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[3];
	}
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	int cost[1001][3] = { 0 };
	cost[0][0] = arr[0][0];
	cost[0][1] = arr[0][1];
	cost[0][2] = arr[0][2];
	for (int i = 1; i < N; i++) {
		cost[i][0] = MIN(cost[i - 1][1], cost[i - 1][2]) + arr[i][0];
		cost[i][1] = MIN(cost[i - 1][0], cost[i - 1][2]) + arr[i][1];
		cost[i][2] = MIN(cost[i - 1][0], cost[i - 1][1]) + arr[i][2];
	}
	int tmp = MIN(cost[N - 1][0], cost[N - 1][1]);
	ans = MIN(tmp, cost[N-1][2]);
	printf("%d\n", ans);
}