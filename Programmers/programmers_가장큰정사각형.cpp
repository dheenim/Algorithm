//�ڵ��׽�Ʈ ����
//��������
//���� ū ���簢�� ã��

#include <iostream>
#include<vector>
using namespace std;

int dir_row[3] = { 0, -1, -1 };//����, ����, �������밢��
int dir_col[3] = { -1, 0, -1 };

int solution(vector<vector<int>> board)
{
    int answer = 0;

    //row = 0�϶�, �ּҰ� ����
    for (int i = 0; i < board[0].size(); i++)
        if (board[0][i]) {
            answer = 1;
            break;
        }


    for (int r = 1; r < board.size(); r++) {
        for (int c = 0; c < board[r].size(); c++) {
            if (c - 1 < 0 || !board[r][c]) continue;
            int min_ = 2100000000;
            for (int dir = 0; dir < 3; dir++) {
                int chk_row = r + dir_row[dir];
                int chk_col = c + dir_col[dir];
                min_ = min_ < board[chk_row][chk_col] ? min_ : board[chk_row][chk_col];
            }
            board[r][c] = ++min_;
            answer = answer < min_ ? min_ : answer;
        }
    }

    return answer * answer;
}