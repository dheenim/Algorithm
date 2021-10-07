#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

int Row, Col;
int map[21][21];
int dirRow[5] = { 0,0,0,-1,1 };//X,��,��,��,�� ��
int dirCol[5] = { 0,1,-1,0,0 };//X,��,��,��, �� ��
pair<int, int> curPos;
queue<int> imple;
deque<int> east_west;//0:��, 1:��, 2:�Ʒ�, 3:�� �� ����Ŵ
deque<int> north_south;//0:��, 1:��, 2:�Ʒ�, 3:�� �� ����Ŵ
void playGame();
bool chkRange(int dir);
void doImple(int dir);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int play;
	cin >> Row >> Col >> curPos.first >> curPos.second >> play;
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < play; i++) {
		int dir; cin >> dir; imple.push(dir);
	}
	for (int i = 0; i < 4; i++) {
		east_west.push_back(0); north_south.push_back(0);
	}
	playGame();
}
void playGame() {
	while (!imple.empty()) {
		int dir = imple.front();
		if (chkRange(dir)) {
			doImple(dir);
		}
		imple.pop();
	}
}

bool chkRange(int dir) {
	int nr = curPos.first + dirRow[dir];
	int nc = curPos.second + dirCol[dir];
	if (nr < 0 || nc < 0 || nr >= Row || nc >= Col) return false;
	return true;
}

void doImple(int dir) {
	//���� ��ġ ����
	curPos.first += dirRow[dir];
	curPos.second += dirCol[dir];
	//cout << "(" << curPos.first << ", " << curPos.second <<"), dir:" <<dir<<endl;
	int up, down;
	switch (dir) {
	case 1://��
		up = east_west.back(); east_west.pop_back();
		east_west.push_front(up);
		north_south[0] = up;

		if (map[curPos.first][curPos.second] == 0) {
			down = east_west[2];
			map[curPos.first][curPos.second] = east_west[2];
		}
		else {
			down = map[curPos.first][curPos.second];
			map[curPos.first][curPos.second] = 0;
		}
		
		break;
	case 2://��
		up = east_west[1]; 
		east_west.push_back(east_west.front());
		east_west.pop_front();
		north_south[0] = up;

		if (map[curPos.first][curPos.second] == 0) {
			down = east_west[2];
			map[curPos.first][curPos.second] = east_west[2];
		}
		else {
			down = map[curPos.first][curPos.second];
			map[curPos.first][curPos.second] = 0;
		}

		break;
	case 3://��
		up = north_south.back(); north_south.pop_back();
		north_south.push_front(up);
		east_west[0] = up;

		if (map[curPos.first][curPos.second] == 0) {
			down = north_south[2];
			map[curPos.first][curPos.second] = north_south[2];
		}
		else {
			down = map[curPos.first][curPos.second];
			map[curPos.first][curPos.second] = 0;
		}

		break;
	default://��
		up = north_south[1];
		north_south.push_back(north_south.front());
		north_south.pop_front();
		east_west[0] = up;
	
		if (map[curPos.first][curPos.second] == 0) {
			down = north_south[2];
			map[curPos.first][curPos.second] = north_south[2];
		}
		else {
			down = map[curPos.first][curPos.second];
			map[curPos.first][curPos.second] = 0;
		}

		break;
	}
	east_west[2] = down; north_south[2] = down;
	cout << east_west[0] << "\n";

	/*for (int i = 0; i < 4; i++) {
		cout << east_west[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < 4; i++) {
		cout << north_south[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) cout << map[i][j] << " ";
		cout << "\n";
	}
	cout << endl;*/
}