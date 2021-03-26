#include<iostream>
#include <map>
using namespace std;

int N, M;
map<int,int> inputN;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		inputN[tmp]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		cout << inputN[tmp] << ' ';
	}
	return 0;
}