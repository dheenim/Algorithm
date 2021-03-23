#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int* narr;
int* marr;
bool* ans;

int main() {
	cin >> N;
	narr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> narr[i];
	}
	sort(narr, narr + N);

	cin >> M;
	marr = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> marr[i];
	}
	//sort(marr, marr + M);
	ans = new bool[M];
	memset(ans, false, sizeof(ans));
	for (int i = 0; i < M; i++) {
		int low = 0;
		int high = N - 1;
		int mid;
		while (low<=high) {
			mid = (low + high) / 2;
			printf("low:%d high : %d, marr[%d]:%d, narr[%d]:%d\n", low, high, i, marr[i], mid, narr[mid]);
			if (marr[i] > narr[mid]) {
				low = mid + 1;
			}
			else if (marr[i] < narr[mid]) {
				high = mid - 1;
			}
			else {
				ans[i] = true;
				break;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		if (ans[i]) printf("1\n");
		else printf("0\n");
	}
}