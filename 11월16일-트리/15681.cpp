#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_cnt; //서브트리 

int treeDp(int cur, vector<vector<int>>& graph) {
    if (subtree_cnt[cur] != -1) //이미 탐색했던 상태
        return subtree_cnt[cur]; //리턴

    //서브트리에 속한 정점의 수를 세고, 저장
    subtree_cnt[cur] = 0;
    int node = 1;//초기 갯수 
    for (int i = 0; i < graph[cur].size(); i++) //그래프 사이즈만큼 탐색
        node += treeDp(graph[cur][i], graph); //저장
    return subtree_cnt[cur] = node;//리턴
}

/**
 * PPT 트리의 정점의 수 구하기 응용
 *
 * 1. 루트에서부터 dfs 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 계산
 */
int main() {
    ios::sync_with_stdio(false); //속도 향상
    cin.tie(NULL); //속도 향상

    int n, r, q, u, v, input; //변수

    //입력
    cin >> n >> r >> q;
    vector<vector<int>> graph(n + 1, vector<int>(0)); //그래프 벡터
    subtree_cnt.assign(n + 1, -1); //서브트리 초기화

    while (--n) { //무방향 그래프
        cin >> u >> v; //u-v
        graph[u].push_back(v);//u-v
        graph[v].push_back(u);//v-u
    }

    //연산
    treeDp(r, graph);

    //출력
    while (q--) {
        cin >> input; //쿼리
        cout << subtree_cnt[input] << '\n'; //답 출력
    }
}
