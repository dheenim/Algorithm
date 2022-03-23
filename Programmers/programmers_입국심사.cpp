#include <string>
#include <vector>
#include <climits>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 1, right = LLONG_MAX-1;
    while(left < right){
        long long val = (left+right)/2;
        long long sum = 0;
        bool chk = false;
        for(int num:times){
            sum += (val/num);
            if(sum>=n){
                right = val;
                chk = true;
                break;
            }
        }
        if(!chk){
            left = val+1;
        }
    }
    answer = right;
    return answer;
}
