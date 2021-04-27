#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dir_row[4] = {-1,1,0,0};//위 아래 오른쪽 왼쪽
int dir_col[4] = {0,0,1,-1};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    bool visit[101][101];
    memset(visit,0,sizeof(visit));
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j] == 0 || visit[i][j]) continue;
            number_of_area++;
            int cnt_area = 0;
            queue<pair<int,int>> q;
            q.push({i,j});
            visit[i][j] = true;
            //cout<<"numofarea:"<<number_of_area<<endl;
            while(!q.empty()){
                pair<int,int> cur = q.front();
                //cout << "cur: "<<cur.first<<", "<<cur.second<<endl;
                cnt_area++;
                q.pop();
                for(int dir=0;dir<4;dir++){
                    int nr = cur.first + dir_row[dir];
                    int nc = cur.second + dir_col[dir];
                    if(nr<0||nr>=m||nc<0||nc>=n) continue;
                    if(visit[nr][nc]) continue;
                    if(picture[nr][nc] != picture[cur.first][cur.second]) continue;
                    //cnt_area++;
                    visit[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
            if(cnt_area > max_size_of_one_area) max_size_of_one_area = cnt_area;
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
