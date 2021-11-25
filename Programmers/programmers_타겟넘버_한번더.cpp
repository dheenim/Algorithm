#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int totsum = 0;
    for(int i=0;i<numbers.size();i++)
        totsum+=numbers[i];
    queue<int> q;
    q.push(numbers[0]); q.push(-numbers[0]);
    int idx = 1;
    while(1){
        int qsize = q.size();
        totsum -= numbers[idx];
        while(qsize>0){
            int sum = q.front(); q.pop();
            if(sum+numbers[idx]+totsum>=target && sum+numbers[idx]-totsum<=target){
                q.push(sum+numbers[idx]);
            }
            if(sum-numbers[idx]+totsum>=target && sum-numbers[idx]-totsum<=target){
                q.push(sum-numbers[idx]);
            }
            qsize--;
        }
        idx++;
        if(idx>=numbers.size()){
            while(!q.empty()){
                if(q.front()==target) answer++;
                q.pop();
            }
            break;
        }
    }
    return answer;
}
