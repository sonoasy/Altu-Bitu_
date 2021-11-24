#include <iostream>
#include <map>

using namespace std;

map<char, pair<char, char>> tree; //트리 

//전위 순회
void preorder(char node) {
    if (node == '.')//.이면
        return;//종료
    cout << node;//노드 출력
    preorder(tree[node].first); //왼쪽
    preorder(tree[node].second);//오른쪽
}

//중위 순회
void inorder(char node) {
    if (node == '.')//.이면
        return;//종료
    inorder(tree[node].first);//왼쪽
    cout << node;//노드 출력
    inorder(tree[node].second);//오른쪽
}

//후위 순회
void postorder(char node) {
    if (node == '.')//.이면
        return;//종료
    postorder(tree[node].first);//왼쪽
    postorder(tree[node].second);//오른쪽
    cout << node;//노드 출력
}

int main() {
    int n; //갯수
    char root, left, right; //루트, 왼,오 

    //입력
    cin >> n; 
    while (n--) { //n개 입력
        cin >> root >> left >> right;//입력
        tree[root] = make_pair(left, right); //트리 생성
    }

    //연산 & 출력
    preorder('A'); //전위 순회
    cout << '\n'; //띄어쓰기 

    inorder('A');//중위 순회
    cout << '\n';//띄어쓰기 

    postorder('A');//후위 순회
    cout << '\n';//띄어쓰기 
}
