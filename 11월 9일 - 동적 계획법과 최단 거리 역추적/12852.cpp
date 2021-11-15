#include <iostream>
#include <vector>

using namespace std;

//https://guiyum.tistory.com/12  n을 1로 만드는 dp의 점화식을 세우는것이 어렵게 여겨져서 역추적이 제외된 1463번의 블로그 풀이를 참고하여 학습하여 먼저 풀었습니다. 


void back(int x, vector<int>& path) {
   
    while (x != -1) {
        cout << x<<' ';
        x = path[x]; //다음 경로
    }
    
}

int main() {
    //백준 12852번

    int n;

    cin >> n;

    //연산의 종류: 3으로 나누거나, 2로 나누거나, -1
    vector<int>dp(n + 1, 0); //d[n]은 n이 1이되는 최소의 연산 횟수 
    vector<int>path(n + 1, -1); //path[a]=b 는 b->a로 숫자가 바뀌는것임

    dp[1] = 0; //1은 마지막 숫자 
    for (int i = 2; i <= n; i++) { //n=1,2,3...n일때
        dp[i] = dp[i-1] + 1; //이전 숫자에서 +1되서 되는 값 
        path[i] = i - 1; //역추적이니까 i가 되기전의 값은 i-1 

        if (i % 3 == 0 && dp[i]>dp[i / 3] + 1) { //n=i일때 3으로 나누어 떨어지면 3으로 나눈 값에서 +1 되는데 원래 dp[i]이 같거나 더 작으면 그값으로 설정
            //dp[i] = dp[i] < dp[i / 3]+1?dp[i]:dp[i / 3]+1;
            dp[i] = dp[i / 3] + 1;
            path[i] = i / 3;//역추적이니까 i가 되기전의 값은 i/3 ,패스의 갱신은 dp[i/3]으로 바뀔떄만 설정해줘야함!!!
        }
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) { //n=2일때도 동일한 방식 
            dp[i] = dp[i / 2] + 1;
            path[i] = i / 2;//역추적이니까 i가 되기전의 값은 i/2
        }


    }
    cout << dp[n]<<'\n'; //최소 연산횟수 출력
    back(n, path); //n->1이 되는 과정 출력





}
