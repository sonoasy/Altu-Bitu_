#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;//최대 번호갯수

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>>& board) {
    return r >= 0 && r < SIZE&& c >= 0 && c < SIZE&& board[r][c] == stone; //SIZE범위 내에 있는지,돌 유효한지 확인
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>>& board) {
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = { 0, 1, 1, -1 };//행
    int dc[4] = { 1, 0, 1, 1 };//열

    //(r, c) 이전에 위치한 이어지는 돌이 있나?
    bool is_six = promising(r - dr[d], c - dc[d], stone, board); //T/F로 확인하기 

    int cnt = 0; //바둑알 수 카운트하기 
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++;//카운트+1
        r += dr[d];//행위치 바꾸기
        c += dc[d];//열위치 바꾸기 
    }
    return cnt == 5 && !is_six; //바둑알이 5개인지 리턴
}

bool isEnd(int r, int c, vector<vector<int>>& board) {
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board))//바둑알이 5개면 
            return true;  //종료
    }
    return false; //그외에는 false로 계속 진행
}

/**
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. 육목이상이 되는 경우 : (r, c) 왼쪽에 같은 돌이 있는 경우
 */
int main() {

    //백준 2615번

    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); //바둑판

    //입력
    for (int i = 0; i < SIZE; i++) { //SIZExSIZE
        for (int j = 0; j < SIZE; j++)//입력
            cin >> board[i][j];//바둑판 벡터 board에 저장
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) { //SIZE행
        for (int j = 0; j < SIZE; j++) {//SIZE열에 대하여 출력
            if (!board[i][j]) //돌이 없음
                continue;//그 다음
            if (isEnd(i, j, board)) { //누군가 이겼나?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1; //이긴 돌, 가로,세로 위치 출력
                return 0;//종료 
            }
        }
    }
    cout << 0;
}
