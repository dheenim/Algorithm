#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<pair<int,int>> edge[51];
    int cost[51]; 
    for(int i=2;i<=N;i++){
        cost[i] = 1e9;
    }
    cost[1] = 0;


    for(int i=0;i<road.size();i++){
        int s = road[i][0], d = road[i][1];
        edge[s].push_back({d,road[i][2]}); edge[d].push_back({s,road[i][2]});
    }
    for(int i=1;i<=N;i++){
        sort(edge[i].begin(),edge[i].end(),cmp);
    }

    queue<int> q; q.push(1);
    while(!q.empty()){
        int s = q.front(); q.pop();
        for(int i=0;i<edge[s].size();i++){
            int d = edge[s][i].first;
            if(cost[d] < cost[s] + edge[s][i].second){
                continue;
            }
            q.push(d);
            cost[d] = MIN(cost[d], cost[s] + edge[s][i].second);
        }
    }
    for(int i=1;i<=N;i++){
        if(cost[i]<=K) answer++;
    }
    return answer;
}
