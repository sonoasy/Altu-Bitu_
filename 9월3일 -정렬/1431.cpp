#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int check(string a) { //문자열 내 숫자인 글자의 숫자합
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] <= '9' && a[i] >= '0') {
			sum += a[i] - '0';
		}
	}
	return sum;

}


bool cmp(const string a, string b) {

	if (a.size() != b.size()) {
		return a.size() < b.size();
	}


	int sum1 = 0;
	int sum2 = 0;

	sum1 = check(a);
	sum2 = check(b);
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
		cout << v[i] << '\n';
	}
}
