#include <iostream>
#include <vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#define MAX 500001
using namespace std;

vector<int> num;
int arr[8002] = { 0 };

//산술 평균 구하기
double avg(int n, vector<int> v) {
    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return round(sum / n);

}



//중앙값 출력하기
int mid(int n, vector<int>v) {
    //n은 홀수라고 가정하므로 n/2번째를 탐색하면됨
   
    return v[n/2];
}



//최빈값 
int freqs(int n, vector<int>v) {
   //입력되는 정수의 절댓값은 4000을 넘지 않음
   //-4000부터 4000까지 값에 해당되면 +1 하기
     //0     1     3999 4000 4001       8000    arr 인덱스  
    //-4000,-3999,..-1,  0, 1 ,...3999,4000     매칭되는 숫자

    for (int i = 0; i < v.size(); i++) {
        //s는 숫자
        int s = v[i];
        arr[s+4000]++;
    }

    int max = 0;
    int maxi;
    //arr에서 최빈값을 구하기
    for (int i = 0; i < 8002; i++) {
        if (max <= arr[i]) { //여러개일수 있으므로 같거나 큰 값을 탐색
            max = arr[i];
            //마지막 최빈값 인덱스
            maxi = i;
        }
    }
    
    //최빈값에 해당되는게 여러개인지 확인하기
    int flags = 0;
    for (int i = 0; i < 8002; i++) {
        //max값인데 maxi와 인덱스가 다르다면 여러개
        if (arr[i] == max && i != maxi) {
            flags = 1;
            break;
        }

    }
    //여러개일때
    if (flags == 1) {
        // 이미 숫자는 오름차순이므로 maxi 보다 작은 숫자들 중 두번쨰로 작은 숫자를 출력
        int count = 0;
        for (int i = 0; i < maxi; i++) {
            if (arr[i] == max) {
                count++;
            }
            
            if (count == 2) {
                //실제 숫자
                return i-4000;
            }
        }


    }
   
    return maxi-4000;
   


}


//범위 출력
int range(int n, vector<int>v) {

    return v[v.size() - 1] - v[0];
}


int main() {

    //백준 2108번
    int n, m;
    double sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        sum += m;
        num.push_back(m);
    }
    //산술평균 반올림하여 출력하기
    cout << avg(n,num) << '\n';


    //중앙값 계산부터는 정렬된 벡터를 사용
    sort(num.begin(), num.end());


    //중앙값 출력하기
    cout << mid(n,num) << '\n';
    //최빈값
    cout << freqs(n, num) << '\n';
  
    //범위 출력하기
    cout << range(n,num) << '\n';



    return 0;
}
