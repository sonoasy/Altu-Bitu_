#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//삼각형이 될때 세변의 길이릐 합의 최댓값
int makeTriangle(int n, vector<int>& straw) {
    int ans = -1; //최댓값을 저장하기 위해 변수 설정, 없으면 -1출력하므로 -1로 초기화

    //내림차순으로 끝에서 3번째까지 탐색 
    for (int i = 0; i < n - 2; i++) {
        //내림차순이므로 맨 앞이 길이가 가장 큼
        if (straw[i] < straw[i + 1] + straw[i + 2]) { //삼각형이라면
            ans = straw[i] + straw[i + 1] + straw[i + 2]; //제일 처음에 삼각형 되는게 최댓값임 
            break;
        }
    }
    //결과값 리턴
    return ans;
}

/**
 * 세 변의 길이의 합이 최대가 되도록 삼각형을 만드는 문제
 * 주어지는 빨대의 길이를 내림차순 정렬한 후, 길이가 긴 빨대부터 그리디적으로 탐색
 * 현재 빨대 길이를 가장 긴 변의 길이라 가정하고 삼각형이 만들어지는지 확인하면 된다
 */

int main() {
    int n; //빨대 갯수

    //입력
    //빨대갯수
    cin >> n;
    //각 빨대에 대한 길이를 입력받음
    vector<int> straw(n, 0);
    //n개의 빨대에 대하여
    for (int i = 0; i < n; i++)
        cin >> straw[i];//길이를 저장

    //연산
    //내림차순 정렬
    sort(straw.begin(), straw.end(), greater<>());

    //출력
    cout << makeTriangle(n, straw);

    return 0;
}
