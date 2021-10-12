#include <iostream>
#include <vector>

using namespace std;

vector<int> w; //에너지 값저장
int ans; //결과 

void backtracking(int sum) {
    if (w.size() == 2) { //에너지 구슬이 2개 -> 더 이상 고를 수 없음
        ans = max(ans, sum); //기존 갱신된 ans과 sum 중에 더 큰값을 ans로 설정 
        return; //종료
    }
    //0부터 저장되어있음 
    for (int i = 1; i < w.size() - 1; i++) { //처음과 마지막 선택 불가이므로
        int temp_w = w[i]; //선택한 인덱스의 에너지 값
        int sum_w = w[i - 1] * w[i + 1]; //선택한 인덱스 전,후로의 에너지값을 곱해서 더하기
        w.erase(w.begin() + i); //w에서 선택한 인덱스 지우기
        backtracking(sum + sum_w); //최종 합에 전,후로의 에너지값 곱한것 더해주기
        w.insert(w.begin() + i, temp_w); //다른 경우도 w사용하므로 다시 지운 인덱스의 값 저장해주기
    }
}

/**
 * 가능한 모든 경우를 구해서 계산하자
 * 이때, 사용한 에너지는 따로 저장해 둔 후에 배열에서 지우고, 다시 돌아왔을 때 저장한 값을 배열에 넣는다.
 */
int main() {

    //에너지 갯수
    int n;

    //입력
    cin >> n;
    //애너지 n개에 대하여 
    w.assign(n, 0);
    //각각 에너지의
    for (int i = 0; i < n; i++)
        cin >> w[i]; //크기를 저장한다.

    //연산
    backtracking(0);

    //결과 출력
    cout << ans << '\n';

    return 0;
}
