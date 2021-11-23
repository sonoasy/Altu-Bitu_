#include <iostream>
#include <vector>

using namespace std;

//단절점, 단절선 파악 함수
string isTrue(int t, int k, vector<vector<int>>& tree) {
    if (t == 2) //2면
        return "yes"; //yes
    if (tree[k].size() >= 2) //2이상이면
        return "yes";//yes
    return "no";//그외 no
}

/**
 * 부모 노드를 알 수 없기에 트리를 양방향 그래프로 저장
 * 단절점: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 연결된 간선이 2개 이상이면 단절점
 * 단절선: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 모든 간선이 단절선
 */

int main() {
    ios_base::sync_with_stdio(false); //속도 향상
    cin.tie(NULL); //속도 향상
    int n, a, b, q, t, k; //변수

    //입력
    cin >> n;
    vector<vector<int>> tree(n + 1, vector<int>(0)); //트리 벡터
    for (int i = 0; i < n - 1; i++) { //정점 갯수 간 연결
        cin >> a >> b; //a,b 연결
        tree[a].push_back(b); // a-b
        tree[b].push_back(a);//b-a
    }
    cin >> q; //질의
    while (q--) { //질의 갯수만큼 
        cin >> t >> k; //t번째,k번째 간선에 대한 질의 
        cout << isTrue(t, k, tree) << '\n'; //질의
    }
    return 0; //종류
}
