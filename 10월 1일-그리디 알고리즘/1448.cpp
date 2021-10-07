#include <iostream>
#include<vector>
#include<algorithm>

using namespace  std;


int main() {

	//백준 1448번

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; //빨대의 갯수
	cin >> n;  //n은 3보다 크거나 같고 1000000보다 작거나 같음

	vector<int>straw(n + 1, 0);
	//빨대의 각 길이
	for (int i = 1; i <= n; i++) {
		cin >> straw[i];
	}

	//삼각형을 만들수 없으면 -1 출력, 만들수 있으면 세변의 길이 합 최댓값 출력
	//삼각형 조건: 가장 큰 변 c<a+b 
	//4,5,6,7,20 ->



	
	int sum = 0;
	sort(straw.begin(), straw.end());
	
	int flag = 0;
	int go1 = 0; //삼각형이 되는 3번째 인덱스 체크
	int go2 = 0;
	int go3 = 0;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			for (int k = j + 1; k <= n; k++) {
				//정렬했으므로 k가 가장 큰수
				if (straw[k] < straw[i] + straw[j]) { //삼각형이 되면 최댓값이므로 삼각형 되는 마지막까지 확인
					go1 = i;
					go2 = j;
					go3 = k;
					
				}
				else {
					break;
				}
			}
			
			
		}


	}
	if (go1&&go2&&go3) {
		sum = straw[go1] + straw[go2] + straw[go3];
		
	}


	if (sum== 0) {
		cout << -1;
	}
	else {
		cout << sum;
	}


	

}
