#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int P[1001];
int ans = 0;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	sort(P + 1, P + 1 + N);
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += P[i];
		ans += sum;
	}
	printf("%d\n", ans);
}