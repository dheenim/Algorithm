#include <string>
#include <vector>
#include <iostream>
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[501][501];
    int row = triangle.size();
    dp[0][0] = triangle[0][0];
    for(int i=1;i<row;i++){
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        int last = triangle[i].size()-1;
        int beforeLast = triangle[i-1].size()-1;
        dp[i][last] = dp[i-1][beforeLast] + triangle[i][last];
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<triangle[i].size()-1;j++){
            dp[i][j] = MAX(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    
    int lastSize = triangle[row-1].size();
    
    /*for(int i=0;i<row;i++){
        for(int j=0;j<triangle[i].size();j++){
            cout << dp[i][j] <<" ";
        }
        cout<<endl;
    }*/
    
    for(int i=0; i<lastSize; i++){
        answer = MAX(answer, dp[row-1][i]);
    }
    return answer;
}
