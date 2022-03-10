#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto place:places){
        bool good = true;
        for(int r=0;r<5;r++){
            for(int c=0;c<5;c++){
                if(place[r][c] == 'P'){
                    if(r+1<5 && place[r+1][c]=='P'){
                        good = false;
                        break;
                    }
                    if(c+1<5 && place[r][c+1]=='P'){
                        good = false;
                        break;
                    }
                    //우측 두칸
                    if(c+2<5 && place[r][c+2] == 'P' && place[r][c+1] != 'X'){
                        good = false;
                        break;
                    }
                    //좌측 대각선
                    if((r+1<5&&c-1>=0)&&place[r+1][c-1] == 'P' && (place[r][c-1] != 'X' || place[r+1][c] != 'X')){
                        good = false;
                        break;
                    }
                    //우측 대각선
                    if((r+1<5&&c+1<5)&&place[r+1][c+1] == 'P' && (place[r][c+1] != 'X' || place[r+1][c] != 'X')){
                        good = false;
                        break;
                    }
                    //아래 두칸
                    if((r+2<5)&&place[r+2][c] == 'P' && place[r+1][c] != 'X'){
                        good = false;
                        break;
                    }
                }
            }
        }
        answer.push_back(good);
    }
    return answer;
}
