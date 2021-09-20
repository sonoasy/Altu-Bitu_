#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
using namespace  std;


int main() {

	//백준 2493번

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	stack<int> s;
	vector<int>v;
	stack<int> answer;
	stack<int> q;
	int m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		s.push(m);
		//v.push_back(m);
	}

	while (!s.empty()) {
		int e = s.top();
		s.pop();
		
		while (!s.empty()) {
			if (e < s.top()) {
				answer.push(s.size());
				break;
			}
			//없으면
			q.push(s.top());
			s.pop();

		}
		if (s.empty()) {
			answer.push(0);
		}
		//다음 체크를 위해 복귀
		while (!q.empty()) {
			s.push(q.top());
			q.pop();
		}

	}
	while (!answer.empty()) {
		cout << answer.top() << ' ';
		answer.pop();

	}

}
