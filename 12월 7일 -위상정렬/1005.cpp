#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬 + DP
int topologicalSort(int n, int w, vector<int> &delay, vector<int> &indegree, vector<vector<int>> &graph) {
    //vector<int> result;
    queue<int> q; //큐 
    vector<int> dp(n + 1, 0); //현재 건물(인덱스)을 짓기까지 걸린 최소 시간

    for (int i = 1; i <= n; i++) { //n개에 대하여
        dp[i] = delay[i]; //dp 배열 초기화
        if (!indegree[i]) //진입차수가 0이라면
            q.push(i); //큐에 넣기 
    }
    while (!q.empty()) { //큐가 빌때까지 계속하기 
        int node = q.front(); //큐 맨앞 번호 정보
        q.pop();//큐에서 꺼내기 

        //result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) { //현재 건물번호에 연결된 모든 건물 탐색
            int next_node = graph[node][i]; //다음 건물 
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node); //큐에 넣기 

            //다음 정점의 최소 시간 계산 -> 이어진 전 정점(현재 정점) 중 가장 긴 시간의 건물을 선택
            dp[next_node] = max(dp[next_node], dp[node] + delay[next_node]);
        }
    }
    return dp[w]; //시간 정보 리턴
}

int main() {
    int t, n, k, x, y, w; //테스트 케이스 갯수 t, 건물 갯수 n, 규칙 갯수 k, 건설 순서 x-y, 건설해야 하는 건물 번호 w

    //입력
    cin >> t;
    while (t--) { //t개 테스트 케이스 
        cin >> n >> k; //n,k 입력
        vector<int> indegree(n + 1, 0); //진입차수
        vector<vector<int>> graph(n + 1, vector<int>(0)); //그래프
        vector<int> delay(n + 1, 0); //건설에 걸리는 시간
        for (int i = 1; i <= n; i++) //n개의 
            cin >> delay[i]; //시간 정보 저장
        while (k--) { //규칙 k 
            cin >> x >> y; //x -> y
            indegree[y]++; //y의 진입차수 +1
            graph[x].push_back(y); //연결 x-y 저장 
        }
        cin >> w; //승리하기 위해 건설해야 할 건물의 번호

        //연산 & 출력
        cout << topologicalSort(n, w, delay, indegree, graph) << '\n';
    }
    return 0; //종료 
}
