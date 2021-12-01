#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; //parent 벡터 

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);//두 개에 대해 탐색:xp,
    int yp = findParent(y);//yp

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return;//종료
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];//갱신
        parent[yp] = xp;//갱신
    }
    else { //새로운 루트 yp
        parent[yp] += parent[xp];//갱신
        parent[xp] = yp;//갱신
    }
}

int main() {
    ios::sync_with_stdio(false);//속도 향상
    cin.tie(NULL);//속도 향상

    int n, m, cmd, a, b; //변수 

    //입력
    cin >> n >> m;
    parent.assign(n + 1, -1);//집합 초기화
    while (m--) {//연산 갯수 m만큼 
        cin >> cmd >> a >> b;//a,b에 대해 cmd 탐색

        //연산
        if (cmd == 0) { //유니온
            unionInput(a, b);//연산
        }
        if (cmd == 1) { //파인드
            if (findParent(a) == findParent(b))//부모가 같으면
                cout << "YES\n";//yes
            else//그외에는
                cout << "NO\n";//no
        }
    }
}
