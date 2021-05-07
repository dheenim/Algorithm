#include <string>
#include <vector>
#include<cstring>
#include<iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int map[1001][1001];
    memset(map, 0, sizeof(map));
    int i = -1, j = 0, dir = 0, num = 1;
    int nn=n;
    while (n-- > 0) {
        if (dir == 0) {
            for (int k = 0; k <= n; k++) {
                i++;
                map[i][j] = num++;
            }
            dir = (dir + 1) % 3;
        }
        else if (dir == 1) {
            for (int k = 0; k <= n; k++) {
                j++;
                map[i][j] = num++;
            }
            dir = (dir + 1) % 3;
        }
        else if (dir == 2) {
            for (int k = 0; k <= n; k++) {
                i--; j--;
                map[i][j] = num++;
            }
            dir = (dir + 1) % 3;
        }
    }
    for(int i=0;i<nn;i++){
        for(int j=0;j<nn;j++){
            //cout<<map[i][j]<<" ";
            if(map[i][j]!=0) answer.push_back(map[i][j]);
            if(map[i][j]==0) break;
        }
        //cout<<endl;
    }
    return answer;
}
