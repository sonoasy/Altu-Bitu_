#include <iostream>
#include <vector>

using namespace std;

vector<bool> cycle; //사이클 벡터
vector<int> parent; //parent 벡터

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //node 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);//xp
    int yp = findParent(y);//yp에 대하여 

    if (xp == yp) { //같은 집합에 있다면 유니온 할 수 없음
        cycle[xp] = true; //사이클 true로 설정
        return;//종ㄽ
    }
    if (cycle[xp] || cycle[yp]) //둘 중 하나라도 사이클이 있으면 표시
        cycle[xp] = cycle[yp] = true;
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];//갱신
        parent[yp] = xp;//갱신
    }
    else { //새로운 루트 yp
        parent[yp] += parent[xp];//갱신
        parent[xp] = yp;//갱신
    }
}

int cntTree(int n) { //트리 갯수 세기
    int cnt = 0; //0에서 시작
    for (int i = 1; i <= n; i++) { //n개에 대하여 
        if (parent[i] < 0 && !cycle[i]) //루트 정점인데 사이클도 없을 때
            cnt++;//+1
    }
    return cnt;//cnt 리턴
}

void printResult(int num, int cnt) { //결과 출력 함수
    cout << "Case " << num; //케이스 넘버 출력
    if (cnt == 0) //0개면
        cout << ": No trees.\n"; //트리 없음
    else if (cnt == 1) //1개면
        cout << ": There is one tree.\n";//트리 한개
    else // 그외
        cout << ": A forest of " << cnt << " trees.\n"; //트리갯수 출력
}

int main() {
    int n, m, a, b, test_case = 0; //변수

    while (true) { //계속 반복
        test_case++; //테스트 케이스+1

        //입력
        cin >> n >> m;
        if (n == 0 && m == 0) //종료 조건
            break;//종료
        parent.assign(n + 1, -1); //parent 초기화
        cycle.assign(n + 1, false);//사이클 초기화
        while (m--) { //무방향 그래프
            cin >> a >> b; //두 a,b에 대하여
            unionInput(a, b);//탐색
        }

        //연산
        int tree_cnt = cntTree(n);

        //출력
        printResult(test_case, tree_cnt);
    }
}
