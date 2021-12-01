#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //node 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);//xp,
    int yp = findParent(y);//yp에 대해서 탐색

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return;//종료
    if (parent[xp] > parent[yp]) //새로운 루트 xp
        parent[yp] = xp;//갱신
    else //새로운 루트 yp
        parent[xp] = yp;//갱신
}

int friendshipCost(int n) {//친구비 계산
    int sum = 0;//0부터 시작
    for (int i = 1; i <= n; i++) {//n개에 대하여
        if (parent[i] < 0) //루트 정점이라면
            sum += -parent[i];//갱신
    }
    return sum;//총합 리턴
}

int main() {
    int n, m, k, v, w, cost;//변수 

    //입력
    cin >> n >> m >> k;
    parent.assign(n + 1, 0); //초기화
    for (int i = 1; i <= n; i++) { //n개의
        cin >> cost;//cost 입력
        parent[i] = -cost; //루트 정점에 필요한 친구비(음수)를 저장
    }

    //연산
    while (m--) {
        cin >> v >> w;//서로 친구인 v,w
        unionInput(v, w);//연산
    }

    int ans = friendshipCost(n); //연산

    //출력
    if (ans <= k) //가지고 있는 돈 내이면
        cout << ans; //답 출력
    else // 그외 
        cout << "Oh no"; //안됨
}
