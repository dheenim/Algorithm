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
				calc(row, col, size / 2);//�������
				calc(row + (size / 2), col, size / 2);//�������
				calc(row, col + (size / 2), size / 2);//�����ϴ�
				calc(row + (size / 2), col + (size / 2), size / 2);//�����ϴ�
				return;
			}
		}
	}
	if (same) {//1�� ����
		one++;
	}
	else {
		zero++;
	}
}