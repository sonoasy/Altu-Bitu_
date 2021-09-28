#include <iostream>
#include <vector>

//std::생략
using namespace std;

const int MAX_CHANNEL = 1000000;

vector<bool> broken(11); //버튼별 고장여부

//리모컨의 버튼들로 이 채널을 누를 수 있는지 검사. 만약 누를 수 있다면 눌러야 하는 횟수 리턴
int canPress(int channel) {
    int cnt = 0; //버튼을 눌러야 하는 횟수
    if (channel == 0) //0번 채널일 때
        //고장났으면 움직일수 없어서 0, 아니면 0 하나만 누르면 되니까 1번 리턴
        return !broken[0];
    //0이 아니라면 
    while (channel != 0) { //누를 채널의 모든 자릿수에 대해
        if (broken[channel % 10]) //하나라도 부서졌다면 누를 수 없음
            return 0;//누르는 횟수 0, 바로 종료 
        //10씩 나눠서 각 자리 확인해보기
        channel /= 10;
        //각각 횟수 더하기
        cnt++;
    }
    //모든 자리수 다 누를수 있을때의 횟수 반환
    return cnt;
}

/**
 * 0번 채널부터 MAX_CHANNEL까지 모든 채널에 대해 이동 가능 여부를 체크
 * 1,000,000까지만 계산하면 되기 때문에 무식하게 풀어도 시간안에 풀 수 있음
 */
int main() {
    //n - 이동하고자 하는 채널, m - 고장난 번호의 갯수 button - 고장난 번호 저장하기 위해 사용할 변수
    int n, m, button;

    //n,m 입력
    cin >> n >> m;
    //m개의 고장난 버튼을 입력받는다
    for (int i = 0; i < m; i++) {
        //button에 번호를 저장하고
        cin >> button;
        //broken 벡터에 true로 고장 여부를 체크한다
        broken[button] = true;
    }

    //연산

    //현재 채널이 100번이므로 100번보다 작거나/같거나/큰 위치로 갈수 있으므로 절댓값
    int min_click = abs(n - 100); //+ 또는 - 버튼 계속 누르기


    if (m == 10) { //버튼이 전부 부서졌다면 숫자를 눌러 이동할 수 없음
        cout << min_click; //숫자버튼으로느 이동 불가해서 위치 차이만큼 + 혹은 - 눌러서 이동해야함
        //해당 경우 종료
        return 0;
    }
    //그 외에 모두 고장난게 아니었을때
    for (int i = 0; i < MAX_CHANNEL; i++) { //i번 채널에 대해
        int press_cnt = canPress(i); //i번 채널에 가기 위해 버튼을 눌러야 하는 횟수
        if (press_cnt != 0) //0이 아니라면 i번 채널로 이동할 수 있음
            min_click = min(min_click, abs(n - i) + press_cnt); //i번 채널 이동 후, i번에서 n번까지 + / - 버튼 누른 값과 최솟값 비교
    }

    //출력
    cout << min_click;
}
