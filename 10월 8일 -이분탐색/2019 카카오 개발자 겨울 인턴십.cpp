#include <iostream>
#include <vector>

using namespace std;

//cnt명이 건널 때, 건너 뛰어야 하는 디딤돌 칸 수의 최댓값
int jumpDist(vector<int>& stones, int cnt) {
    int dist = 1, prev = -1; //건너뛴 칸, 이전에 밟은 디딤돌
    for (int i = 0; i < stones.size(); i++) {//모든 돌에 대하여 
        if (stones[i] >= cnt) { //밟을 수 있음
            dist = max(dist, i - prev); // 이전- 가려는칸 사이 거리를 통해 건너뛰는 칸 최댓값 갱신
            prev = i; //이전에 밟은 디딤돌 인덱스 
        }
    }
    dist = max(dist, (int)stones.size() - prev); //개울의 오른쪽 건너편까지 이동
    return dist; //건너뛰어야 하는 최대 디딤돌 칸 리턴
}

int upperSearch(vector<int>& stones, int left, int right, int target) {
    int ans = 0; //건널수 있는 인원 저장 
    while (left <= right) {
        //mid만큼의 친구들이 건널 때, 건너 뛰어야 하는 디딤돌 칸 수의 최댓값은 몇칸인가?
        int mid = (left + right) / 2; //절반 위치
        int jump = jumpDist(stones, mid);  //건너뛸수 있는 칸 최댓값

        if (jump <= target) { //target(k)보다 같거나 작으면
            ans = mid; //mid명수는 건널수 있음
            left = mid + 1; //mid+1명부터 되는지 탐색
        }
        else if (jump > target)//target(k)보다 크면
            right = mid - 1; //mid명은 안됨, mid-1부터 다시 탐색
    }
    return ans; //건널수 있는 최대 인원 리턴
}

/**
 * 징검다리를 건널 수 있는 니니즈 친구들의 최댓값
 * -> 니니즈 친구들 n명이 징검다리를 건널 때, 건너 뛰어야 하는 디딤돌 칸 수의 최댓값이 k보다 작은가?
 *
 * left : 배열의 원소가 1이상이기 때문에 최소한 1명은 건널 수 있음
 * right : 아무리 많이 건너도 배열 원소의 최댓값보다 많은 인원이 건널 수는 없음
 */
int solution(vector<int> stones, int k) {
    int right = 0; //배열 원소의 최댓값
    for (int i = 0; i < stones.size(); i++)//징검다리 돌 위의 숫자들을 탐색해서
        right = max(right, stones[i]); //징검다리 각각 돌의 가장많이 디딜수 있는 숫자를 저장

    return upperSearch(stones, 1, right, k); //1부터 시작
}

int main() {
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }; //징검다리 돌 위의 숫자
    int k = 3; //최대 한번에 건너뛸수 있는 칸수
    cout << solution(stones, k);//최대 몇명까지 건널수 있는지 리턴 
}
