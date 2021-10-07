#include <iostream>
#include<vector>
#include<algorithm>

using namespace  std;


int main() {

	//백준 16206번

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; //롤케이크 갯수, 자를수 있는 최대 횟수
	cin >> n >> m;
	vector<int>cake(n + 1, 0);
	//n개의 각각 롤케이크 길이
	for (int i = 1; i <= n; i++) {
		cin >> cake[i];
	}
	//길이가 10인 케이크만 먹음
	//10보다 큰 수만 자름, 어떤것 먼저?-> 한번 잘랐을때 10보다 큰수
	int tmp;
	int ans = 0;
	sort(cake.begin(), cake.end());
	for (int i = 1; i <= n; i++) {
		if (cake[i] == 10) {
			ans++;
			continue;
		}
		else if (cake[i] > 10) {
			while (cake[i] > 10&&m>0) {
				m--;//한번 자름
				ans++;
				cake[i] -= 10; 
			}
			if (cake[i] == 10) {
				ans++;
			}
			
		}


	}



	//길이가 10인 갯수
	cout << ans;


}
