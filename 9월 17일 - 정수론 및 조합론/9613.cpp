#include <iostream>
#include <vector>
#include<queue>
//백준 9613번

using namespace std;

//유클리드 호제법
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}



int main() {
   
    int n;
    cin >> n;
    while (n--) {
        int m,e;
        cin >> m;
        vector<int>a;
        vector<int>a2;
        //m개의 숫자중 모든 쌍의 가능한 gcd 값 구하기
        for (int i = 0; i < m; i++) {
            cin >> e;
            a.push_back(e);

        }
        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < m; j++) {
                int s1 = max(a[i], a[j]);
                int s2= min(a[i], a[j]);
                int res = gcd(s1, s2);
                a2.push_back(res);
            }
        }
        long long sum = 0;
        for (int i = 0; i < a2.size();i++) {
            sum += a2[i];
        }
        cout << sum << '\n';

    }


}
