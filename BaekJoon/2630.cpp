#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int paper[129][129];
int zero = 0;
int one = 0;

void calc(int row, int col, int size);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> paper[i][j];
		}
	}
	calc(1,1,N);
	printf("%d\n%d", zero, one);
}

void calc(int row, int col, int size) {
	int same = paper[row][col];

	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (same != paper[i][j]) {
				calc(row, col, size / 2);//좌측상단
				calc(row + (size / 2), col, size / 2);//우측상단
				calc(row, col + (size / 2), size / 2);//좌측하단
				calc(row + (size / 2), col + (size / 2), size / 2);//우측하단
				return;
			}
		}
	}
	if (same) {//1의 개수
		one++;
	}
	else {
		zero++;
	}
}