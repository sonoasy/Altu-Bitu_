#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) {
    vector<int> result; //결과 저장 벡터
    queue<int> q; //큐

    for (int i = 1; i <= n; i++) { //n명에 대해서 탐색
        if (!indegree[i]) //진입차수가 0이라면
            q.push(i); //큐에 넣기
    }
    while (!q.empty()) { //큐에 아무도 없을때까지 
        int node = q.front(); //맨앞 큐 학생 정보
        q.pop();//큐에서 꺼내기

        result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) {//현재 번호 학생과 연결된 학생 탐색
            int next_node = graph[node][i]; //연결된 어떤 학생 번호 
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node); //큐에 넣기
        }
    }
    return result; //result 반환
}

int main() {
    int n, m, a, b; //n명, 키 비교 횟수 m, 학생 a-b

    //입력
    cin >> n >> m;
    vector<int> indegree(n + 1, 0); //각 정점의 진입차수
    vector<vector<int>> graph(n + 1, vector<int>(0)); //인접 리스트 그래프
    while (m--) { //m번 입력
        cin >> a >> b; //a < b
        indegree[b]++; //b의 인접차수 +1
        graph[a].push_back(b); //a-b연결 기록
    }

    //연산
    vector<int> result = topologicalSort(n, indegree, graph);

    //출력
    for (int i = 0; i < n; i++)
        cout << result[i] << ' '; //결과 출력

    return 0; //출력
}
