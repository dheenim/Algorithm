#include <string>
#include <vector>

using namespace std;
int ones = 0, zeros = 0;
vector<vector<int>> map;
void quadT(int start_row, int start_col, int end_row, int end_col){
    int first=map[start_row][start_col];
    bool flag = true;
    for(int i=start_row;i<end_row;i++){
        for(int j=start_col;j<end_col;j++){
            if(map[i][j]!=first){
                quadT(start_row,start_col,(start_row+end_row)/2,(start_col+end_col)/2);
                quadT(start_row,(start_col+end_col)/2,(start_row+end_row)/2,end_col);
                quadT((start_row+end_row)/2,start_col,end_row,(start_col+end_col)/2);
                quadT((start_row+end_row)/2,(start_col+end_col)/2,end_row,end_col);
                flag=false;
                break;
            }
        }
        if(!flag) break;
    }
    if (flag) {
            if(first == 1) ones++;
            else zeros++;
    }

}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    map = arr;
    quadT(0, 0, arr.size(), arr.size());
    answer.push_back(zeros); answer.push_back(ones);
    return answer;
}
