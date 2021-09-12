#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


vector<int>tmp;
vector<int>a;
int main() {
	//백준 18870번
	
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n,k;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >>k;
		tmp.push_back(k);
	}
	//set으로 저장해서 각자의 인덱스가 자신보다 작은 숫자 갯수임
	set<int> v(tmp.begin(), tmp.end());

	//set을 vector로 set에서 위치를 찾아서 set처음 위치를 빼는게 안됨
	vector<int> a(v.begin(), v.end());
	
	//입력받은 값에 대해서 set을 벡터로 바꾼 a내 인덱스 찾기
	for (int i = 0; i < tmp.size(); i++) {
		//find 시간초과뜸
		auto find= lower_bound(a.begin(), a.end(), tmp[i]);
		
		cout << find - a.begin() << ' ';
	}








}
