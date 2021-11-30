#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;//최대값
typedef pair<int, int> ci; //pair형

pair<int, ci> nextPos(int n, int shark_size, ci& shark, vector<vector<int>>& board) {
    int dr[4] = { -1, 1, 0, 0 };//행 이동
    int dc[4] = { 0, 0, -1, 1 };//열 이동

    int min_dist = INF;//초기값 설정
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> visited(n, vector<int>(n, 0)); //상어의 방문 여부
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    visited[shark.first][shark.second] = 1; //방문 체크
    q.push(shark);//큐에 넣음
    while (!q.empty()) {//큐가 빌때까지
        int row = q.front().first;//행위치
        int col = q.front().second;//열위치
        int dist = visited[row][col];//계산
        q.pop();//큐에서 꺼냄

        if (dist >= min_dist) //최단거리 이상은 탐색할 필요 없음
            continue;//계속
        for (int i = 0; i < 4; i++) {//상하좌우
            int nr = row + dr[i];//행 이동
            int nc = col + dc[i];//열이동
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] > shark_size)//범위 밖이면
                continue;//다음으로

            visited[nr][nc] = visited[row][col] + 1;//범위 내이면 +1
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc);//추가
                min_dist = visited[nr][nc];//갱신
                continue;//계속하기
            }
            q.push({ nr, nc });//큐에 넣기 
        }
    }

    if (list.empty()) //상어가 갈 수 있는 곳이 없음
        return { min_dist, {-1, -1} };//리턴하기

    sort(list.begin(), list.end(), [](const ci& p1, const ci& p2) { //정렬
        if (p1.first != p2.first)//first가 다르면
            return p1.first < p2.first;//오름차순 정렬
        return p1.second < p2.second;//second 기준 오름차순 정렬
        });
    return { min_dist - 1, list[0] };//리턴
}

int simulation(int n, pair<int, int>& shark, vector<vector<int>>& board) {
    int ans = 0, size = 2, cnt = 0; //초기값
    while (true) {//계속 실행
        pair<int, ci> result = nextPos(n, size, shark, board);//result애 결과 저장
        if (result.first == INF) //더 이상 먹을 수 있는 물고기가 공간에 없음
            break;//종료
        ans += result.first;//min_dist 더해주기
        cnt++;//+1
        if (cnt == size) { //상어 크기 증가
            cnt = 0;//먹은 갯수 다시 0으로 
            size++;//사이즈+1
        }

        //상어 이동
        ci pos = result.second;//위치
        board[shark.first][shark.second] = 0; //0으로 설정
        shark = pos;//위치 
    }
    return ans; //답 출력
}

/**
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */
int main() {
    int n;//n개의 줄 입력
    pair<int, int> shark_pos;//상어 위치

    //입력
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));//board 벡터
    for (int i = 0; i < n; i++) {//nx
        for (int j = 0; j < n; j++) {//n에 대하여
            cin >> board[i][j];//입력
            if (board[i][j] == 9) //상어의 초기 위치
                shark_pos = make_pair(i, j);//위치 저장
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
}
