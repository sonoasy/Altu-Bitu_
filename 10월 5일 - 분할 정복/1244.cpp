#include <iostream>
#include <vector>

using namespace std;

//남학생의 스위치 바꾸기
vector<int> changeSwitchBoy(int n, int number, vector<int> switches) {
    for (int i = number; i <= n; i += number) //배수에 있는 스위치 바꾸기
        switches[i] = !switches[i]; //반대 상태로 바꾸기 

    return switches; //스위치 배열 리턴
}

//여학생의 스위치 바꾸기
vector<int> changeSwitchGirl(int n, int number, vector<int> switches) {
    switches[number] = !switches[number];  //우선 입력받은 곳 바꾸기 
    for (int i = 1; i < number; i++) { //모든 구간 탐색
        //좌우 대칭 탐색, 범위 내에 드는지 확인 
        if ((number + i > n) || (switches[number - i] != switches[number + i])) //스위치 범위 넘어가거나 좌우 대칭이 아니면
            break;
        //좌우 대칭이면서 범위 내에 있으면 
        switches[number - i] = !switches[number - i]; //반대로 바꾸기
        switches[number + i] = !switches[number + i]; //반대로 바꾸기
    }

    return switches; //스위치 배열 리턴
}

/**
 * 남학생 -> 해당 번호의 배수에 해당하는 스위치 상태 바꾸기
 * 여학생 -> 해당 번호를 중심으로 좌우 대칭이면서 가장 많은 스위치 포함하는 구간의 상태 모두 바꾸기
 *
 * 좌우 대칭 검사 시, 스위치 범위 주의 (주어진 스위치 범위 넘어가지 않도록)
 * 스위치 20개씩 출력하는 부분 주의
 */
int main() {

    int n, m; // n은 스위치 갯수, m은 학생수
    int student, number; //학생 성별, 숫자

    //입력
    cin >> n;
    //스위치 배열 
    vector<int> switches(n + 1, 0);
    for (int i = 1; i <= n; i++) //n개의 스위치에 대하여
        cin >> switches[i]; //각각의 상태를 저장 

    //입력 & 연산
    cin >> m;
    while (m--) { 
        cin >> student >> number; //성별, 숫자
        if (student == 1) //남학생
            switches = changeSwitchBoy(n, number, switches); //스위치 갯수, 숫자, 배열을 인자로 남학생이 바꾸는 경우로 실행
        else //여학생 
            switches = changeSwitchGirl(n, number, switches);//스위치 갯수, 숫자, 배열을 인자로 여학생이 바꾸는 경우로 실행
    }

    //출력
    for (int i = 1; i <= n; i++) { //n개의 스위치 
        cout << switches[i] << ' '; //상태를 출력 
        if (i % 20 == 0)  //한줄에 20개씩 출력이므로
            cout << '\n'; //20개 되면 띄어쓰기 
    }
    return 0;
}
