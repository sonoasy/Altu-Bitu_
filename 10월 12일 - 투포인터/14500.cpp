#include <iostream>
#include <vector>

using namespace std;

int ans, n, m;//답, nxm행렬
vector<vector<int>> board; //숫자 저장 벡터
int dr[4] = { -1, 1, 0, 0 }; //행 좌,우,상,하
int dc[4] = { 0, 0, -1, 1 };//열 좌,우,상,하

//board[row][col]을 가운데로 하는 +모양 만들기
int horn(int row, int col) {  //보라블럭
    int cnt = 0, min_block = 1001, sum = board[row][col];

    for (int i = 0; i < 4; i++) { //상하좌우 모두보기 
        int nr = row + dr[i]; //행
        int nc = col + dc[i];//열

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) //범위를 벗어나면 무시
            continue;
        min_block = min(min_block, board[nr][nc]); //가장자리 블럭 중 값이 가장 작은 블럭
        sum += board[nr][nc]; //되는 값 더해주기
        cnt++; //될때마다 +1 
    }

    if (cnt < 3) //가능한 가장자리가 최소 3개 이상이어야 함
        return 0; //안됨
    if (cnt == 3) //ㅗㅏㅜㅓ
        return sum;//sum을 리턴해주기
    //+
    return sum - min_block;  //4방향 다될때 가장 합의 최댓값을 리턴함
}

//한붓 그리기가 가능한 블럭들 백트래킹 탐색
void backtracking(int row, int col, int cnt, int sum) {
    if (cnt == 4) { //기저조건 : 4개의 블럭을 탐색함
        ans = max(ans, sum); //ans와 sum중에 더 큰값을 ans로 지정
        return; //종료
    }

    for (int i = 0; i < 4; i++) {//상하좌우 모두 탐색
        int nr = row + dr[i]; //행
        int nc = col + dc[i];//열

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) //범위를 벗어나거나, 이미 방문했다면
            continue; //무시 
        int save = board[nr][nc]; //되는곳 숫자 저장
        board[nr][nc] = 0; //이미 썼으므로 0으로 설정
        backtracking(nr, nc, cnt + 1, sum + save); //cnt+1하고 sum에 저장한 save값 추가해서 가기 
        board[nr][nc] = save; //다른 경우도 탐색해야하므로 다시 돌려놓음
    }
}

/**
 * 1. 각 블럭을 백트래킹이 가능한 블럭과 불가능한 블럭으로 나누기
 *    -> 블럭을 한붓 그리기로 그릴 수 있으면 백트래킹이 가능 아니라면 불가능
 *    -> 보라색 블럭을 제외하면 모두 백트래킹 가능
 * 2. 보라색 블럭은 + 모양에서 가장자리를 하나 제거한 것과 같음
 *    -> 가운데 블럭을 중심으로 가장자리 블럭을 붙여보고 가능한 최댓값 구하기
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 *
 * 해설 : https://myunji.tistory.com/297
 * *코드가 살짝 달라요(블로그 코드는 최적화 하기 전)
 */
int main() {
    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0)); //nxm 행렬
    for (int i = 0; i < n; i++) { //n행에 대하여
        for (int j = 0; j < m; j++)//m열의 
            cin >> board[i][j];// 수를 입력한다
    }

    //연산
    for (int i = 0; i < n; i++) {//n행에 대하여
        for (int j = 0; j < m; j++) {//m열의 
            ans = max(ans, horn(i, j)); //보라색 블럭 처리
            int save = board[i][j];//되는곳 숫자 저장

            board[i][j] = 0;//이미 썼으므로 0으로 설정
            backtracking(i, j, 1, save); //나머지 모양 처리
            board[i][j] = save;//다른 경우도 탐색해야하므로 다시 돌려놓음
        }
    }

    //출력
    cout << ans;
}
