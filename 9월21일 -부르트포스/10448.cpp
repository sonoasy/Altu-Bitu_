#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
 
    //백준 10448번
    //삼각수는 n*(n+1)/2 
    //3개의 삼각수로 표현이 되는지 확인
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;

        //시간초과
        int sum = 0;
        int flag = 0;

        double s = sqrt(2 * m);
        //숫자가 다를 필요없음!!
        for (int i = 1; i < s; i++) {
            for (int j = 1; j < s; j++) {
                for (int k = 1; k < s; k++) {
                    sum = 0;
                    sum += (i * (i + 1) / 2) + (j * (j + 1) / 2) +( k * (k + 1) / 2);
                    if (sum == m) {
                        flag = 1;
                        
                        break;
                    }


                }
            }
        }
        if (flag == 0) {
            cout << 0 << '\n';
        }
        else {
            cout << 1 << '\n';
        }

    }

   







  
    return 0;
}
