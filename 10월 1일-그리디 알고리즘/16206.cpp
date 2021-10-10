#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//롤케이크 길이를 정렬하는 기준
//10으로 나누어 떨어지는게 먼저,나누어 떨어지는것 중에서도 길이가 짧은게 더 먼저
bool cmp(const int& a, const int& b) {
    if (a % 10 == 0 && b % 10 == 0) //둘 다 나누어 떨어지면 짧은 것부터
        return a < b;

    return a % 10 == 0; //나누어떨어지는 게 먼저 오도록 정렬
}

//롤케이크 자르는 함수
int cutCakeRoll(int n, int m, vector<int>& cake) {
    //결과 
    int ans = 0;

    //모든 롤케이크에 대하여 
    for (int i = 0; i < n; i++) {
        int cut = cake[i] / 10; //자르는 횟수 (10으로 나누어 안떨지는 23같은 수는 자르는 횟수 여기서 변동 없음)
        if (cake[i] % 10 == 0) //케이크가 10으로 나누어 떨어지면
            cut--;  // 나누어 떨어지는 수보다 1씩 적게 자르면 됨
        if (cut <= m) { //자를수 있는 최대 횟수 m에 대하여 
            m -= cut;   //cut이 되는 수만큼 m에서 제해주기
            ans += cake[i] / 10;  //자른 후 길이가 10인 케이크 갯수 더해주기 
        }
        else { //다 못자르는 경우 -> 한 번 자를 때 1개씩 나오므로 m 더함
            ans += m;   //자르는 횟수가 m보다 큰 숫자였으면 m을 더해주기
            break; //m을 모두 썼으므로 연산 종료
        }
    }
    //결과 리턴
    return ans;
}

/**
 * 길이가 10인 롤케이크 개수의 최댓값을 구하는 문제
 * 길이가 10이상인 롤케이크를 잘라보자. 기본적으로 한 번 자르면 1개씩 나오게 된다.
 * 이때, 10으로 나누어 떨어지는 길이를 먼저 잘라야 한다. (ex. 15를 한 번 자르면 1개가 생기지만, 20을 한 번 자르면 2개가 생김)
 * 10으로 나누어 떨어지는 길이 중에서도, 작은 길이를 먼저 잘라야 한다. (ex. 20을 한 번 자르면 2개가 생기지만, 30을 한 번 자르면 1개가 생김)
 * 10으로 나누어 떨어지지 않는 다른 수끼리는 순서가 상관 없다.
 */

int main() {
    //롤케이크 갯수, 자를수 있는 최대 횟수
    int n, m;

    //입력
    cin >> n >> m;
    //n개의 롤케이크 각 길이
    vector<int> cake(n, 0);
    //n개의 롤케이크에 대한
    for (int i = 0; i < n; i++)
        cin >> cake[i]; //길이 저장

    //연산
    //케이크 cmp 기준으로 정렬
    sort(cake.begin(), cake.end(), cmp);

    //연산 & 출력
    //결과값 출력 
    cout << cutCakeRoll(n, m, cake) << '\n';

    return 0;
}
