#include <string>
#include <vector>
#include <queue>
using namespace std;
//섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i] * -1);
    }
    while(!pq.empty()){
        if(pq.size() == 1){
            if(pq.top()*-1 < K) answer = -1;
            break;
        }
        int min1 = pq.top() * -1; pq.pop();
        if(min1 >= K) break;
        int min2 = pq.top() * -1; pq.pop();
        pq.push( -(min1 + min2*2) );
        answer++;
    }
    return answer;
}
