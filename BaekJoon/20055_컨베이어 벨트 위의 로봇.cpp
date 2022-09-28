#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int zeros = 0;
vector<int> belt;
vector<bool> beltEmpt;
queue<int> robotPos;

bool oneStep() {
	
	//1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
	rotate(belt.rbegin(), belt.rbegin() + 1, belt.rend());
	int qsize = robotPos.size();
	
	//2.
	while (qsize-- > 0) {
		int pos = robotPos.front();
		robotPos.pop();
		beltEmpt[pos] = true;
		pos++;//벨트 이동과 함께 로봇이동
		if (pos < N) {
			if (belt[pos + 1] > 0 && beltEmpt[pos+1]) {//우측으로 이동
				beltEmpt[pos] = true;
				pos++;
				//beltEmpt[pos] = false;
				belt[pos]--;
				if (belt[pos] == 0) {
					zeros++;
					if (zeros >= K) return false;
				}
				if (pos < N) {
					beltEmpt[pos] = false;
					robotPos.push(pos);
				}
			}
			else {
				beltEmpt[pos] = false;
				robotPos.push(pos);
			}
		}
	}

	//3.
	if (belt[0] > 0) {
		belt[0]--;
		if (belt[0] == 0) {
			zeros++;
			if (zeros >= K) return false;
		}
		beltEmpt[0] = false;
		robotPos.push(0);
	}
	if (zeros >= K) return false;
	return true;
}

int main() {
	cin >> N >> K;
	
	for (int i = 0; i < 2 * N; i++) {
		int weight;
		cin >> weight;
		belt.push_back(weight);
		beltEmpt.push_back(true);
	}
	N--;
	
	int step = 1;
	while (1) {
		if (!oneStep()) break;
		step++;
	}
	cout << step << endl;
	return 0;
}
