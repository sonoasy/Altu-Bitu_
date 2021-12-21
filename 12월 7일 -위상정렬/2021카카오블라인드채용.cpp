#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci; //pair형 자료구조 
const int SIZE = 4; //size 상수 4

int dr[4] = {-1, 1, 0, 0}; //행
int dc[4] = {0, 0, -1, 1}; //열 

vector<vector<ci>> findCard(vector<vector<int>> &board) { //존재하는 모든 카드의 위치를 리턴하는 함수
    vector<vector<ci>> card_pos(7, vector<ci>(0)); //최대 카드 수
    int cnt = 0; //초기값 
    for (int i = 0; i < SIZE; i++) { //4x
        for (int j = 0; j < SIZE; j++) {//4 
            cnt = max(cnt, board[i][j]);//보드 탐색해서 카드 갯수 구하기 
            if (board[i][j]) //카드라면 위치 저장
                card_pos[board[i][j]].emplace_back(i, j); //좌표 저장 
        }
    }
    card_pos.resize(cnt + 1); //실제 존재하는 카드의 수만큼 크기 조절
    return card_pos; //카드 위치를 저장한 벡터 리턴 
}

pair<int, int> ctrl(int row, int col, int dir, vector<vector<int>> &tmp) { //컨트롤로 이동하는 좌표를 리턴하는 함수
    while (true) { //계속 진행 
        row += dr[dir]; //행 이동 
        col += dc[dir]; //열 이동 
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) //해당 방향에 카드가 하나도 없다면 그 방향의 가장 마지막 칸으로 이동
            return make_pair(row - dr[dir], col - dc[dir]); //마지막 칸으로 이동
        if (tmp[row][col] != 0) //누른 키 방향에 있는 가장 가까운 카드
            return make_pair(row, col);//해당 좌표 리턴 
    }
}

int bfs(int r1, int c1, int r2, int c2, vector<vector<int>> &tmp) { //현재 커서에서 목표 카드로 이동하는 가장 적은 비용을 리턴하는 함수
    vector<vector<int>> visited(SIZE, vector<int>(SIZE, 0));//방문 
    queue<pair<int, int>> q; //큐 
    visited[r1][c1] = 1; //반드시 엔터를 누르게 될 것. 엔터를 미리 눌렀다 가정하고 1로 표시
    q.push({r1, c1}); //큐에 넣기 

    while (!q.empty()) { //큐가 빌때까지 계속 
        int row = q.front().first; //행
        int col = q.front().second; //열
        int dist = visited[row][col];//방문 번째
        q.pop(); //큐에서 꺼내기 

        if (row == r2 && col == c2) //목표 카드에 도달했다면
            return dist; //dist 리턴 

        for (int i = 0; i < 4; i++) { //컨트롤 입력 이동
            pair<int, int> np = ctrl(row, col, i, tmp); //ctrl로 이동한 좌표
            if (visited[np.first][np.second]) //다녀간곳이면 
                continue;//다음 
            visited[np.first][np.second] = dist + 1; //값 갱신 
            q.push(np); //큐에 넣기 
        }

        for (int i = 0; i < 4; i++) { //방향키 입력 이동
            int nr = row + dr[i], nc = col + dc[i]; //다음 좌표 
            if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || visited[nr][nc]) //범위 밖이면 
                continue; //다음 
            visited[nr][nc] = dist + 1; //dist+1해서 갱신 
            q.push({nr, nc}); //큐에 넣기 
        }
    }
    return -1; //목표 카드에 도달하지 못함 (실제로는 일어나지 않는 일)
}

int matchCard(int bit, int num, int r, int c, vector<int> &seq, vector<vector<ci>> &cards, vector<vector<int>> tmp){ //조합에 대해 카드를 매칭하는 함수
    int ans = 0; //초기값
    for (int i = 0; i < num; i++) { //num만큼 
        int cur = seq[i]; //이번에 매칭할 캐릭터
        int now = 0; //해당 캐릭터의 0번째 카드부터 선택한다고 가정
        if (bit & (1 << i)) //만약 해당 위치의 비트가 1을 표시했다면 1번째 카드부터 선택
            now = 1; //1 지정

        for (int j = 0; j < 2; j++) { //2번
            now = (now + j) % 2; //이번에 매칭할 카드 인덱스
            int nr = cards[cur][now].first, nc = cards[cur][now].second; //이번에 매칭할 카드 위치
            ans += bfs(r, c, nr, nc, tmp); //현재 커서에서 목표 카드까지 이동하는 비용

            //카드 삭제 + 커서 이동
            tmp[nr][nc] = 0; //0으로 설정 
            r = nr;//행
            c = nc; //열 
        }
    }
    return ans; //비용 리턴 
}

int solution(vector<vector<int>> board, int r, int c) { //solution 함수 
    int answer = 1e9; //초기값 

    vector<vector<ci>> cards = findCard(board); //존재하는 모든 카드의 위치
    int card_cnt = cards.size() - 1; //카드의 개수

    vector<int> seq(card_cnt); //순열을 위한 배열
    for (int i = 0; i < card_cnt; i++) //카드갯수만큼 
        seq[i] = i + 1; //+1 

    do { //가능한 모든 카드 순서에 대해
        for (int bit = 0; bit < (1 << card_cnt); bit++) { //0, 1번째 카드 중 어떤 카드를 먼저 뒤집을지 결정
            answer = min(answer, matchCard(bit, card_cnt, r, c, seq, cards, board)); //최소 비용으로 갱신 
        }
    } while (next_permutation(seq.begin(), seq.end())); //순열계속
    return answer; //결과 리턴 
}

/**
 * 아이디어
 * 1. 범위가 크지 않음
 * 2. 존재하는 모든 카드의 종류는 6개, 카드 2장이 한 쌍을 이룬다.
 * 3. 뒤집을 카드 순서를 정하는 모든 경우의 수는 6!(카드 순서) * 2^6(2개의 카드 중 어떤 카드를 먼저 뒤집을지) -> 브루트포스 가능
 * 4. 이번에 목표로 하는 카드에 대해 현재 커서에서 목표 카드까지 가는 최단 경로를 구하며 이동 횟수 전부 구하고 최솟값 갱신
 *
 * 구현
 * 1. 존재하는 모든 카드의 위치를 저장하며 카드의 개수 세기 (findCard)
 * 2. 가능한 모든 카드의 순서(next_permutation)와 각 카드를 뒤집을 순서(bitmask)를 결정
 *    ex) seq = {3, 1, 2}, bit = 011 일 때
 *        3번, 1번, 2번 카드의 순서로 뒤집는다.
 *        3번 카드는 1번째 카드부터, 1번 카드는 0번째 카드부터, 2번 카드는 1번째 카드부터 뒤집는다.
 *        bit의 011이 앞에서부터 각각 1, 2, 3번 카드와 대응함
 * 3. 현재 카드 순서와 각 카드를 뒤집는 순서에 대한 커서 이동 횟수 계산 (matchCard)
 *    현재 커서 위치와 목표 카드 위치에 대해 bfs 함수 실행
 *    컨트롤 입력을 고려해야 하기 때문에 4방향에 대한 방향 이동에 추가로 컨트롤 입력도 처리한다.(ctrl)
 * 4. 매 조합에 따라 board가 갱신되므로 board를 복사한 tmp 사용
 * 공식 풀이 : https://tech.kakao.com/2021/01/25/2021-kakao-recruitment-round-1/
 */
int main() {
    vector<vector<int>> board = {{1, 0, 0, 3},  //테스트 케이스 
                                 {2, 0, 0, 0},
                                 {0, 0, 0, 2},
                                 {3, 0, 1, 0}};
    cout << solution(board, 1, 0); //조작횟수 최솟값 출력 
}
