#include <iostream>
#include <vector>

using namespace std;

void floydWarshall(int n, vector<vector<bool>>& graph) { //사건의 갯수,graph 벡터
    for (int k = 1; k <= n; k++) {//중간 k
        for (int i = 1; i <= n; i++) { //i-j에서 i
            for (int j = 1; j <= n; j++) {//j 
                if (graph[i][k] && graph[k][j]) //i->k, k->j 전후관계 있는 경우
                    graph[i][j] = true; //전후관계 성립
            }
        }
    }
}

int main() {

    //백준 1613번
    ios::sync_with_stdio(false); //속도향상
    cin.tie(NULL); //속도향상

    int n, k, s, a, b; //사건의 갯수 n, 사건 전후 관계의 갯수 k,알고 싶은 쌍의 갯수 s,두 사건 a,b

    //입력
    cin >> n >> k; //사건의 갯수, 사건 전후 관계 갯수 입력
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false)); //graph에 저장
    while (k--) { //모든 전후 관계 입력
        cin >> a >> b; //전-후 a-b
        graph[a][b] = true; //전후관계 -> 단방향 그래프
    }

    //연산
    floydWarshall(n, graph); //플로이드-워셜

    //입력 & 출력
    cin >> s; //알고 싶은 쌍의 갯수
    while (s--) { //모두 계산
        cin >> a >> b; // 입력
        if (graph[a][b]) //전-후관계면
            cout << "-1";//-1 출력
        else if (graph[b][a])//후-전 관계면
            cout << "1"; //1 출력
        else //그 외에
            cout << "0"; //0출력
        cout << '\n'; //띄어쓰기
    }
    return 0; //종료
}
