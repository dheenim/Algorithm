#include <string>
#include <vector>
#define MAX(a,b) ((a)>(b))?(a):(b)
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int depth = triangle.size();
    for(int d=depth-2; d>=0; d--){
        for(int w=0;w<triangle[d].size();w++){
            triangle[d][w] += MAX(triangle[d+1][w], triangle[d+1][w+1]);
        }
    }
    answer = triangle[0][0];
    return answer;
}
