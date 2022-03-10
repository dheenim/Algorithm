#include <string>
#include <vector>
#include <cstring>
using namespace std;
bool visit[5][5];
bool good;
int dirRow[4] = {-1,0,0,1};
int dirCol[4] = {0,-1,1,0};
void dfs(int r,int c, int dist, vector<string> place){
    if(dist<=2 && dist>0){
        if(place[r][c] == 'P'){
            good = false;
            return;
        }
    }
    if(dist>1) return;
    if(!good) return;
    for(int i=0;i<4;i++){
        int nr = r+dirRow[i];
        int nc = c+dirCol[i];
        if(nr<0 || nr>4 || nc<0 || nc>4) continue;
        if(visit[nr][nc]) continue;
        if(place[nr][nc] == 'X') continue;
        visit[nr][nc] = true;
        dfs(nr,nc,dist+1,place);
    }
}

vector<int> solution(vector<vector<string>> places){
    vector<int> answer;
    for(auto place:places){
        memset(visit,0,sizeof(visit));
        good = true;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(place[i][j] == 'P'){
                    visit[i][j] = true;
                    dfs(i,j,0,place);
                }
            }
        }
        answer.push_back(good);
    }
    return answer;
}
