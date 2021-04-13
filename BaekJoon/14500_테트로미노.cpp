#include <iostream>

#define MAX(a,b) ((a)>(b))?(a):(b)
using namespace std;

//¿ÞÂÊÀ§ ÁÂÇ¥
int block_row[19][4] = { {0,0,0,0}, {0,1,2,3}, {0,0,1,1}, {0,1,2,2}, {0,0,-1,-2}, {0,0,1,2}, {0,0,1,2}, {0,1,1,1}, {0,0,0,-1}, {0,0,0,1}, {0,0,0,1}, {0,1,1,2}, {0,1,1,2}, {0,0,1,1}, {0,0,-1,-1}, {0,0,0,-1}, {0,0,0,1}, {0,1,1,2}, {0,1,1,2} };
					// ÀÏÀÚ °¡·Î    ÀÏÀÚ ¼¼·Î  ³×¸ð		À§°¡ ±ä ´ÏÀº/ÁÂ¿ì´ëÄª/»óÇÏ´ëÄª(±â¾ï)/»óÇÏÁÂ¿ì  À§°¡ÂªÀº´ÏÀº/ÁÂ¿ì´ëÄª/»óÇÏ´ëÄª/»óÇÏÁÂ¿ì´ëÄª) ¤©¼¼¿ö/ÁÂ¿ì         /¤©         /¤©»óÇÏ      /¤Ç  /¤Ì		          /¤¿        /¤Ã
int block_col[19][4] = { {0,1,2,3}, {0,0,0,0}, {0,1,0,1}, {0,0,0,1}, {0,1,1,1}, {0,1,1,1}, {0,1,0,0}, {0,0,1,2}, {0,1,2,2}, {0,1,2,0}, {0,1,2,2}, {0,0,1,1}, {0,0,-1,-1}, {0,1,1,2}, {0,1,1,2}, {0,1,2,1}, {0,1,2,1}, {0,0,1,0}, {0,0,-1,0} };

int row, col;
int map[501][501];
int ans = 0;
bool chkRange(int r, int c) {
	if (r > row || r<1 || c>col || c < 1) return false;
	return true;
}

int main() {
	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> map[i][j];
		}
	}
	for (int r = 1; r <= row; r++) {
		for (int c = 1; c <= col; c++) {
			for (int blk = 0; blk < 19; blk++) {
				int possible = 0;
				int val = 0;
				int nr, nc;
				for (int i = 0; i < 4; i++) {
					nr = r + block_row[blk][i];
					nc = c + block_col[blk][i];
					if (!chkRange(nr, nc)) continue;
					possible++;
					val += map[nr][nc];
				}
				if (possible == 4) {
					ans = MAX(ans, val);
				}
			}
		}
	}
	cout << ans << endl;
}