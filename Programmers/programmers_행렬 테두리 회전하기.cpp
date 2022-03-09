#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> mat(rows+1, vector<int>(columns+1,0));
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            mat[i][j] = (i-1)*columns + j;
        }
    }
    for(auto qur:queries){
        int r1 = qur[0], r2 = qur[2];
        int c1 = qur[1], c2 = qur[3];
        int min_ = mat[r1][c1];
        queue<int> q;
        //위쪽 가로
        for(int c=c1;c<=c2;c++){
            q.push(mat[r1][c]);
            if(mat[r1][c]<min_) min_ = mat[r1][c];
        }
        //오른쪽 세로
        for(int r=r1+1;r<=r2;r++){
            q.push(mat[r][c2]);
            if(mat[r][c2] < min_) min_ = mat[r][c2];
        }
        //아래 가로
        for(int c=c2-1;c>=c1;c--){
            q.push(mat[r2][c]);
            if(mat[r2][c]<min_) min_ = mat[r2][c];
        }
        //왼쪽 세로
        for(int r=r2-1;r>r1;r--){
            q.push(mat[r][c1]);
            if(mat[r][c1]<min_) min_ = mat[r][c1];
        }
        
        //입력
        //위쪽 가로
        for(int c=c1+1;c<=c2;c++){
            mat[r1][c] = q.front();
            q.pop();
        }
        //오른쪽 세로
        for(int r=r1+1;r<=r2;r++){
            mat[r][c2] = q.front();
            q.pop();
        }
        //아래 가로
        for(int c=c2-1;c>=c1;c--){
            mat[r2][c] = q.front();
            q.pop();
        }
        //왼쪽 세로
        for(int r=r2-1;r>=r1;r--){
            mat[r][c1] = q.front();
            q.pop();
        }
        
        answer.push_back(min_);
    }
    return answer;
}
