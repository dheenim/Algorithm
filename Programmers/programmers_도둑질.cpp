#include <string>
#include <vector>
#define MAX(A,B) (A)>(B)?(A):(B)
using namespace std;
int house;
long long dp1[1000001];
long long dp2[1000001];
long long solution(vector<int> money) {
    house = money.size();
    if(house == 3){
        if(money[0]>=money[1] && money[0]>=money[2]) return money[0];
        if(money[1]>=money[0] && money[1]>=money[2]) return money[1];
        if(money[2]>=money[1] && money[2]>=money[0]) return money[2];
    }
    dp1[0] = dp1[1] = money[0];
    for(int i=2;i<house-1;i++){
        dp1[i] = MAX(dp1[i-1],dp1[i-2]+money[i]);
    }
    dp2[1] = money[1];
    for(int i=2;i<=house-1;i++){
        dp2[i] = MAX(dp2[i-1],dp2[i-2]+money[i]);
    }
    long long answer = MAX(dp1[house-2], dp2[house-1]);
    return answer;
}
