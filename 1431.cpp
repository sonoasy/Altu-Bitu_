#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool cmp(const string a, string b) {

	if (a.size() != b.size()) {
		return a.size() < b.size();
	}


	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < a.size(); i++) {
			if (a[i] <='9' && a[i] >'0') {
				sum1 +=  a[i]-'0';
			}
	}
	for (int i = 0; i < b.size(); i++) {
			if (b[i] <= '9' && b[i] > '0') {
				sum2 += b[i] - '0';
			}
	}
	if (sum1 != sum2) {
			return sum1 < sum2;
			
	}

	return a < b;
	
}

string s;
vector<string> v;
int main() {
	//백준 1431번
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	//짧은게 먼저, 같으면 문자 내 숫자 합이 작은거, 사전순
	//길이가 짧은 순으로 정렬
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout <<v[i]<<'\n' ;
	}
}
