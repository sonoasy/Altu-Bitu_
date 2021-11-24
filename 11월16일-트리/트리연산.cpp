#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//트리의 정점 수
int nodeCnt(int node) {
    int cnt = 1;//초기 값
    for (int i = 0; i < tree[node].size(); i++) //트리 노드 개수만큼 탐색
        cnt += nodeCnt(tree[node][i]); //갯수 +1
    return cnt; //갯수 출력
}

//리프 노드의 수
int leafCnt(int node) { 
    if (tree[node].empty()) //비어있으면
        return 1; //1리턴
     
    int cnt = 0; //갯수 세기
    for (int i = 0; i < tree[node].size(); i++)//트리 노드 갯수 만큼
        cnt += leafCnt(tree[node][i]); //카운트
    return cnt; //갯수 리턴
}

//트리의 높이
int treeHeight(int node) {
    int height = 0; //초기값 0
    for (int i = 0; i < tree[node].size(); i++) //트리 노드 갯수만큼
        height = max(height, treeHeight(tree[node][i])); //가장 큰 높이에 
    return height + 1;//+1 리턴
}

int main() {
    //입력
    tree.assign(6, vector<int>(0));
    tree[1] = { 2, 3, 4 };  //트리 정보 입력
    tree[4] = { 5 }; //트리 정보 입력

    //연산 & 출력
    cout << "[Tree info]\n"; //트리 정보
    cout << "Nodes : " << nodeCnt(1) << '\n'; //노드 갯수
    cout << "Leaf Nodes : " << leafCnt(1) << '\n'; //리프 노드
    cout << "Height : " << treeHeight(1) << '\n'; //트리 높이 
}
