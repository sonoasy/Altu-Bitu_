#include <iostream>
#include <vector>

using namespace std;

vector<bool> truth; //진실을 아는지 여부
vector<int> parent; //parent 벡터

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //루트 정점
        return node; //node 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);//xp,
    int yp = findParent(y);//yp에 대하여 탐색

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return;//종료
    if (truth[xp] || truth[yp]) //둘 중 하나라도 진실을 믿는 사람이 있다면 표시
        truth[xp] = truth[yp] = true; //true로 설정
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];//갱신
        parent[yp] = xp;//갱신
    }
    else { //새로운 루트 yp
        parent[yp] += parent[xp];//갱신
        parent[xp] = yp;//갱신
    }
}

int liarParty(vector<int>& parties) {//거짓말 파티
    int cnt = 0;//0부터 시작
    for (int i = 0; i < parties.size(); i++) {//파티 갯수만큼
        int root = findParent(parties[i]); //파티 집합의 루트 정점
        if (!truth[root])//거짓 
            cnt++;//+1
    }
    return cnt;//갯수 출력
}

/**
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */
int main() {
    int n, m;//사람수,파티 수

    //입력
    cin >> n >> m;
    truth.assign(n + 1, false);//초기화 false
    parent.assign(n + 1, -1); //초기화 -1

    int init, p; //변수
    cin >> init;//진실 아는 숫자
    while (init--) { //진실을 아는 사람들
        cin >> p;//번호 입력
        truth[p] = true; //true로 설정
    }

    int cnt, first_person, people;//변수
    vector<int> parties;//파티참여
    while (m--) { //m개 입력
        cin >> cnt >> first_person; //파티에 오는 수, 번호 

        //연산
        parties.push_back(first_person); //파티 정보로 각 파티의 첫번째 사람만 저장
        while (--cnt) { //남은 cnt만큼 
            cin >> people; //번호 입력
            unionInput(first_person, people);//연산
        }
    }

    int ans = liarParty(parties);//연산

    //출력
    cout << ans;
}
