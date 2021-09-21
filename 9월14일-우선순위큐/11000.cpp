#include<iostream>
#include <algorithm>
#include<queue>


#define MAX 200001
using namespace std;


//시작-끝
pair<int, int> p[MAX];

int main() {

	// 백준 110000번 최소 강의실 

	//n개의 수업
	int n;
	priority_queue<int,vector<int>,greater<int>> pq;


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p,p+n);
  
	pq.push(p[0].second);

	for (int i = 1; i < n; i++) {
		if (pq.top() <= p[i].first) {
			pq.pop();
			pq.push(p[i].second);
		}
		else {
			 
			pq.push(p[i].second);
		}



	}


	cout << pq.size();


}
