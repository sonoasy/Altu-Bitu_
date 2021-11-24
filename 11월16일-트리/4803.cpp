#include <iostream>
#include <vector>

using namespace std;

bool is_tree;
vector<bool> visited;
vector<vector<int>> graph;

void dfs(int node, int parent) {
    if (visited[node]) { //이미 방문한 정점이라면 사이클이 발생한 것
        is_tree = false; //false 
        return;//종료
    }

    visited[node] = true; //방문 처리
    for (int i = 0; i < graph[node].size(); i++) { //그래프 노드 사이즈만큼
        if (graph[node][i] != parent) //부모 정점이 아니라면
            dfs(graph[node][i], node);//dfs
    }
}

void printResult(int num, int cnt) {
    cout << "Case " << num; //케이스 넘버
    if (cnt == 0) //0이면
        cout << ": No trees.\n"; //출력
    else if (cnt == 1)//1이면
        cout << ": There is one tree.\n";//출력
    else //그 외
        cout << ": A forest of " << cnt << " trees.\n";//출력
}

int main() {
    int n, m, a, b, test_case = 0; //변수 

    while (true) {
        test_case++;//테스트 케이스 +1

        //입력
        cin >> n >> m;
        if ((n == 0) && (m == 0)) //종료 조건
            break; //종료 
        visited.assign(n + 1, false);//초기화
        graph.assign(n + 1, vector<int>(0));//그래프 초기화 
        while (m--) { //무방향 그래프
            cin >> a >> b;//a-b
            graph[a].push_back(b);//a-b
            graph[b].push_back(a);//b-a
        }

        //연산
        int tree_cnt = 0;
        for (int i = 1; i <= n; i++) {//n개에 대하여
            if (visited[i]) //이미 방문한 정점
                continue;//다음 차례로 
            is_tree = true; //트리인지 확인
            dfs(i, -1);//dfs
            if (is_tree) //트리가 맞다면
                tree_cnt++;//갯수 +1 
        }

        //출력
        printResult(test_case, tree_cnt);
    }
}
