#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i=0;i<progresses.size();i++){
        q.push(ceil((100-progresses[i])/(double)speeds[i]));
    }
    int cnt = 1;
    int maxD = q.front(); q.pop();
    while(!q.empty()){
        int nq = q.front(); q.pop();
        if(maxD < nq){
            maxD = nq;
            answer.push_back(cnt);
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    answer.push_back(cnt);
    return answer;
}
