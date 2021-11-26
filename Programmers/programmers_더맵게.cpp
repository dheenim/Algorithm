#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    if(K==0) return 0;
    int zeros = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
        if(scoville[i] == 0) zeros++;
    }
    if(zeros>=2) return -1;
    while(1){
        int cur = pq.top();
        if(cur>=K) break;
        pq.pop();
        int next = pq.top(); pq.pop();
        int newfood = cur + next*2;
        pq.push(newfood);
        answer++;
        if(pq.size()==1 && newfood < K){
            return -1;
        }
    }
    return answer;
}
