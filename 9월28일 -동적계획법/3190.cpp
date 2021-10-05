#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci; //pair 형 ci로 설정

//좌표 이동 
ci dir[4] = { {0,  1},  //우
             {-1, 0},  //상
             {0,  -1}, //좌
             {1,  0} }; //하

//게임을 진행하는 함수
int playGame(int n, vector<vector<int>>& board, map<int, char>& cmd) {
    //뱀 초기화
    deque<ci> snake;
    //뱀이 처음 있는 위치(0,0)을 입력해준다
    snake.push_front(ci(0, 0));
    //보드 위에 배미 있다는 표시를 1로 해준다
    board[0][0] = 1;

    int t = 0, head = 0; //시간, 뱀의 머리 방향(우로 초기화되어 있음)
    
    //종료조건을 만나기전에 계속 진행한다
    while (true) {
        t++;
        //뱀의 머리가 위치하게될 칸
        int nr = snake.front().first + dir[head].first; //지금 뱀의 행좌표와
        int nc = snake.front().second + dir[head].second;//지금 뱀의 열좌표에 움직여야할 방향으로 이동한 좌표로 설정한다

        //게임 종료 조건 : 벽에 부딪히거나, 자기자신의 몸과 부딪힘
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1) //움직여야할 좌표가 벽에 부딛히거나 board값이 1로 자기자신과 만나면
            break; //게임을 종료한다

        if (board[nr][nc] != 2) { //이동한 칸에 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
            board[snake.back().first][snake.back().second] = 0; //뱀의 최신값을 front로 입력받으므로  꼬리는 back쪽에 있음, 보드에 꼬리 없어짐
            snake.pop_back(); //뱀에서도 꼬리 없앰
        }
        //사과가 있으면
        //뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다
        snake.push_front(ci(nr, nc)); //꼬리는 움직이지 않음
        board[nr][nc] = 1; //뱀이 이동한것 표시해주기 

        //이번에 방향을 변환하는지 확인
        if (cmd[t] == 'L') //왼쪽 회전
            head = (head + 1) % 4; //왼쪽으로 90도 회전은 방향의 r의 값이 -1로 바뀜 
        if (cmd[t] == 'D') //오른쪽 회전
            head = (head + 3) % 4;//오른쪽으로 90도 회전은 방향의 r값이 1로 바뀜
    }
    //끝나는 시간 반환
    return t;
}

/**
 * 0 0 1
 * 0 2 1
 * 0 0 1
 *
 * 편의를 위해 문제와 달리 (0, 0)부터 시작
 *
 * 보드의 상태가 위와 같을 때
 * 뱀의 몸은 (0, 2)~(2, 2)에 걸쳐 있고, 사과는 (1, 1)에 위치하고 있음
 * -> 뱀의 꼬리와 머리 위치를 알기 위해 덱 사용
 * -> 덱의 front : 머리, 덱의 back : 꼬리
 *
 * 원활한 방향 변환을 위해 dir 배열 사용
 */
int main() {
    //보드의 크기:n, 사과의 갯수:k, 사과가 있는 위치 저장 행,열:row,col, 뱀의 방향 변환 횟수:l, 변할때 시간:x, 
    int n, k, row, col, l, x;
    char c; //변할때 방향:c 

    //입력
    cin >> n >> k;

    //nxn 박스 형성
    vector<vector<int>> board(n, vector<int>(n));
    //사과 있는 갯수만큼
    for (int i = 0; i < k; i++) {
        cin >> row >> col; //있는 위치의 행,렬 값을 입력
        board[row - 1][col - 1] = 2; //사과 표시
    }
    cin >> l; //방향 변환 횟수 입력
    map<int, char> cmd;//cmd map 에 방향 변환 조작 정보를 저장

    for (int i = 0; i < l; i++) { //회전 정보
        cin >> x >> c; //시간-방향을 입력
        cmd[x] = c;//시간에 대하여 방향을 저장
    }

    //연산 & 출력
    cout << playGame(n, board, cmd);
}
