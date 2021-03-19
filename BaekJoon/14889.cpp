#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int N;

int arr[21][21];
int answer = 200000;
int chk[21];
int a[11];
int a_chk[11];

void calc();
void dfs(int usingNum);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	memset(a_chk, 0, sizeof(a_chk));
	dfs(1);
	printf("%d\n", answer);
}

void calc() {
	//a배열 사용
	int b[11];
	int chk[21];
	memset(chk, 0, sizeof(chk));
	for (int i = 1; i <= N/2; i++) {
		chk[a[i]] = 1;
	}
	int tmp = 1;
	for (int i = 1; i <= N; i++) {
		if (!chk[i]) {
			b[tmp] = i;
			tmp++;
		}
	}
	int aScore = 0;
	int bScore = 0;
	for (int i = 1; i < N / 2; i++) {
		for (int j = i + 1; j <= N / 2; j++) {
			aScore = aScore + arr[a[j]][a[i]] + arr[a[i]][a[j]];
			bScore = bScore + arr[b[j]][b[i]] + arr[b[i]][b[j]];
		}
	}

	int dif = aScore - bScore;
	if (dif < 0) dif = dif = bScore - aScore;
	//printf("ans:%d dif:%d\n", answer, dif);
	if (dif < answer) answer = dif;
	return;
}

void dfs(int usingNum) {
	//printf("num=%d\n", num);
	//for (int i = 1; i <= N / 2; i++) {
	//	printf("a[%d]=%d\n",i, a[i]);
	//}
	if (usingNum > N/2) {
		calc();
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (a_chk[i]) continue;
		if (usingNum - 1 > 0 && a[usingNum - 1] > i) continue;
		a[usingNum] = i;
		a_chk[i] = 1;
		dfs(usingNum + 1);
		a_chk[i] = 0;
	}
}