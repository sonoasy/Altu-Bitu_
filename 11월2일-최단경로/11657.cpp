#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef long long ll; //long long
typedef tuple<int, int, int> ti; //3개의 int 정보를 기본으로 하는 ti
const int INF = 1e6 * 5; // 최댓값

//벨만-포드
vector<ll> bellmanFord(int n, int m, int start, vector<ti>& edges) {//도시갯수, 버스갯수,시작도시,노선 정보
    //오버플로우 X, 언더플로우 O
    //500 * 6,000 * (-10,000) => int 범위 넘어감!
    vector<ll> dist(n + 1, INF); //dist 벡터

    dist[start] = 0; //시작 위치 초기화

    for (int i = 1; i <= n; i++) { //모든 도시에 대해서 
        bool flag = true; //더 이상 반복문을 실행할 필요가 없는지 확인
        for (int j = 0; j < m; j++) { //모든 버스에 대해서 
            //s->d로 가는 간선의 가중치가 w
            int s = get<0>(edges[j]); //s->d에서 s
            int d = get<1>(edges[j]);//d
            int w = get<2>(edges[j]);//가중치

            if (dist[s] == INF) //아직 시작점에서 s로 가는 경로가 발견되지 않았으므로 갱신할 수 없음
                continue; //아무것도 하지 않고 다음으로 넘어가기
            ll next_weight = w + dist[s]; //갱신하려는 값
            if (dist[d] > next_weight) { //더 짧은 경로로 갈 수 있다면
                if (i == n) //n번째 갱신이었다면 음의 사이클이 발생한 것
                    return { INF + 1 }; //음의 사이클임
                dist[d] = next_weight;//음의 사이클이 아니면 
                flag = false;//계속
            }
        }
        if (flag) //더 이상 갱신되지 않았다면 더 탐색할 필요 없음
            break; //끝
    }
    return dist; //dist 반환
}

int main() {
    int n, m, a, b, c;//도시의 갯수 n, 버스 갯수  m, 시작도시 a, 도착도시 b,걸리는 시간 c

    //입력
    cin >> n >> m; //도시의 갯수, 버스 갯수
    vector<ti> edges(m); //간선 정보를 저장할 벡터 (그래프 관계보다는 간선 자체의 정보가 더 중요함)
    for (int i = 0; i < m; i++) {//모든 버스 노선 입력
        cin >> a >> b >> c; //시작도시-도착도시-걸리는 시간
        edges[i] = { a, b, c }; //방향 그래프
    }

    //연산
    vector<ll> ans = bellmanFord(n, m, 1, edges); //벨만포드

    //출력
    if (ans[0] == INF + 1) { //음의 사이클
        cout << -1; //-1을 출력
        return 0; //종료
    }
    for (int i = 2; i <= n; i++) //INF면 -1 출력, 아니면 값 출력
        cout << ((ans[i] == INF) ? -1 : ans[i]) << '\n';//출력
}
