#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int res = -1;
int check[11] = { 0 };
vector<int>energy(11, 0);
void go(vector<int> v,int s) {
    
    if (v.size() == 2) { //두개가 남으면 더이상 선택할수 없음
        if (res < s) {
            res = s;
        }
        return;
    }
    //2부터 v.size()-2까지 선택 가능
    for (int i = 2; i <= v.size() - 2; i++) {
        //에너지값도 초기화해줘야함
        int tmp = s;
        tmp += v[i - 1] * v[i + 1];
        //energy가 변동되면 안됨!!!!
        vector<int>q = v;
        q.erase(q.begin() + i); //1 2 4
        //for (int i = 0; i < q.size(); i++) {
       //    cout << q[i] << ' ';
       // }
        go(q, tmp);
        
    }



}


int main() {
   
    //백준 16198번

    int n;
    cin >> n;
    
    
    //i번째 구슬의 무게:energy[i]
    for (int i = 1; i <= n; i++) {
        cin >> energy[i];
    }

    //에너지를 모으는 방법 
    //에너지 x번째 구슬을 하나 고른다.(1,n번째 제외) 고른 구슬 제거
    // energy[x-1]*energy[x+1] 에너지 모음
    // n 제거 후 구슬 1부터 번호 다시 매김 

    //1 2 3 4     -> 1 2 4
    // 3 제거 ->8 , 2 제거 -> 4 = 12
    //줄어든 벡터 어떻게 처리 -> erase 사용
    int w = 0; //에너지 초기값
   
    go(energy,w);
    


    cout << res;



    return 0;
}
