#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int* Narr;
int* Marr;
bool* chk;
int main() {
	cin >> N;
	Narr = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		cin >> Narr[i];
	}
	sort(Narr + 1, Narr + 1 + N);
	cin >> M;
	Marr = new int[M + 1];
	for (int i = 1; i <= M; i++) {
		cin >> Marr[i];
	}
	chk = new bool[M + 1];
	memset(chk, 0, sizeof(M + 1));
	
	for (int i = 1; i <= M; i++) {
		int low = 1;
		int high = N;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (Marr[i] > Narr[mid]) {
				low = mid + 1;
			}
			else if (Marr[i] < Narr[mid]) {
				high = mid - 1;
			}
			else {
				chk[i] = true;
				break;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		if (chk[i]) printf("1 ");
		else printf("0 ");
	}
	return 0;
}