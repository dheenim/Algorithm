#include <string>
#include <vector>
#include <cstring>
#define DIV 1000000007 
using namespace std;
int Row, Col;
int map[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    Row = n; Col = m;
    memset(map,0,sizeof(map));
    for(int i=0;i<puddles.size();i++){
        map[puddles[i][1]][puddles[i][0]] = -1;
    }
    map[0][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j] == -1) continue;
            int a=0,b=0;
            if(map[i-1][j]!=-1) a=map[i-1][j];
            if(map[i][j-1]!=-1) b=map[i][j-1];
            map[i][j] = (a+b)%DIV;
        }
    }
    
    int answer = map[n][m]%DIV;
    return answer;
}
