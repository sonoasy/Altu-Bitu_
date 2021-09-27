#include <iostream>
#include<vector>
using namespace std;

vector<int> c;
int main() {
 
    //백준 1107번
    //+누르면 +1 -누르면 -1

    int n; //이동하려는 채널 현재채널은 100
    cin >> n;
    int m; //고장난 버튼
    int s;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        c.push_back(s);
    }
    int min = 100000000;
    for (int i = 100; i < 500000; i++) {
        //시작점에 고장난 숫자 없으면 이동 가능함
        int flag = 0;
        int count = 0;
        while (i % 10 > 0) {
            //각각 자릿수에 대해 실행
            //고장난 숫자 목록에서 
            int k = i % 10;
            for (int e = 0; e < c.size(); e++) {
                if (k == c[e]) { //고장난 숫자 있으면 이동 안됨
                    flag = 1;
                    break;
                }
              
            }
            if (flag == 0) {
                count++;
            }
            i = i / 10;
        }
        //탐색했을때 모든 자릿수가 고장나지 않았을때만 count 계산 
        if (flag == 0 ) {
            //차이만큼 움직이기 
            count += abs(n - i);

        }
        else {
            continue;
        }
        if (min > count) {
            min = count;
        }
    }

    cout << min;


  
    return 0;
}
