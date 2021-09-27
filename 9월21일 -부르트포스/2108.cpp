#include <iostream>
#include <vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#define MAX 500001
using namespace std;

vector<int> num;
map<int, int>freq;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
 
    //백준 2108번
    int n,m;
    double sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        sum += m;
        freq[m]++;
        num.push_back(m);
    }
    //산술평균 반올림
    cout << round(sum / n)<<'\n';

    //중앙값
    sort(num.begin(), num.end());
    int s;
    if (n % 2 == 0) {
        s = n / 2;
    }
    else {
        s = n / 2 + 1;
    }

    cout << num[s - 1] << '\n';

    //최빈값 여러개 있을떄는 두번쨰로 작은 값
    //빈도수에 맞춰 오름차순 정렬하기
    vector<pair<int, int>> vec(freq.begin(), freq.end());
    sort(vec.begin(), vec.end(), cmp);

    //여러개 있을때 
    int max = vec[vec.size() - 1].second;
    int flag = 0;
    vector<int>check;
    for (int i = 0; i < vec.size()-1; i++) {
        if (vec[i].second == max) {
            flag = 1;
            check.push_back(vec[i].first);
        }

    }
    check.push_back(vec[vec.size() - 1].first);
    if (flag == 1) {
        sort(check.begin(), check.end());
        cout << check[1] << '\n';

    }
    else {
        cout << vec[vec.size() - 1].first << '\n';
    }
   

    //범위
    cout << num[n - 1] - num[0] << '\n';




    return 0;
}
