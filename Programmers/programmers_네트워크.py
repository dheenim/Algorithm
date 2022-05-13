#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visit[201];
    memset(visit, false, sizeof(visit));
    for(int i=0;i<n;i++){
        if(visit[i]) continue;
        answer++;
        queue<int> q;
        q.push(i);
        visit[i] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int idx=0;idx<n;idx++){
                if(cur==idx) continue;
                if(computers[cur][idx] && !visit[idx]){
                    q.push(idx);
                    visit[idx] = true;
                }
            }
        }
    }
    return answer;
}
