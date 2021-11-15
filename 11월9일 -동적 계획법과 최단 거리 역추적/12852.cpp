#include <iostream>
#include <vector>

using namespace std;

vector<int> back(int x, vector<int>& path) {
    vector<int> result(0); //Lis의 마지막 원소 인덱스부터 들어감
    while (x != -1) {
        result.push_back(x);
        x = path[x]; //다음 경로
    }
    return result;
}

int main() {
    //백준 12852번

    int n;
   
    cin >> n;
    vector<int> path(n, -1); //경로 배열
    int cnt = 0;//연산의 횟수 

    //n을 1로 만드는 방법에 포함되어 있는 수를 출력하기
    //연산의 종류: 3으로 나누어 떨어지면 3으로 나눔, 2로 나누어 떨어지면 2로 나눔, -1 

    //연산을 하는 최소 횟수 
    
    path[cnt] = n;
    while (n != 1) {

        if (n == 1)break;
        if (cnt == n)break;
        int tmp;
        tmp = n - 1;
        cnt++;
        path[cnt] = tmp;
        n = tmp;

        if (n % 2 == 0) {
            tmp /= 2;
            cnt++;
            path[cnt] = tmp;
            n = tmp;
           
        }

        if (n % 3 == 0) {
            tmp /= 3;
            cnt++;
            path[cnt] = tmp;
            n = tmp;
        }
       

    }
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }
    //vector<int> result = back(cnt, path);
   // for (int i = result.size() - 1; i >= 0; i--)
    //    cout << result[i] << ' ';








}
