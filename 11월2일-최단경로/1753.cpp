#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci; //int pair 형 ci
const int INF = 1e5 * 2; //최대 V-1개의 간선을 지나게 됨

//다익스트라
vector<int> dijkstra(int vertex, int start, vector<vector<ci>>& graph) {//정점의 갯수, 시작번호, graph 벡터
    vector<int> dist(vertex + 1, INF); //dist 값 모두 INF로 초기화 
    priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터의 거리, second : 정점

    //시작 위치 초기화
    dist[start] = 0; //0으로 지정
    pq.push({ 0, start }); //거리, 시작 번호 큐에 넣음

    while (!pq.empty()) { //큐가 빌때까지 계속 진행
        int weight = pq.top().first;//가중치 거리
        int node = pq.top().second;//정점
        pq.pop();//큐에서 꺼냄

        if (weight > dist[node]) //이미 확인했던 정점  이렇게 되는 경우?
            continue;//아무것도 하지 않음 
        for (int i = 0; i < graph[node].size(); i++) {//node와 연결된 모든 정점에 대하여 
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리
            if (dist[next_node] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[next_node] = next_weight;//갱신하기
                pq.push({ next_weight, next_node });//큐에 넣기
            }
        }
    }
    return dist; //dist 반환
}

int main() {
    int vertex, edge, k, u, v, w; //vertex: 정점의 개수,edge:간선의 갯수, 각 간선 정보 매개변수 u,v,w

    //입력
    cin >> vertex >> edge >> k; //정점의 개수, 간선의 갯수,시작 정점의 번호
    vector<vector<ci>> graph(vertex + 1, vector<ci>(0)); //인접 리스트
    while (edge--) { //모든 간선에 대한 정보 입력
        cin >> u >> v >> w; //u ->v , 가중치 w
        graph[u].emplace_back(v, w); //방향 그래프  emplace back은 객체없이 가능
    }
    //2차원 벡터가 아니라 번호 u자리에 쌍 v,w를 저장, 여러개일수 있으므로 2차원..?
    //리스트같이 구현하는듯
    //여러 간선 가능?
    
    //연산
    vector<int> ans = dijkstra(vertex, k, graph); //다익스트라, dist 반환 저장

    //출력
    for (int i = 1; i <= vertex; i++) { //모든 정점에 대하여 
        if (ans[i] == INF) //dist를 반환받은 ans가 INF이면 
            cout << "INF"; //INF 출력
        else //그 외에 값이 있으면
            cout << ans[i]; //값 출력
        cout << '\n'; //띄어쓰기
    }
}
