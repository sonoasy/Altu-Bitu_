#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; //첫째 문자열 길이,둘째 문자열 길이 
//상, 좌, 좌상향
int dr[3] = { -1, 0, -1 }; //행
int dc[3] = { 0, -1, -1 };//열

//역추적
string back(string str1, vector<vector<int>>& path) {
    string result = ""; //결과값 저장
    int r = n, c = m; //행,열
    while (path[r][c] != -1) { //-1되기 전까지 계속
        int d = path[r][c]; //방향
        if (d == 2) //좌상향에서 가져온 경우 -> str1[r - 1] == str2[c - 1]
            result += str1[r - 1];//값저장하기
        r += dr[d]; //역추적
        c += dc[d]; //역추적
    }
    reverse(result.begin(), result.end()); //거꾸로 뒤집기 
    return result; //결과 출력
}

//LCS 길이 구하는 함수
int lcs(string str1, string str2, vector<vector<int>>& path) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) { //첫째 문자열 길이에 대해서 탐색
        for (int j = 1; j <= m; j++) {//둘째 문자열 길이에 대해서 탐색
            if (str1[i - 1] != str2[j - 1]) { //두 문자가 서로 다르면
                dp[i][j] = dp[i - 1][j]; //우선 위쪽 값 가져온 것으로 저장
                path[i][j] = 0; //경로(방향) 저장
                if (dp[i][j] < dp[i][j - 1]) { //왼쪽이 더 크다면
                    dp[i][j] = dp[i][j - 1];//더 큰거로 지정
                    path[i][j] = 1; //경로(방향) 저장
                }
            }
            else if (str1[i - 1] == str2[j - 1]) { //두 문자가 서로 같다면
                dp[i][j] = dp[i - 1][j - 1] + 1; //+1
                path[i][j] = 2; //경로(방향) 저장
            }
        }
    }
    return dp[n][m]; //LCS 길이 리턴
}

/**
 * 기본 문제: LCS (해당 풀이는 "08. 동적계획법.pdf" 참고)
 *
 * [역추적]
 * - 위쪽, 왼쪽, 좌상향 중 어느 방향에서 왔는지 경로를 저장한 후, 역추적하는 문제
 * - 경로 저장은 dp배열이 갱신될 때 함
 *
 * 해당 풀이는 인덱스를 편하게 관리하기 위해 dp와 path 배열을 (1, 1)부터 시작
 */

int main() {

    //백준 9252
    string str1, str2; //두 문자열 입력

    //입력
    cin >> str1 >> str2;
    n = str1.length(); //첫번째 문자열의 길이
    m = str2.length(); //두번째 문자열의 길이
    vector<vector<int>> path(n + 1, vector<int>(m + 1, -1)); //그 전 방향 저장

    //연산
    int ans = lcs(str1, str2, path); //lcs
    string result = back(str1, path); //역추적

    //출력
    cout << ans << '\n' << result << '\n';
    return 0; //종료
}
