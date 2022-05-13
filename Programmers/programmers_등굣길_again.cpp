#include <string>
#include <vector>
using namespace std;
int map[101][101];
int move_row[2] = {0,1};//오른쪽, 아래
int move_col[2] = {1,0};
int solution(int col, int row, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i=0;i<puddles.size();i++){
        map[puddles[i][1]][puddles[i][0]] = -1;
    }
    for(int i=2;i<=row;i++) {
        if(map[i][1] == -1) break;
        map[i][1] = 1;
    }
    for(int i=2;i<=col;i++) {
        if(map[1][i] == -1) break;
        map[1][i] = 1;
    }
    for(int r=2;r<=row;r++){
        for(int c=2;c<=col;c++){
            if(map[r][c] < 0) continue;
            int u=0;
            int l=0;
            if(map[r-1][c] > -1) u = map[r-1][c] % 1000000007;
            if(map[r][c-1] > -1) l = map[r][c-1] % 1000000007;
            map[r][c] = (u+l) % 1000000007;
        }
    }
    return map[row][col] % 1000000007;
}
