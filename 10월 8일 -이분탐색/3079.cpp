#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

vector<long long>v;
int main() {
         //이번 17회 이퍼 대비 문제로 프로그래머스의 해당 문제 풀이가 있었는데, 그때 풀이를 떠올리면서 풀었습니다!
	//백준 3079번

	long long n, m; //입국 심사대, 친구 m명
	

	cin >> n >> m;
	
	long long a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);  //걸리는 시간
		
	}

	long long ans = LLONG_MAX;
	sort(v.begin(), v.end());

	long long start = 1;
	long long end = m * v[v.size() - 1];  //최대 m명 최대시간으로 곱하기 

	long long mid=0;
	long long sum=0;
	while (start <= end) {

		mid = (start + end) / 2;
		sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum+=mid / v[i];

		}
		
		if (sum >= m) { //m명을 만족하면 
			ans = min(ans,mid); //저장 
			end = mid - 1;
			
		}
		else {
			start = mid + 1;
		}
	}
	cout << ans;



}
