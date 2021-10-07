#include <string>
#include <vector>

using namespace std;
bool visit[201];
int answer;
void dfs(int s, vector<vector<int>> &com){
    for(int i=0;i<com[s].size();i++){
        if(com[s][i]==0) continue;
        if(visit[i]) continue;
        visit[i] = true;
        dfs(i,com);
    }
}

int solution(int n, vector<vector<int>> computers) {
    answer = 0;
    for(int i=0;i<computers.size();i++){
        if(visit[i]) continue;
        dfs(i, computers);
        answer++;
    }
    return answer;
}
