#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>>& board) {
    //상, 우, 하, 좌
    int dr[4] = { -1, 0, 1, 0 }; //행
    int dc[4] = { 0, 1, 0, -1 }; //열

    int step = 0, ans = 0; //회전, ans
    while (true) {//계속 진행 
        if (board[r][c] == 0) {//빈칸이면
            board[r][c] = 2; //청소
            ans++; //+1
        }

        if (step == 4) {//4방향
            if (board[r - dr[d]][c - dc[d]] == 1)//벽 마주치면
                return ans; //청소 갯수 리턴
            r -= dr[d];//행 움직임
            c -= dc[d];//열 움직임
            step = 0;//초기화
        }
        else {
            d = (d + 3) % 4;  //왼쪽으로
            if (board[r + dr[d]][c + dc[d]]) {//이동
                step++;//step+1
                continue;//계속하기
            }
            r += dr[d];//행 움직임
            c += dc[d];//열움직임
            step = 0;//초기화
        }
    }
}

/**
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d; //변수

    //입력
    cin >> n >> m >> r >> c >> d;
    vector<vector<int>> board(n, vector<int>(m, 0)); //저장
    for (int i = 0; i < n; i++) { //n개의 
        for (int j = 0; j < m; j++) {//m열에 대하여
            cin >> board[i][j]; //정보 입력
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);
    return 0; //종료
}
