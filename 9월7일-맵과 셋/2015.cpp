#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;



int main() {
	//백준 2015번
          
	//숫자 저장 arr
	int arr[200001] = { 0 };
	//어떤 합이 되는 갯수 현황 map
	map<int, long long> m;
	
	int n, k;
	cin >> n >> k;

	//부분합이 k가되는 갯수 구하기 

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

	}

	//누적합 구하기
	for (int i = 1; i <= n; i++) {
		arr[i] += arr[i - 1];

	}

	long long answer = 0;
	for (int i = 1; i <= n; i++) {

		//i까지 누적합이 k면 바로 추가  - 누적합이 k가 되는 경우
		if (arr[i] == k) {

			answer++;
		}


		//부분합은 i-j 까지 A[j]-A[i-1]= k 가되는거
		//만약 어떤곳에서 +k 해서 i가 되는게 이미 map되어있으면 그 갯수 추가해주기 - 부분합이 k가 되는 경우
		if (m[arr[i] - k] > 0) {
			answer += m[arr[i] - k];

		}
		//누적합 저장, 마지막에 추가해야함 k가 0이면 두번 체크할수 있음
		m[arr[i]]++;


	}

	cout << answer;


}
