#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) {
    vector<int> result; //결과 벡터 
    queue<int> q; //큐

    for (int i = 1; i <= n; i++) { //n개에 대하여 
        if (!indegree[i]) //진입차수가 0이라면
            q.push(i); //큐에 넣기 
    }

    while (!q.empty()) {//큐가 빌때까지 
        int node = q.front(); //맨앞 큐의 정보
        q.pop();//큐에서 꺼내기

        result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) { //연결된 모든 가수 정보에 대하여 
            int next_node = graph[node][i]; //다음 가수 정보 
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node); //큐에 넣기 
        }
    }
    return result; //결과 리턴
}

/**
 * 기본적인 위상 정렬 문제
 * 현재 가수와 바로 전 가수 사이의 선후관계를 정의
 * 순서를 정하는 것이 불가능한 경우(위상정렬을 할 수 없는 경우)는 모든 정점을 탐색하지 못한 경우
 */

int main() {
    int n, m, cnt, prev, cur; //가수의 수 n, 보조 pd 수 m, 담당 가수 수 cnt, 가수 정보 prev,cur

    //입력
    cin >> n >> m;
    vector<int> indegree(n + 1, 0); //진입차수 벡터
    vector<vector<int>> graph(n + 1, vector<int>(0)); //선후관계 연결 정보
    while (m--) { //m개 입력
        cin >> cnt; //담당 가수의 수
        cin >> prev; //처음 가수 입력
        while (--cnt) { //선후관계 정의
            cin >> cur; //연결되는 다음 가수
            indegree[cur]++; //진입차수 +1 
            graph[prev].push_back(cur); //연결정보 반영
            prev = cur; //지금 가수 정보를 prev로 변경하여 계속 
        }
    }

    //연산
    vector<int> result = topologicalSort(n, indegree, graph);

    //출력
    if (result.size() != n) { //순서를 정하는 것이 불가한 경우
        cout << "0\n"; //0출력
        return 0; //종료 
    }
    for (int i = 0; i < result.size(); i++) //결과
        cout << result[i] << '\n'; //출력
}
