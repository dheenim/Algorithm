#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define EMPT -2
using namespace std;

typedef struct blockGrp {
	int blockNum;
	int rainbowNum;
	int row;
	int col;
}blockGrp;

int N, M;
int answer = 0;
vector<vector<int>> block;
int dirRow[4] = { -1,1,0,0 };//상하좌우
int dirCol[4] = { 0,0,-1,1 };

bool cmp(blockGrp a, blockGrp b) {
	if (a.blockNum == b.blockNum) {
		if (a.rainbowNum == b.rainbowNum) {
			if (a.row == b.row) {
				return a.col > b.col;
			}
			return a.row > b.row;
		}
		return a.rainbowNum > b.rainbowNum;
	}
	return a.blockNum > b.blockNum;
}

bool posChk(int r, int c) {
	if (r<1 || r>N || c<1 || c>N) return false;
	return true;
}


vector<blockGrp> findBlk() {
	//cout << "findBlk()\n";
	vector<blockGrp> findBlocks;
	vector<vector<bool>> visit(N + 1, vector<bool>(N + 1, false));
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (block[r][c] == 0 || block[r][c] == -1 || block[r][c] == EMPT || visit[r][c]) {
				continue;
			}
			vector<vector<bool>> rainbowVisit(N + 1, vector<bool>(N + 1, false));
			int rainbows = 0;
			int blks = 1;
			int blkColor = block[r][c];
			queue<pair<int, int>> q;
			q.push({ r,c }); visit[r][c] = true;
			while (!q.empty()) {
				pair<int, int> pos = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nr = pos.first + dirRow[dir];
					int nc = pos.second + dirCol[dir];
					if (!posChk(nr, nc)) continue;
					if (block[nr][nc] == -1 || block[nr][nc] == EMPT) continue;
					if (visit[nr][nc] || rainbowVisit[nr][nc]) continue;
					if (block[nr][nc] == 0) {
						rainbows++;
						blks++;
						rainbowVisit[nr][nc] = true;
						q.push({ nr,nc });
					}
					else if(block[nr][nc] == blkColor) {
						blks++;
						visit[nr][nc] = true;
						q.push({ nr,nc });
					}
				}
			}
			if (blks > 1) {
				blockGrp blkGrp;
				blkGrp.blockNum = blks;
				blkGrp.rainbowNum = rainbows;
				blkGrp.row = r;
				blkGrp.col = c;
				findBlocks.push_back(blkGrp);
			}
		}
	}
	return findBlocks;
}

void eraseNgain(int r, int c) {
	//cout << "erasNgain\n";
	int blkColor = block[r][c];
	int blks = 0;
	vector<vector<bool>> visit(N + 1, vector<bool>(N + 1, false));
	queue<pair<int, int>> q;
	q.push({ r,c }); visit[r][c] = true; blks++;
	block[r][c] = EMPT;
	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nr = pos.first + dirRow[dir];
			int nc = pos.second + dirCol[dir];
			if (!posChk(nr, nc)) continue;
			if (visit[nr][nc]) continue;
			if (block[nr][nc] == -1 || block[nr][nc] == EMPT) continue;
			if (block[nr][nc] == blkColor || block[nr][nc] == 0) {
				q.push({ nr,nc }); visit[nr][nc] = true; blks++;
				block[nr][nc] = EMPT;
			}
			
		}
	}
	//cout << blks * blks << endl;
	answer += (blks * blks);
}

void doGravity() {
	for (int r = N - 1; r > 0; r--) {
		for (int c = 1; c <= N; c++) {
			if (block[r][c] < 0) continue;
			int newRow = r;
			bool downPossi = false;
			while (1) {
				if (newRow + 1 <= N && block[newRow + 1][c] == EMPT) {
					downPossi = true;
					newRow++;
				}
				else break;
			}
			if (downPossi) {
				block[newRow][c] = block[r][c];
				block[r][c] = EMPT;
			}
		}
	}
}

void do270reverse() {
	vector<vector<int>> tmpBlk(N + 1, vector<int>(N + 1));
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			tmpBlk[N - c + 1][r] = block[r][c];
		}
	}
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			 block[r][c] = tmpBlk[r][c];
		}
	}
}

bool autoPlay() {
	//cout << "startAutoplay\n";
	/* 1. 크기가 가장 큰 블록 그룹을 찾는다.
	그러한 블록 그룹이 여러 개라면 포함된 무지개 블록의 수가 가장 많은 블록 그룹,
	그러한 블록도 여러개라면 기준 블록의 행이 가장 큰 것을,
	그 것도 여러개이면 열이 가장 큰 것을 찾는다. */
	vector<blockGrp> blkGrps = findBlk();
	if (blkGrps.size() == 0) return false;
	sort(blkGrps.begin(), blkGrps.end(), cmp);
	blockGrp blkInfo = blkGrps[0];
	//cout << blkInfo.row << "," << blkInfo.col << endl;
	//2. 1에서 찾은 블록 그룹의 모든 블록을 제거한다.
	//블록 그룹에 포함된 블록의 수를 B라고 했을 때, B2점을 획득한다.
	eraseNgain(blkInfo.row, blkInfo.col);

	
	//3. 격자에 중력이 작용한다.
	doGravity();

	
	//4. 격자가 90도 반시계 방향으로 회전한다.
	do270reverse();
	
	//5. 다시 격자에 중력이 작용한다.
	doGravity();

	/*cout << "after1step\n";
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << block[r][c] << " ";
		}
		cout << endl;
	}*/

	return true;
}

int main() {
	cin >> N >> M;
	block.resize(N + 1, vector<int>(N + 1));
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int blk; cin >> blk;
			block[r][c] = blk;
		}
	}

	while (autoPlay()) { ; }
	cout << answer;
}
