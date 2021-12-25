#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> board; //보드 벡터 
int dr[2] = {1, 0}; //행
int dc[2] = {0, 1}; //열 

int cntCandy(int n, int row, int col, int dir) { //연속하는 사탕 갯수 구하기 
    int ans = 0, cnt = 0; //0부터 시작 
    char cur = ' '; //초기값
    for (int i = 0; i < n; i++) { 
        if (cur == board[row][col]) { //연속된 사탕
            cnt++; //+1 
            ans = max(ans, cnt); //갱신 
        } else { //불연속
            cnt = 1;//1개 
            cur = board[row][col]; //지금 사탕 정보 
        }
        row += dr[dir]; //행 위치 갱신
        col += dc[dir]; //열 위치 갱신 
    }
    return ans; //갯수 리턴 
}

int findCandy(int n) { //최종 사탕 갯수 
    int ans = 0; //초기값
    for (int i = 0; i < n; i++) { //모두 탐색 
        ans = max(ans, cntCandy(n, 0, i, 0)); //같은 열에 대해
        ans = max(ans, cntCandy(n, i, 0, 1)); //같은 행에 대해
    }
    return ans; //결과 리턴 
}

int switchCandy(int n, int row, int col, char candy) { //
    int ans = 0; //초기값 
    for (int i = 0; i < 2; i++) { //오른쪽, 아래에 있는 사탕과 바꿔보기
        int nr = row + dr[i], nc = col + dc[i]; //다음 좌표 위치 
        if (nr < n && nc < n && candy != board[nr][nc]) { //범위 내에 있고 다른 캔디면 
            swap(board[row][col], board[nr][nc]); //바꾸기 
            ans = max(ans, findCandy(n)); //갯수 세기
            swap(board[row][col], board[nr][nc]); //다시 정보 되돌리기 
        }
    }
    return ans; //결과값 반환 
}

/**
 * 입력 범위가 크지 않으므로 바꿀 수 있는 사탕을 모두 바꿔보며 먹을 수 있는 사탕 계산
 * 오른쪽, 아래에 있는 사탕과만 바꿔도 모든 경우 고려 가능(왼쪽, 위 고려 X)
 *
 * 1. 사탕의 색이 다른 사탕만 교환하기
 * 2. 각 열, 행이 모두 같은 사탕일 때 사탕의 개수가 갱신되지 않도록 주의 (ans 갱신을 line 18~21에서 하는 경우)
 */
int main() {
    int n, max_candy = 0; //보드의 크기, 최대 먹을수 있는 사탕갯수

    //입력
    cin >> n;
    board.assign(n, vector<char>(n, ' ')); //보드 초기화 
    for (int i = 0; i < n; i++) //nx
        for (int j = 0; j < n; j++)//n에 대하여 
            cin >> board[i][j];//정보 입력 

    //연산
    for (int i = 0; i < n; i++) { //nx
        for (int j = 0; j < n; j++)//n에 대하여 
            max_candy = max(max_candy, switchCandy(n, i, j, board[i][j])); //사탕을 바꾸면서 최댓값 계산하기 
    }

    //출력
    cout << max_candy;
}
