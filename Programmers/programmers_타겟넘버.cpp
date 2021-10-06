#include <string>
#include <vector>

using namespace std;
vector<int> nums;
int tgt;
int answer;

bool promising(int sum, int totalSum){
    if(sum-totalSum > tgt || sum + totalSum < tgt) return false;
    return true;
}

void dfs(int idx, int sum, int totalSum){
    if(promising(sum, totalSum)){
        if(nums.size() == idx){
            if(tgt == sum) answer++;
            return;
        }
        dfs(idx+1, sum + nums[idx], totalSum - nums[idx]);
    
        dfs(idx+1, sum - nums[idx], totalSum - nums[idx]);
    }
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    nums.clear();
    nums = numbers;
    tgt = target;
    int sum=0;
    for(int i=0;i<numbers.size();i++){
        sum+=numbers[i];
    }
    dfs(0,0,sum);
    return answer;
}
