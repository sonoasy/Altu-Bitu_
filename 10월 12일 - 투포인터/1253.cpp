#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
vector<int>a;

int cnt = 0; //좋다 갯수

void find(int last) {

	for (int curr = 0; curr < last; curr++) { //인덱스 2부터 두수의 합으로 변환가능한게 아님!!같은 숫자 반복해서 나올수 있으므로
		int left = 0; //왼쪽은 0인덱스부터 탐색
		int right = last - 1; //같은 숫자 여러개 있을수 있으므로 last-1부터 다 탐색하기

		while (left < right) {
		
			int sum = a[left] + a[right]; //현재 left와 right 인덱스의 값의 합이 curr와 같은지 확인
		
			if (sum == a[curr]) { //합이 같으면
				if (left != curr && right != curr) {
					cnt++; //갯수 추가
					break;
				}
				else if (right == curr) {//합은 같은데 right가 지금 수와 같은 위치면-> 하나 아래로 가기
					right--;
				}
				else if (left == curr) {//합은 같은데 left가 지금 수와 같은 위치면 하나 위로가기, 오름차순 정렬이므로 다음수에 같은 숫자가 있을수도 있음
					left++;
				}
			}
			else if (sum > a[curr]) {//합이 더 크면 right의 인덱스를 하나 줄임
				right--;
			}
			else if (sum < a[curr]) {//합이 더 작으면 left의 인덱스를 하나 늘림
				left++;
			}


		}

	}
	


}



int main() {

	//백준 1253번
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//n개의 수 중에서 어떤 수가 다른 두개의 수의 합으로 나타낼수 있으면 good
	int n, m;
	cin >> n;
	
	for(int i=0;i<n;i++){       //while(n--)안됨
		cin >> m;
		a.push_back(m);
	}
	sort(a.begin(), a.end());//오름차순 정렬
	find(n);
	cout << cnt;




}
