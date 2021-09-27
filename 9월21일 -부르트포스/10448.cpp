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

    //n 삼각수 설정하기
    int tri[1001];
    for (int i = 1; i <= 1000; i++) {
        tri[i] = i * (i + 1) / 2;
    }

    while (n--) {
        int m;
        cin >> m;

        
        int sum = 0;
        int flag = 0;
        //시간초과 방지 
        double s = sqrt(2 * m);
        //숫자가 다를 필요없음!!
        for (int i = 1; i < s; i++) {
            for (int j = 1; j < s; j++) {
                for (int k = 1; k < s; k++) {
                    sum = 0;
                    sum += tri[i] + tri[j] + tri[k];
                    //세 삼각수 합이 입력값과 같으면 flag 1 표기
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
            //flag가 1일떄만 1 출력
            cout << 1 << '\n';
        }

    }


    return 0;
}
