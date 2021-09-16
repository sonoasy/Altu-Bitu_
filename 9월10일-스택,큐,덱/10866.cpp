#include <iostream>
#include <deque>
#include<string>
using namespace  std;



int main() {
  	
   //백준 10866번
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	deque<int> q;
	string s;
	int n;
	int m;
	cin >> n;
	while (n--) {

		cin >> s;
		if (s == "push_front") {
			cin >> m;
			q.push_front(m);

		}
		else if (s == "push_back") {
			cin >> m;
			q.push_back(m);
		}
		else if (s == "pop_front") {
			if (!q.empty()) {
				cout << q.front()<<'\n';
				q.pop_front();
			}
			else {
				cout << -1<<'\n';
			}


		}
		else if (s == "pop_back") {
			if (!q.empty()) {
				cout << q.back() << '\n';
				q.pop_back();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "size") {
			cout << q.size()<<'\n';

		}
		else if (s == "empty") {
			if (q.empty()) {
				cout << 1<<'\n';
			}
			else {
				cout << 0 << '\n';
			}

		}
		else if (s == "front") {

			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
			}


		}
		else if (s == "back") {

			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.back() << '\n';
			}


		}




	}










	
	
}
