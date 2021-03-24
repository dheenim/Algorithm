#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 3000
#define MIN(a,b) a<b?a:b
using namespace std;

int N;
int ans=-1;
int* arr;
void dp(int count, int weight);

int main() {
	cin >> N;
	if (N < 3 || N==4) {
		printf("%d\n", ans);
		return 0;
	}

	arr = new int[N + 1];
	for (int i = 0; i <= N; i++) {
		arr[i] = INF;
	}
	arr[3] = 1;
	arr[5] = 1;
	for (int i = 6; i <= N; i++) {
		arr[i] = MIN(arr[i - 3] + 1, arr[i - 5] + 1);
		printf("arr[%d]=%d\n", i, arr[i]);
	}
	if (arr[N] < INF) {
		ans = arr[N];
	}
	printf("%d\n", ans);
}
