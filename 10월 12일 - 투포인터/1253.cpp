#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
vector<int>a;

int cnt = 0; //좋다 갯수

void find(int curr,int last) {
	
	int left = 0; //왼쪽은 0인덱스부터 탐색
	int right = curr - 1; //오른쪽은 지금 좋다인지 확인하려는 숫자의 인덱스 -1

	if (curr > last)return;

	while (left < right) {
		int sum = a[left] + a[right]; //현재 left와 right 인덱스의 값의 합이 curr와 같은지 확인

		if (right == last || left == last)return;

		if (right==curr || left==curr) {//left나 right의 인덱스가 curr과 같아지면 
			find(curr + 1, last);//curr 다음 인덱스를 탐색
		}
		
		if (sum == a[curr]) { //같으면
			cnt++; //갯수 추가
			find(curr + 1, last); //다음 인덱스가 좋다인지 확인
		}
		else if (sum > a[curr]) {//합이 더 크면 right의 인덱스를 하나 줄임
			right--;
		}
		else if (sum < a[curr]) {//합이 더 작으면 left의 인덱스를 하나 늘림
			left++;
		}


	}


}



int main() {

	//백준 1253번
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//n개의 수 중에서 어떤 수가 다른 두개의 수의 합으로 나타낼수 있으면 good
	int n,m;
	cin >> n;
	
	while (n--) {
		cin >> m;
		a.push_back(m);
	}
	sort(a.begin(), a.end());//오름차순 정렬
	find(0,n-1);
	cout << cnt;



	
}
                         
