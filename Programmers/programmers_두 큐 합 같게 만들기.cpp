#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int solution(vector<int> q1, vector<int> q2) {
    ull sum = 0;
    int q1Size = q1.size();
    int q2Size = q2.size();
    int totSize = q1Size+q2Size;
    ull lsum;
    for(int i=0;i<q1Size;i++) sum += q1[i];
    lsum = sum;
    for(int i=0;i<q2Size;i++) {
        sum += q2[i];
        q1.push_back(q2[i]);
    }

    if(sum%2 == 1) return -1;
    
    sum = sum/2;
    
    bool possi = false;
    int left = 0, right = q1Size-1;

    //ull lsum = q1[0];
    int ans = 0;
    while(left < totSize && right < totSize){
        if(lsum == sum) {
            possi = true;
            break;
        }
        else if(lsum < sum){
            right++;
            lsum += q1[right];
        }
        else{
            lsum -= q1[left];
            left++;
        }
        ans++;
    }
    
    if(!possi) return -1;
    else return ans;
    return left + abs(q1Size - right - 1);
}
