#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7; //최대 n-1개의 간선을 지나게 됨

//플로이드-워셜
void floydWarshall(int n, vector<vector<int>>& graph) { //도시의 갯수,graph 갱신값 벡터에 저장 
    for (int k = 1; k <= n; k++) { //중간 k, i-j-k 
        for (int i = 1; i <= n; i++) { //i-j
            for (int j = 1; j <= n; j++) {//i-j
                int dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                graph[i][j] = min(graph[i][j], dist); //i->j와 i->k->j 중 더 짧은 경로
            }
        }
    }
}

int main() {

    //벡준 11404번
    int n, m, a, b, c; //도시의 개수:n, 버스의 개수:m,시작 도시:a, 도착도시:b, 비용:c

    //입력
    cin >> n >> m; //도시의 개수, 버스의 개수 입력
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); //2차원 벡터
    for (int i = 1; i <= n; i++) //자기 자신과의 거리
        graph[i][i] = 0; //0으로 설정

    while (m--) { //모든 m개의 버스에 대한 정보
        cin >> a >> b >> c; // 시작도시-도착도시-비용
        graph[a][b] = min(graph[a][b], c); //중복 간선이 들어올 수 있으므로 최솟값 사용
    }

    //연산
    floydWarshall(n, graph); //도시 a-b간 최소 비용 구하기 

    //출력
    for (int i = 1; i <= n; i++) { //모든 도시간의 비용을 탐색했을때 
        for (int j = 1; j <= n; j++) //만약 INF가 있으면 경로 없음, 0을 출력
            cout << ((graph[i][j] == INF) ? 0 : graph[i][j]) << ' '; //그 외에는 graph값 출력
        cout << '\n'; //띄어쓰기 
    }
}
