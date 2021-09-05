#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<pair<int, int>>v;


//면접기준 정렬
bool cmp(pair<int, int> a, pair<int, int> b) {

	return a.second > b.second;

}

int main() {
	//백준 1946번
	//숫자는 점수가 아니라 등수임
	ios::sync_with_stdio(false);
	int m;
	cin >> m;
	for (int k = 0; k < m; k++) {

		int n;

		cin >> n;
		vector<pair<int, int>>v;
		for (int i = 0; i < n; i++) {
			int f, s;//서류점수,면접점수
			cin >> f >> s;
			v.push_back({ f,s });

		}

		//숫자가 등수이므로 서류심사 기준 정렬
		sort(v.begin(), v.end());

		int cnt = 0;
		int min =100001;

		//loop 최소화하기
		//이미 서류에선 뒤에사람보다 잘봤으므로 앞에 있는 사람중에 제일 잘본사람보다 잘보면 됨
		for (int i = 0; i < n; i++) { 
			if (min >v[i].second) { //min은 앞에서부터 갱신되서 내려오는 작은 등수
				min = v[i].second; 
				cnt++;
			}
			

		}

		cout << cnt<<'\n';




	}
	
	


}
