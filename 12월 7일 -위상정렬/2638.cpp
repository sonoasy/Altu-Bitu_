#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci; //pair형 자료구조

vector<vector<int>> board; //종이 정보 
int dr[4] = {-1, 1, 0, 0}; //행 이동
int dc[4] = {0, 0, -1, 1}; //열 이동 

void dfs(int n, int m, int row, int col) { //치즈 외부 공간과 내부 공간을 구분하는 dfs 함수
    if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != 0) //범위 내에 없거나 0이 아니면 
        return; //종료 
    board[row][col] = -1; //외부 공기로 표시
    for (int i = 0; i < 4; i++) //좌표 이동 
        dfs(n, m, row + dr[i], col + dc[i]); //바뀐 좌표로 이동 
}

bool canMelt(int row, int col) { //녹을수 있는지 확인 
    int cnt = 0; //0개에서 시작 
    for (int i = 0; i < 4; i++) { //좌표 주위를 탐색
        int nr = row + dr[i]; //행
        int nc = col + dc[i];//열
        if (board[nr][nc] == -1) //외부 공간
            cnt++; //+1
    }
    return cnt >= 2; //2개이상 접촉했으면 true, 아니면 false
}

vector<ci> findCheese(int n, int m) { //치즈 찾기 
    vector<ci> list; //list에 저장하기 
    for (int i = 0; i < n; i++) { //nx
        for (int j = 0; j < m; j++) {//m에 대하여 
            if (board[i][j] == 1 && canMelt(i, j)) //녹지 않은 치즈면서, 이번에 녹일 수 있다면
                list.emplace_back(i, j); //저장하기 
        }
    }
    return list; //정보 리턴 
}

/**
 * 아이디어
 * 1. 외부 공기와 2변 이상 접촉한 치즈 찾기
 * 2. 치즈 녹이기
 * 3. 해당 치즈가 녹으면서 새로운 외부 공간이 생기지 않았는지 체크
 * !외부 공간과 내부 공간을 구분하는 것이 중요!
 *
 * 구현
 * 1. dfs 함수로 외부 공간(-1)과 내부 공간(0)을 구분하기
 * 2. 녹지 않은 치즈면서, 외부 공간과 2변 이상 접촉한(canMelt) 치즈라면 이번에 녹을 수 있음(findCheese)
 *    !주의! 녹일 수 있는 치즈를 찾자마자 녹이지 않는 이유 :
 *          한 타임의 녹을 수 있는 치즈는 모두 동시에 녹아야 한다. 만약 치즈를 바로 녹이면 연쇄적으로 외부 공간이 생겨 녹지 못하는 치즈를 녹여버릴 수 있음
 * 3-1. 만약 녹을 수 있는 치즈가 없다면(list.empty()) 모든 치즈가 녹은 것이다.
 * 3-2. 녹을 수 있는 치즈가 있다면, 치즈를 녹이고(0), 새롭게 생긴 외부 공간을 표시(dfs)한다.
 */
int main() {
    int n, m; //nxm 모눈종이 

    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m)); //모눈종이 크기 할당 
    for (int i = 0; i < n; i++) { //nx
        for (int j = 0; j < m; j++)//m 
            cin >> board[i][j]; //정보 입력 
    }

    //연산
    dfs(n, m, 0, 0); //외부 공간 표시

    int cnt = 0; //0부터 시작 
    while (true) { //계속 진행 
        vector<ci> list = findCheese(n, m); //이번에 녹을 치즈들
        if (list.empty()) //녹을 치즈 없으면
            break; //종료 
        //치즈를 녹이고, 새롭게 생긴 외부 공간 표시
        for (int i = 0; i < list.size(); i++) { //치즈 정보 수만큼 
            int row = list[i].first, col = list[i].second; //치즈 좌표 정보 
            board[row][col] = 0; //0으로 치즈 녹이기 
            dfs(n, m, row, col); //외부 공간 갱신
        }
        cnt++; //시간+1
    }

    //출력
    cout << cnt;
}
