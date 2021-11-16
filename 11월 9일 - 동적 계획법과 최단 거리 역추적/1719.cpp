#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //최대 n-1개의 간선을 지나게 됨

void floydWarshall(int n, vector<vector<int>>& graph, vector<vector<int>>& table) { //플로이드-워셜
    for (int k = 1; k <= n; k++) {//중간 n개
        for (int i = 1; i <= n; i++) { //n개의
            for (int j = 1; j <= n; j++) {//n개에 대하여
                int new_dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                if (new_dist < graph[i][j]) { //i->k->j가 i->j보다 빠른 경로라면
                    graph[i][j] = new_dist;//갱신하기 
                    table[i][j] = table[i][k];//경로 갱신
                }
            }
        }
    }
}

/**
 * graph : 플로이드-워셜 결과 행렬 그래프
 * table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
 *    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
 *    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
 *    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
 *    line 16을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
 */
int main() {

    //백준 1719번
    int n, m, s, d, c;//n:집하장의 갯수, m:집하장간 경로 갯수, 집하장 번호s,d, 필요한 시간 c

    //입력
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); //그래프 벡터 
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0)); //경로 벡터 
    for (int i = 1; i <= n; i++) //자기 자신으로의 그래프는 
        graph[i][i] = 0; //0으로 초기화 

    while (m--) { //무방향 그래프
        cin >> s >> d >> c;//입력
        //간선 정보
        graph[s][d] = graph[d][s] = c;

        //경로 정보
        table[s][d] = d; 
        table[d][s] = s;//양쪽 모두  지정
    }

    //연산
    floydWarshall(n, graph, table);

    //출력
    for (int i = 1; i <= n; i++) {//모든
        for (int j = 1; j <= n; j++) {//nxn 에 대하여 출력
            if (i == j) //자기 자신으로 가는데면
                cout << "- "; //-로 출력
            else //그 외에는
                cout << table[i][j] << ' '; //경로 벡터값 출력
        }
        cout << '\n'; //띄어쓰기 
    }
}
