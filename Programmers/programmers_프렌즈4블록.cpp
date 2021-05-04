#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <cstring>
using namespace std;

int solution(int m, int n, vector<string> board) {
    deque<char> dq[31];
    for(int i=board.size()-1;i>=0;i--){
        for(int j=0;j<board[i].size();j++){
            dq[j].push_back(board[i][j]);
        }
    }
    bool visit[31][31]; memset(visit,0,sizeof(visit));
    bool continue_;
    int answer = 0;
    do{
        /*for(int i=0;i<board[0].size();i++){
            for(int j=0;j<board.size();j++){
                cout<<dq[i][j] <<" ";
            }
            cout<<endl;
        }*/
        continue_ = false;
        for(int i=0;i<board[0].size()-1;i++){
            for(int j=0;j<board.size()-1;j++){
                if(dq[i][j]=='*')continue;
                if(dq[i][j]==dq[i][j+1]&&dq[i][j]==dq[i+1][j]&&dq[i][j]==dq[i+1][j+1]){
                    //cout <<"i:"<<i<<" j:"<<j<<", dq[i][j]:"<<dq[i][j]<<endl;
                    //dq[i].erase(dq[i].begin()+ers[k]);
                    //dq[i].push_back('*');
                    visit[i][j]=true; visit[i+1][j] = true;
                    visit[i][j+1]=true; visit[i+1][j+1] = true;
                    continue_=true;
                }
            }
        }
        for(int i=0;i<board[0].size();i++){
            //vector<int> ers;
            for(int j=board.size()-1;j>=0;j--){
                if(visit[i][j]){
                    dq[i].erase(dq[i].begin()+j);
                    dq[i].push_back('*');

                    answer++;
                    visit[i][j]=false;
                }
            }
            /*for(int k=0;k<ers.size();k++){
                dq[i].erase(dq[i].begin()+ers[k]);
                dq[i].push_back('*');
            }*/
        }
        //cout<<"ans:"<<answer<<endl;
    }while(continue_);

    return answer;
}
