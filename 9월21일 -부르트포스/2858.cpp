#include <iostream>
#include <vector>

#define MAX 500001
using namespace std;



int main() {
 
    //백준 2858번
    int l, w; //lXw
    int r, b;//r:빨간색 갯수 b:갈색 갯수

    cin >> r >> b;

    //가장자리는 빨간색,나머지는 갈색
 
    //nxm일때 빨간색갯수는 2*(n-2)+2*m=2*(n+m-2)
    //갈색 갯수는 n*m-(빨간색 갯수)
    //빨간색 +갈색 =n*m
   //방 크기
    int area = r + b;
    int max = 0;
    for (int i = 1; i < area / 2; i++) {
        if (area % i == 0 ) {
            int tmp1 = i;
            int tmp2 = area / i;

            if (2 * (tmp1 + tmp2 - 2) == r && area - r == b) {
                max = i;
            }
          
        }
                
       
    }
    cout <<max << ' ' << area / max;
    

    return 0;
}
