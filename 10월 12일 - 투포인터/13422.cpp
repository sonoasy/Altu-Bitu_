#include <iostream>
#include <vector>

using namespace std;

int steal(vector<int>& house, int n, int m, int k) {
    //윈도우 초기화
    int money = 0; //money 초깃값 
    for (int i = 0; i < m; i++)//m개의 
        money += house[i]; //돈 합계 

    if (n == m) //훔칠 수 있는 경우 딱 1개인 경우
        return money < k; //결과에 따라 리턴

    int ans = 0; //답 저장
    int left = 0, right = m - 1;
    do { //원형태로 윈도우를 옮겨야 하기 때문에 종료조건은 left가 초기값(=0)이 됐을 때
        if (money < k) //훔칠 수 있음
            ans++; //ans +1 

        money -= house[left]; //왼쪽 값 빼기

        //윈도우의 양 끝 이동
        left = (left + 1) % n; //한칸 이동
        right = (right + 1) % n;//한칸 이동 

        money += house[right]; //오른쪽 값 더하기
    } while (left); //left가 존재할때까지 계속하기 
    return ans; //ans 리턴 
}

/**
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 */
int main() {
    int t, n, m, k; //t개의 테스트 데이터, 집의갯수 n, 도둑이 훔칠 연속된 집의 갯수 m, 최소 돈의 양 k

    cin >> t; //t 입력 
    while (t--) { //t개의 테스트 데이터
        //입력
        cin >> n >> m >> k;
        vector<int> house(n, 0); //house 벡터에 
        for (int i = 0; i < n; i++) //n개의 
            cin >> house[i]; //각 집의 돈 정보 입력

        //연산 & 출력
        cout << steal(house, n, m, k) << '\n';
    }
}
