#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; //parent 벡터

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //루트 정점
        return node;//node 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x);//xp,
    int yp = findParent(y);//yp에 대하여

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false;//false 리턴
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];//갱신
        parent[yp] = xp;//갱신
    }
    else { //새로운 루트 yp
        parent[yp] += parent[xp];//갱신
        parent[xp] = yp;//갱신
    }
    return true;//유니온 할수 있으면 true 리턴
}

/**
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */
int main() {
    int n, m, x, y;//n개의 점,m개 선택, 두점 번호 x,y

    //입력
    cin >> n >> m;
    parent.assign(n, -1);//초기화 -1
    for (int i = 0; i < m; i++) {//m개에 대하여
        cin >> x >> y;//두 점 번호 x,y

        //연산 & 출력
        if (!unionInput(x, y)) { //유니온 할 수 없음 = 사이클이 생성됨
            cout << i + 1; //사이클 처음 만들어진 차례의 번호를 양의 정수로 출력
            return 0;//종료
        }
    }
    cout << 0;//종료 안되었으면 0출력
}
