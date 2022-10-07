#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2000000000
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<pair<int,int> > > map(N+1);
    vector<int> costs(N+1, INF);
    costs[1] = 0;
    for(int i=0;i<road.size();i++){
        //0 : start , 1:dest, 2:cost
        map[road[i][0]].push_back({road[i][1], road[i][2]});
        map[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    for(int i=1;i<=N;i++){
        sort(map[i].begin(),map[i].end(),cmp);
    }

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int start = q.front();
        //cout << "start:" << start <<endl;
        q.pop();
        for(int i=0;i<map[start].size();i++){
            int dest = map[start][i].first;
            int cost = map[start][i].second;
            if(cost + costs[start] < costs[dest]){
                //cout<< "start:"<<start<<"->"<<dest<<":"<<cost+costs[start] << endl;
                costs[dest] = cost + costs[start];
                q.push(dest);
            }
        }
    }
    for(int i=1;i<=N;i++){
        //cout << costs[i] <<endl;
        if(costs[i] <=K) answer++;
    }
    
    return answer;
}
